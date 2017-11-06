// MyInt2.cpp

class MyInt2{
public:
    MyInt2(int v):val(v){};
    friend MyInt2 operator+(const MyInt2& fir, const MyInt2& sec){ 
        return MyInt2(fir.val + sec.val);
    }
private:
    int val;
};

int main(){

  MyInt2 myFive = MyInt2(2) + MyInt2(3);
  MyInt2 myFive2 = MyInt2(3) + MyInt2(2);
  
  MyInt2 myTen = myFive + 5;
  MyInt2 myTen2 = 5 + myFive;           
  
}
  
