// pureFunctions.cpp

#include <iostream>

int powFunc(int m, int n){ 
  if (n == 0) return 1; 
  return m * powFunc(m, n-1); 
}

template<int m, int n>
struct PowMeta{
  static int const value = m * PowMeta<m,n-1>::value;
};

template<int m>
struct PowMeta<m,0>{
  static int const value = 1;
};

constexpr int powConst(int m, int n){ 
  int r = 1;
  for(int k=1; k<=n; ++k) r*= m;
  return r;
}

int main(){
  std::cout << powFunc(2,10) << std::endl;               // 1024
  std::cout << PowMeta<2,10>::value << std::endl;        // 1024
  std::cout << powConst(2,10) << std::endl;              // 1024
}