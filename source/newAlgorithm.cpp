// newAlgorithm.cpp

#include <hpx/hpx_init.hpp>
#include <hpx/hpx.hpp>
#include <hpx/include/parallel_numeric.hpp>
#include <hpx/include/parallel_algorithm.hpp>
#include <hpx/include/iostreams.hpp>

#include <string>
#include <vector>


int hpx_main(){
  
  hpx::cout << hpx::endl;
  
  // for_each_n
  
  std::vector<int> intVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};                        // 1
  hpx::parallel::for_each_n(hpx::parallel::execution::par,                       // 2
                            intVec.begin(), 5, [](int& arg){ arg *= arg; });
  
  hpx::cout << "for_each_n: ";
  for (auto v: intVec) hpx::cout << v << " ";
  hpx::cout << "\n\n";
  
  // exclusive_scan and inclusive_scan
  std::vector<int> resVec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  hpx::parallel::exclusive_scan(hpx::parallel::execution::par,                   // 3
                               resVec.begin(), resVec.end(), resVec.begin(), 1,
                               [](int fir, int sec){ return fir * sec; });
  
  hpx::cout << "exclusive_scan: ";
  for (auto v: resVec) hpx::cout << v << " ";
  hpx::cout << hpx::endl; 
  
  std::vector<int> resVec2{1, 2, 3, 4, 5, 6, 7, 8, 9};
  
  hpx::parallel::inclusive_scan(hpx::parallel::execution::par,                                       // 5 
                      resVec2.begin(), resVec2.end(), resVec2.begin(),        
                      [](int fir, int sec){ return fir * sec; }, 1);
  
  hpx::cout << "inclusive_scan: ";
  for (auto v: resVec2) hpx::cout << v << " ";
  hpx::cout << "\n\n";
  
  // transform_exclusive_scan and transform_inclusive_scan
  std::vector<int> resVec3{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> resVec4(resVec3.size());             
  hpx::parallel::transform_exclusive_scan(hpx::parallel::execution::par,         // 6
                                          resVec3.begin(), resVec3.end(), 
                                          resVec4.begin(), 0,
                                          [](int fir, int sec){ return fir + sec; },
                                          [](int arg){ return arg *= arg; });
  
  hpx::cout << "transform_exclusive_scan: ";
  for (auto v: resVec4) hpx::cout << v << " ";
  hpx::cout << hpx::endl;
  
  std::vector<std::string> strVec{"Only","for","testing","purpose"};             // 7
  std::vector<int> resVec5(strVec.size());
  
  hpx::parallel::transform_inclusive_scan(hpx::parallel::execution::par,         // 8
                                          strVec.begin(), strVec.end(), 
                                          resVec5.begin(), 0,
                                          [](auto fir, auto sec){ return fir + sec; },
                                          [](auto s){ return s.length(); });
                                  
  hpx::cout << "transform_inclusive_scan: ";
  for (auto v: resVec5) hpx::cout << v << " ";
  hpx::cout << "\n\n";
  
  // reduce and transform_reduce
  std::vector<std::string> strVec2{"Only","for","testing","purpose"};
  
  std::string res = hpx::parallel::reduce(hpx::parallel::execution::par,         // 9
                    strVec2.begin() + 1, strVec2.end(), strVec2[0], 
                    [](auto fir, auto sec){ return fir + ":" + sec; });
  
  hpx::cout << "reduce: " << res << hpx::endl;
 
                                                                                 // 11
  std::size_t res7 = hpx::parallel::parallel::transform_reduce(hpx::parallel::execution::par,        
                     strVec2.begin(), strVec2.end(), 
                     [](std::string s){ return s.length(); }, 
                     0, [](std::size_t a, std::size_t b){ return a + b; });                                                                          
    
  hpx::cout << "transform_reduce: " << res7 << hpx::endl;
  
  hpx::cout << hpx::endl;

  return hpx::finalize();
}

int main(int argc, char* argv[]){
  
    // By default this should run on all available cores
    std::vector<std::string> const cfg = {"hpx.os_threads=all"};

    // Initialize and run HPX
    return hpx::init(argc, argv, cfg);
}


