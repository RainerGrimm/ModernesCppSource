// vectorArithmeticOperatorOverloading.cpp

#include <iostream>
#include <vector>

template<typename T>
class MyVector{
  std::vector<T> cont;   

public:
  // MyVector with initial size
  MyVector(const std::size_t n) : cont(n){}  

  // MyVector with initial size and value
  MyVector(const std::size_t n, const double initialValue) : cont(n, initialValue){}
  
  // size of underlying container
  std::size_t size() const{ 
    return cont.size(); 
  }

  // index operators
  T operator[](const std::size_t i) const{ 
    return cont[i]; 
  }

  T& operator[](const std::size_t i){ 
    return cont[i]; 
  }

};

// function template for the + operator
template<typename T> 
MyVector<T> operator+ (const MyVector<T>& a, const MyVector<T>& b){
  MyVector<T> result(a.size());
  for (std::size_t s= 0; s <= a.size(); ++s){
    result[s]= a[s]+b[s];
  }
  return result;
}

// function template for the * operator
template<typename T>
MyVector<T> operator* (const MyVector<T>& a, const MyVector<T>& b){
   MyVector<T> result(a.size());
  for (std::size_t s= 0; s <= a.size(); ++s){
    result[s]= a[s]*b[s]; 
  }
  return result;
}

// function template for << operator
template<typename T>
std::ostream& operator<<(std::ostream& os, const MyVector<T>& cont){  
  std::cout << std::endl;
  for (int i=0; i<cont.size(); ++i) {
    os << cont[i] << ' ';
  }
  os << std::endl;
  return os;
} 

int main(){

  MyVector<double> x(10,5.4);
  MyVector<double> y(10,10.3);

  MyVector<double> result(10);
  
  result= x+x + y*y;
  
  std::cout << result << std::endl;
  
}
