// userdefinedLiterals.cpp

#include <iostream>

namespace Distance{

  class MyDistance{
    public:
      MyDistance(double i):m(i){}

      friend MyDistance operator+(const MyDistance& a, const MyDistance& b){
        return MyDistance(a.m + b.m);
      }
      friend MyDistance operator-(const MyDistance& a,const MyDistance& b){
        return MyDistance(a.m - b.m);
      }
	  
	  friend MyDistance operator*(double m, const MyDistance& a){
	    return MyDistance(m*a.m);
	  }
	  
	  friend MyDistance operator/(const MyDistance& a, int n){
	    return MyDistance(a.m/n);
	  }
	  
      friend std::ostream& operator<< (std::ostream &out, const MyDistance& myDist){
        out << myDist.m << " m";
        return out;
      }
	private:
	  double m;	  
  };

  namespace Unit{
    MyDistance operator "" _km(long double d){
      return MyDistance(1000*d);
    }
    MyDistance operator "" _m(long double m){
      return MyDistance(m);
    }
    MyDistance operator "" _dm(long double d){
      return MyDistance(d/10);
    }
    MyDistance operator "" _cm(long double c){
      return MyDistance(c/100);
    }
  }
  
}
  
Distance::MyDistance getAverageDistance(std::initializer_list<Distance::MyDistance> inList){
  auto sum= Distance::MyDistance{0.0};
  for (auto i: inList) sum = sum + i ;
  return sum/inList.size(); 
}


using namespace Distance::Unit;

int main(){

  std:: cout << std::endl;
  
  auto work= 63.0_km;
  auto workPerDay= 2 * work;
  auto abbrevationToWork= 5400.0_m;
  auto workout= 2 * 1600.0_m;
  auto shopping= 2 * 1200.0_m;
  
  auto distPerWeek1= 4*workPerDay-3*abbrevationToWork+ workout+ shopping;
  auto distPerWeek2= 4*workPerDay-3*abbrevationToWork+ 2*workout;
  auto distPerWeek3= 4*workout + 2*shopping;
  auto distPerWeek4= 5*workout + shopping;
  
  auto averageDistance= getAverageDistance({distPerWeek1,distPerWeek2,distPerWeek3,distPerWeek4});
  std::cout << "averageDistance: " << averageDistance << std::endl;
  
  std::cout << std::endl;

}
