// lazyEvaluation.cpp

#include <range/v3/all.hpp>
#include <iostream>
#include <tuple>

using namespace ranges;

int main(){

  std::cout << std::endl;

  // take 5 [1..]  -- [1,2,3,4,5]

  auto num = view::take(view::ints(1), 5);
  ranges::for_each(num, [](int i){ std::cout << i << " "; });

  std::cout << "\n\n";

  auto pairs= view::zip_with([](int i, char c){ return std::make_pair(i, c);}, view::ints(0), "ranges");

  ranges::for_each(pairs, [](std::pair<int,char> p){ std::cout << "(" <<  p.first << ":" << p.second << ")"; });

  std::cout << "\n\n";

}
