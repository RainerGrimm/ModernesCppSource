// featureTesting.cpp
// from cppreference.com

#if __cplusplus < 201100
#  error "C++11 or better is required"
#endif
 
#include <algorithm>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>
 
#ifdef __has_include
# if __has_include(<version>)
#   include <version>
# endif
#endif
 
#define COMPILER_FEATURE_VALUE(value) #value
#define COMPILER_FEATURE_ENTRY(name) { #name, COMPILER_FEATURE_VALUE(name) },
 
#ifdef __has_cpp_attribute
# define COMPILER_ATTRIBUTE_VALUE_AS_STRING(s) #s
# define COMPILER_ATTRIBUTE_AS_NUMBER(x) COMPILER_ATTRIBUTE_VALUE_AS_STRING(x)
# define COMPILER_ATTRIBUTE_ENTRY(attr) \
  { #attr, COMPILER_ATTRIBUTE_AS_NUMBER(__has_cpp_attribute(attr)) },
#else
# define COMPILER_ATTRIBUTE_ENTRY(attr) { #attr, "_" },
#endif
 
// Change these options to print out only necessary info.
static struct PrintOptions {
    constexpr static bool titles               = 1;
    constexpr static bool attributes           = 1;
    constexpr static bool general_features     = 1;
    constexpr static bool core_features        = 1;
    constexpr static bool lib_features         = 1;
    constexpr static bool supported_features   = 1;
    constexpr static bool unsupported_features = 1;
    constexpr static bool sorted_by_value      = 0;
    constexpr static bool cxx11                = 1;
    constexpr static bool cxx14                = 1;
    constexpr static bool cxx17                = 1;
    constexpr static bool cxx20                = 1;
    constexpr static bool cxx23                = 0;
}   print;
 
struct CompilerFeature {
    CompilerFeature(const char* name = nullptr, const char* value = nullptr)
        : name(name), value(value) {}
    const char* name; const char* value;
};
 
static CompilerFeature cxx20[] = {
COMPILER_FEATURE_ENTRY(__cpp_aggregate_paren_init)
COMPILER_FEATURE_ENTRY(__cpp_char8_t)
COMPILER_FEATURE_ENTRY(__cpp_concepts)
COMPILER_FEATURE_ENTRY(__cpp_conditional_explicit)
COMPILER_FEATURE_ENTRY(__cpp_consteval)
COMPILER_FEATURE_ENTRY(__cpp_constexpr)
COMPILER_FEATURE_ENTRY(__cpp_constexpr_dynamic_alloc)
COMPILER_FEATURE_ENTRY(__cpp_constexpr_in_decltype)
COMPILER_FEATURE_ENTRY(__cpp_constinit)
COMPILER_FEATURE_ENTRY(__cpp_deduction_guides)
COMPILER_FEATURE_ENTRY(__cpp_designated_initializers)
COMPILER_FEATURE_ENTRY(__cpp_generic_lambdas)
COMPILER_FEATURE_ENTRY(__cpp_impl_coroutine)
COMPILER_FEATURE_ENTRY(__cpp_impl_destroying_delete)
COMPILER_FEATURE_ENTRY(__cpp_impl_three_way_comparison)
COMPILER_FEATURE_ENTRY(__cpp_init_captures)
COMPILER_FEATURE_ENTRY(__cpp_modules)
COMPILER_FEATURE_ENTRY(__cpp_nontype_template_args)
COMPILER_FEATURE_ENTRY(__cpp_using_enum)
};


constexpr bool is_feature_supported(const CompilerFeature& x) {
    return x.value[0] != '_' && x.value[0] != '0' ;
}
 
inline void print_compiler_feature(const CompilerFeature& x) {
    constexpr static int max_name_length = 44; //< Update if necessary
    std::string value{ is_feature_supported(x) ? x.value : "------" };
    if (value.back() == 'L') value.pop_back(); //~ 201603L -> 201603
    // value.insert(4, 1, '-'); //~ 201603 -> 2016-03
    if ( (print.supported_features && is_feature_supported(x))
        || (print.unsupported_features && !is_feature_supported(x))) {
            std::cout << std::left << std::setw(max_name_length)
                      << x.name << " " << value << '\n';
    }
}
 
template<size_t N>
inline void show(char const* title, CompilerFeature (&features)[N]) {
    if (print.titles) {
        std::cout << '\n' << std::left << title << '\n';
    }
    if (print.sorted_by_value) {
        std::sort(std::begin(features), std::end(features),
            [](CompilerFeature const& lhs, CompilerFeature const& rhs) {
                return std::strcmp(lhs.value, rhs.value) < 0;
            });
    }
    for (const CompilerFeature& x : features) {
        print_compiler_feature(x);
    }
}
 
int main() {
    
    if (print.cxx20 && print.core_features) show("C++20 CORE", cxx20);
   
}