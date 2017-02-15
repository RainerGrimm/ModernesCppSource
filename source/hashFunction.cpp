// hashFunction.cpp

#include <iostream>
#include <ostream>
#include <unordered_map>

struct MyInt{
  MyInt(int v):val(v){}
  bool operator== (const MyInt& other) const {
    return val == other.val;
  }
  int val;
};

struct MyHash{
  std::size_t operator()(MyInt m) const {
    std::hash<int> hashVal;
    return hashVal(m.val);
  }
};

struct MyAbsHash{
  std::size_t operator()(MyInt m) const {
    std::hash<int> hashVal;
    return hashVal(abs(m.val));
  }
};

struct MyEq{
  bool operator() (const MyInt& l, const MyInt& r) const {
    return abs(l.val) ==  abs(r.val);
  }
};

std::ostream& operator << (std::ostream& strm, const MyInt& myIn){
  strm << "MyInt(" << myIn.val << ")";
  return strm;
}

int main(){

  std::cout << std::endl;

  std::hash<int> hashVal;

  // a few hash values
  for ( int i= -2; i <= 1 ; ++i){
    std::cout << "hashVal(" << i << "): " << hashVal(i) << std::endl;
  }

  std::cout << std::endl;

  typedef std::unordered_map<MyInt,int,MyHash> MyIntMap;

  std::cout << "MyIntMap: ";
  MyIntMap myMap{{MyInt(-2),-2},{MyInt(-1),-1},{MyInt(0),0},{MyInt(1),1}};

  for(auto m : myMap) std::cout << '{' << m.first << ',' << m.second << '}';

  std::cout << std::endl << std::endl;

  typedef std::unordered_map<MyInt,int,MyAbsHash,MyEq> MyAbsMap;
  std::cout << "MyAbsMap: ";
  MyAbsMap myAbsMap{{MyInt(-2),-2},{MyInt(-1),-1},{MyInt(0),0},{MyInt(1),1}};

  for(auto m : myAbsMap) std::cout << '{' << m.first << ',' << m.second << '}';

  std::cout << std::endl << std::endl;

  std::cout << "myAbsMap[MyInt(-2)]: " << myAbsMap[MyInt(-2)] << std::endl;
  std::cout << "myAbsMap[MyInt(2)]: " << myAbsMap[MyInt(2)] << std::endl;
  std::cout << "myAbsMap[MyInt(3)]: " << myAbsMap[MyInt(3)] << std::endl;

  std::cout << std::endl;

}
