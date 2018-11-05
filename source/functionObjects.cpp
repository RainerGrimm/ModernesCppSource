// functionObjects.cpp

#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

bool lessLength(const std::string& f, const std::string& s){      // (6) 
    return f.length() < s.length();
}

class GreaterLength{                                              // (7)
    public:
        bool operator()(const std::string& f, const std::string& s) const{
            return f.length() > s.length();
    }
};

int main(){

    std::vector<std::string> myStrVec = {"523345", "4336893456", "7234", 
	                                     "564", "199", "433", "2435345"};

    std::cout << "\n";                                      
    std::cout << "ascending with function object" << std::endl;  
    std::sort(myStrVec.begin(), myStrVec.end(), std::less<std::string>()); // (1)
    for (const auto& str: myStrVec) std::cout << str << " ";  
    std::cout << "\n\n";
  
    std::cout << "descending with function object" << std::endl;             
    std::sort(myStrVec.begin(), myStrVec.end(), std::greater<>());         // (2)
    for (const auto& str: myStrVec) std::cout << str << " ";  
    std::cout << "\n\n";

    std::cout << "ascending by length with function" << std::endl;
    std::sort(myStrVec.begin(), myStrVec.end(), lessLength);               // (3)
    for (const auto& str: myStrVec) std::cout << str << " ";  
    std::cout << "\n\n";

    std::cout << "descending by length with function object" << std::endl;
    std::sort(myStrVec.begin(), myStrVec.end(), GreaterLength());          // (4)
    for (const auto& str: myStrVec) std::cout << str << " ";  
    std::cout << "\n\n";

    std::cout << "ascending by length with lambda function" << std::endl;
    std::sort(myStrVec.begin(), myStrVec.end(),                           // (5)
              [](const std::string& f, const std::string& s){ 
		          return f.length() < s.length(); 
			  });
    for (const auto& str: myStrVec) std::cout << str << " ";  
    std::cout << "\n\n";

}
