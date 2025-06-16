// SIMD.cpp

const int SIZE= 8;

int vec[]={1,2,3,4,5,6,7,8};
int res[SIZE]={0,};

int main(){
  for (int i= 0; i < SIZE; ++i) {
    res[i]= vec[i]+5; // (1)
  }
}