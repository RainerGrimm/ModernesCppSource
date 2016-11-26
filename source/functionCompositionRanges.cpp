// functionCompositionRanges.cpp

#include <range/v3/all.hpp>
#include <numeric>
#include <iostream>

using namespace ranges;

int main(){

  std::cout << std::endl;

  // odds= takeWhile (< 1000) . filter odd . map (^2)
  // odds [1..]                 -- [1,9,25, ... , 841,961]

  auto odds= view::transform([](int i){ return i*i;} ) |
             view::remove_if([](int i){ return i % 2 == 0; } ) |
             view::take_while([](int i){ return i < 1000;} );
  auto oddNumbers= view::ints(1) | odds;

  ranges::for_each(oddNumbers,[](int i){ std::cout << i << " "; });

  std::cout << "\n\n";

  // total= sum $ take 100 $ map (\x -> x*x) [100..1000] -- 2318350

  auto total= ranges::accumulate(view::ints(100, 1000) |
                                 view::transform([](int x){ return x*x; }) |
                                 view::take(100), 0);

  std::cout << "total: " << total << std::endl;

  std::cout << std::endl;

}
