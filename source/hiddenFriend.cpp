// hiddenFriend.cpp

#include <iostream>

class MyDistance{
 public:
    explicit MyDistance(double i):m(i){}

    friend MyDistance operator +(const MyDistance& a, const MyDistance& b){
        return MyDistance(a.m + b.m);
    }
    
    friend MyDistance operator -(const MyDistance& a, const MyDistance& b){
        return MyDistance(a.m - b.m);
    }

    friend std::ostream& operator<< (std::ostream &out, const MyDistance& myDist){
        out << myDist.m << " m";
        return out;
    }
    
 private:
    double m;

};


int main() {

    std::cout << '\n';

    std::cout << "MyDistance(5.5) + MyDistance(5.5): " << MyDistance(5.5) + MyDistance(5.5) << '\n';

     std::cout << "MyDistance(5.5) - MyDistance(5.5): " << MyDistance(5.5) - MyDistance(5.5) << '\n';

    std::cout << '\n';

}