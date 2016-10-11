// uniformInitialization.cpp

#include <map>
#include <vector>
#include <string>

// Initialization of a C-Array as attribute of a class
class Array{
  public:
    Array(): myData{1,2,3,4,5}{}    
  private:
    int myData[5];
};

class MyClass{			
  public: 
    int x;
    double y;
};

class MyClass2{		
  public:
    MyClass2(int fir, double sec):x{fir},y{sec} {};
  private: 
    int x;
    double y;
};

int main(){

  // Direct Initialization of a standard container
  int intArray[]= {1,2,3,4,5};   
  std::vector<int> intArray1{1,2,3,4,5};  
  std::map<std::string,int> myMap{{"Scott",1976}, {"Dijkstra",1972}};

  // Initialization of a const heap array
  const float* pData= new const float[3]{1.1,2.2,3.3};

  Array arr;

  // Defaut Initialization of a arbitrary object   
  int i{};                // i becomes 0
  std::string s{};        // s becomes ""
  std::vector<float> v{}; // v becomes an empty vector
  double d{};             // d becomes 0.0
	
  // Initializations of an arbitrary object using public attributes	
  MyClass myClass{2011,3.14};      
  MyClass myClass1= {2011,3.14};    

  // Initializations of an arbitrary object using the constructor
  MyClass2 myClass2{2011,3.14};     
  MyClass2 myClass3= {2011,3.14};   

}