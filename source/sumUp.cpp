// sumUp.cpp

#include <algorithm>
#include <iostream>
#include <vector>

class SumMe{
  int sum{0};
  public:
    SumMe() = default;

    void operator()(int x){
      sum += x;
    }

    int getSum(){
      return sum;
    }
};

int main(){

    std::vector<int> intVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    SumMe sumMe= std::for_each(intVec.begin(), intVec.end(), SumMe());

    std::cout << "\n";
    std::cout << "Sum of intVec= " << sumMe.getSum() << std::endl;
    std::cout << "\n";

}