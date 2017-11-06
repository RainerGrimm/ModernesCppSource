// MyInt4.cpp

class MyInt4{
public:
    explicit MyInt4(int v):val(v){};           // 1
    friend MyInt4 operator+(const MyInt4& fir, const MyInt4& sec){ 
        return MyInt4(fir.val + sec.val);
    }
    friend MyInt4 operator+(const MyInt4& fir, int sec){
        return MyInt4(fir.val + sec);
    }
     friend MyInt4 operator+(int fir, const MyInt4& sec){
        return MyInt4(fir + sec.val);
    }
private:
    int val;
};

int main(){

  MyInt4 myFive = MyInt4(2) + MyInt4(3);
  MyInt4 myFive2 = MyInt4(3) + MyInt4(2);
  
  MyInt4 myTen = myFive + 5;                   // 2
  MyInt4 myTen2 = 5 + myFive;                  // 3
  
}
  
