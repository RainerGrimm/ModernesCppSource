#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <array>
#include <algorithm>
#include <charconv>
#include <cstring>
#include <iostream>


// To achieve a design that improves local reasoning, we should
// design algorithm interfaces to not mutate their arguments if
// at all possible.
// Unfortunately, this is often at odds with the efficiency of
// the implementation of the algorithm.

// This comes up in many areas. A few examples include:
// - matrix algorithms, where implementations often require that
// arguments do not alias
// - state machines, where testing is far easier if we can produce a completely new state
// - range algorithms such as the below example
// - immutable maps and sets (see the immer library: https://github.com/arximboldi/immer)

// For clarity, let us consider a small example.
// Our data structure will be a vector of integers
// Our family of algorithms will be "sorted" and "uniqued"

// In c++20 (if we ignore ranges - we are trying to illustrate an approach),
// we would probably design the interface by taking by value and returning
// by value

// (helpers)
auto read_input(int argc, char** argv) -> std::vector<int>;
auto write_output(int) -> void;

namespace traditional {
template <typename T>
auto sorted(std::vector<T> x) -> std::vector<T> {
    std::sort(x.begin(), x.end());
    return x;
}

template <typename T>
auto uniqued(std::vector<T> x) -> std::vector<T> {
    x.erase(std::unique(x.begin(), x.end()), x.end());
    return x;
}

// This pattern leads to the following usage pattern
auto usage(int argc, char** argv) {
    for (auto i : uniqued(sorted(read_input(argc, argv)))) {
        write_output(i);
    };
}

// This is good, but sooner or later someone will want to refactor this
// code like this
auto refactor(int argc, char** argv) {
    auto input = read_input(argc, argv);
    for (auto i : uniqued(sorted(input))) {
        write_output(i);
    };
}

// can you spot the bug? Non-professionals often don't!
// If you work with researchers and scientists, this kind of mistake
// is ubiquitous, and leads to serious, serious slow-downs that are often
// difficult to find if not spotted immediately.

// What can we do? We should ask the compiler to issue an error, of course.
// We can do this by explicitly asking for an rvalue reference instead of taking by value.
}

namespace require_moves {
template <typename T>
auto sorted(std::vector<T>&& x) -> std::vector<T> {
    //                    ^^ new
    std::sort(x.begin(), x.end());
    return x;
}

template <typename T>
auto uniqued(std::vector<T>&& x) -> std::vector<T> {
    //                     ^^ new
    x.erase(std::unique(x.begin(), x.end()), x.end());
    return x;
}
auto read_input(int argc, char** argv) -> std::vector<int>;
auto write_output(int) -> void;

auto usage(int argc, char** argv) {
    // compiles unchanged, and has the same performance
    for (auto i : uniqued(sorted(read_input(argc, argv)))) {
        write_output(i);
    };
}

auto refactor(int argc, char** argv) {
    auto input = read_input(argc, argv);
    for (auto i : uniqued(sorted(std::move(input)))) {
        //                       ^^^^^^^^^^     ^ required, does not compile without it!
        write_output(i);
    };
}

auto print_diff(std::vector<int> const&, std::vector<int> const&) -> void;

// of course, now we have a problem. What if we actually needed the copy?
#if defined(TRY_1)
auto check_is_sorted_and_uniqued(int argc, char** argv) {
    auto input = read_input(argc, argv);
    auto sorted_and_uniqued = uniqued(sorted(input));
    //                                ^^^^^^ no matching function for call to sorted
    if (input != sorted_and_uniqued) {
        print_diff(input, sorted_and_uniqued);
        exit(1);
    }
    exit(0);
}
#elif defined(TRY_2)
// we can work around this by making a copy explicitly
auto check_is_sorted_and_uniqued(int argc, char** argv) {
    auto input = read_input(argc, argv);
    auto input_copy = input; // <- sad face; requires its own statement, ugly
    auto sorted_and_uniqued = uniqued(sorted(std::move(input_copy)));
    if (input != sorted_and_uniqued) {
        print_diff(input, sorted_and_uniqued);
        exit(1);
    }
    exit(0);
}
// Don't you think this is bad user experience, though?
// Of course it is. We just wanted to make copies explicit, not near-impossible.
// The standard library specification has had a name for this for a long time:
// they call it DECAY_COPY, which is literally what happens, but is inscruitable
// jargon.
#elif defined(TRY_3)
// Some smart users have tried and defined their own accompanying function to std::move for this:
auto decay_copyish(auto&& x) { return std::forward<decltype(x)>(x); }

// If we have that, we could write our check_is_sorted_and_uniqued without the named copy:
auto check_is_sorted_and_uniqued(int argc, char** argv) {
    auto input = read_input(argc, argv);
    auto sorted_and_uniqued = uniqued(sorted(decay_copy(input)));
    //                                       ^^^^^^^^^^ "explicit" copy
    if (input != sorted_and_uniqued) {
        print_diff(input, sorted_and_uniqued);
        exit(1);
    }
    exit(0);
}

// This works, and in this case is optimal, but leaves something to be desired in generic cases.
// Let us try and see what happens if we try and refactor sort+unique into a generic
// algorithm

#endif
// Let's take our vector as a forwarding reference so we can reuse its memory if we own it
// We need a concept for that
template <typename T>
inline constexpr bool is_vector_v = false;
template <typename T, typename A>
inline constexpr bool is_vector_v<std::vector<T, A>> = true;
template <typename T>
concept a_vector = is_vector_v<std::remove_cvref_t<T>>;

// we take this by forwarding reference; but now,
// we make an additional move-construction if v is passed by rvalue reference
auto sorted_and_uniqued(a_vector auto&& v) {
    return uniqued(sorted(decay_copy(std::forward<decltype(v)>(v))));
    //                    ^^^^^^^^^^ an extra move construction or the needed copy-construction
    // specifically, we move-construct decay_copy's return value.
}

// so, decay_copy is clearly not optimal. We need something that won't result
// in additional move-constructions and still accomplish our "copies are explicit" goal.

// enter: decay-copy in the language!
}

namespace done_properly {
using require_moves::sorted, require_moves::uniqued, require_moves::a_vector, require_moves::print_diff;

// in regular user code, we can now use auto{} instead of decay-copy:
auto check_is_sorted_and_uniqued(int argc, char** argv) {
    auto input = read_input(argc, argv);
    auto sorted_and_uniqued = uniqued(sorted(auto(input)));
    //                                       ^^^^^^^^^^^ explicit copy
    if (input != sorted_and_uniqued) {
        print_diff(input, sorted_and_uniqued);
        exit(1);
    }
    exit(0);
}

// in generic contexts
auto sorted_and_uniqued(a_vector auto&& v) {
    return uniqued(sorted(auto(std::forward<decltype(v)>(v))));
    //                    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    // correct forwarded copy of an argument we took by forwarding reference
}
}

// Thanks for reading!
