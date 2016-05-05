// userdefinedLiteralsConstexpr.cpp

#include <iostream>

namespace Distance{

  class MyDistance{
    public:
      constexpr MyDistance(double i):m(i){}

      friend constexpr MyDistance operator+(const MyDistance& a, const MyDistance& b){
        return MyDistance(a.m + b.m);
      }
      friend constexpr MyDistance operator-(const MyDistance& a,const MyDistance& b){
        return MyDistance(a.m - b.m);
      }
	  
	  friend constexpr MyDistance operator*(double m, const MyDistance& a){
	    return MyDistance(m*a.m);
	  }
	  
	  friend constexpr MyDistance operator/(const MyDistance& a, int n){
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
    constexpr MyDistance operator "" _km(long double d){
      return MyDistance(1000*d);
    }
    constexpr MyDistance operator "" _m(long double m){
      return MyDistance(m);
    }
    constexpr MyDistance operator "" _dm(long double d){
      return MyDistance(d/10);
    }
    constexpr MyDistance operator "" _cm(long double c){
      return MyDistance(c/100);
    }
  }
  
}
  
constexpr Distance::MyDistance getAverageDistance(std::initializer_list<Distance::MyDistance> inList){
  auto sum= Distance::MyDistance{0.0};
  for (auto i: inList) sum = sum + i ;
  return sum/inList.size(); 
}


using namespace Distance::Unit;

int main(){

  std:: cout << std::endl;
  
  constexpr auto work= 63.0_km;
  constexpr auto workPerDay= 2 * work;
  constexpr auto abbrevationToWork= 5400.0_m;
  constexpr auto workout= 2 * 1600.0_m;
  constexpr auto shopping= 2 * 1200.0_m;
  
  constexpr auto distPerWeek1= 4*workPerDay-3*abbrevationToWork+ workout+ shopping;
  constexpr auto distPerWeek2= 4*workPerDay-3*abbrevationToWork+ 2*workout;
  constexpr auto distPerWeek3= 4*workout + 2*shopping;
  constexpr auto distPerWeek4= 5*workout + shopping;
  
  constexpr auto averageDistance= getAverageDistance({distPerWeek1,distPerWeek2,distPerWeek3,distPerWeek4});
  
  std::cout << "averageDistance: " << averageDistance << std::endl;
  
  std::cout << std::endl;

}
