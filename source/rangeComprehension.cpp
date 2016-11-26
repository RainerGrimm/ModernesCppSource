// rangeComprehension.cpp

#include <range/v3/all.hpp>
#include <iostream>

using namespace ranges;

int main(){

  std::cout << std::endl;

  // odds= [ x*x | x <-[1..] , odd x  ]
  // takeWhile (<1000) odds --  -- [1,9,25, ... , 841,961]

  auto odds= view::ints(1) | view::for_each([](int i){return yield_if(i%2 == 1,i*i);});

  ranges::for_each(odds | view::take_while([](int i){ return i < 1000;}) , [](int i){
      std::cout << i << " ";
    });

  std::cout << "\n\n";

}
