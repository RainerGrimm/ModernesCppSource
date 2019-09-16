// functionalCastCurlyBraces.cpp

void f(int x, long y, double d, long long l){
    char c1{x};   
    char c2{y};   
    char c3{d};   
    char c4{l};
}

int main(){  

  f(3, 3l, 3.0, 3ll);
}
