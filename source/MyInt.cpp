// MyInt.cpp

struct MyInt{
    MyInt(int v):val(v){};              // 1
    MyInt operator+(const MyInt& oth) const { 
        return MyInt(val + oth.val);
    }
    int val;
};

int main(){

  MyInt myFive = MyInt(2) + MyInt(3);
  MyInt myFive2 = MyInt(3) + MyInt(2);
  
  MyInt myTen = myFive + 5;            // 2
  MyInt myTen2 = 5 + myFive;           // ERROR
  
}
  
