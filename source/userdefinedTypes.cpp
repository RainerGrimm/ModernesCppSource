// userdefinedTypes.cpp

#include <iostream>
#include <ostream>

class MyInt{
public:
  constexpr MyInt()= default;
  constexpr MyInt(int fir, int sec): myVal1(fir), myVal2(sec){}
  MyInt(int i){
	myVal1= i-2;
	myVal2= i+3;
  }
  
  constexpr MyInt(const MyInt& oth)= default;
  constexpr MyInt(MyInt&& oth)= delete;
  
  constexpr int getSum(){ return myVal1+myVal2; }
  
  friend std::ostream& operator<< (std::ostream &out, const MyInt& myInt){
    out << "(" << myInt.myVal1 << "," << myInt.myVal2 << ")";  
    return out;
  }

private:
  int myVal1= 1998;
  int myVal2= 2003;

};

int main(){
  
  std::cout << std::endl;
  
  constexpr MyInt myIntConst1;
  MyInt myInt2;
  
  constexpr int sec= 2014;
  constexpr MyInt myIntConst3(2011,sec);
  std::cout << "myIntConst3.getSum(): " << myIntConst3.getSum() << std::endl;
  
  std::cout << std::endl;
  
  int a= 1998;
  int b= 2003;
  MyInt myInt4(a,b);
  std::cout << "myInt4.getSum(): " << myInt4.getSum() << std::endl;
  std::cout << myInt4 << std::endl;
  
  std::cout << std::endl;
  
  // constexpr MyInt myIntConst5(2000);  ERROR
  MyInt myInt6(2000);
  std::cout << "myInt6.getSum(): " << myInt4.getSum() << std::endl;
  std::cout << myInt6 << std::endl;
  
  // constexpr MyInt myInt7(myInt4); ERROR
  constexpr MyInt myInt8(myIntConst3);
  
  std::cout << std::endl;
  
  int arr[myIntConst3.getSum()];
  static_assert( myInt6.getSum() == 4025, "2011 + 2014 should be 4025" );
  
}