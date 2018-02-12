// suppressNarrowingConversion.cpp

void f(int x, long y, double d){
    char c1 = {x};   
    char c2 = {y};   
    char c3 = {d};   
}

int main(){

  double d = {7.9};
  int i = {d};    

  f(3, 3l, 3.0);
}
