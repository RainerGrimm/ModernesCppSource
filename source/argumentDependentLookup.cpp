// argumentDependentLookup.cpp

#include <iostream>
#include <vector>

namespace Bad{
    
    struct Number{ 
        int m; 
    };
    
    template<typename T1, typename T2> // generic equality  (5)
    bool operator==(T1, T2){ 
        return false;  
    }
    
}

namespace Util{
    
    bool operator==(int, Bad::Number){   // equality to int (4)
        return true; 
    } 

    void compareSize(){
        Bad::Number badNumber{5};                            // (1)
        std::vector<int> vec{1, 2, 3, 4, 5};
        
        std::cout << std::boolalpha << std::endl;
        
        std::cout << "5 == badNumber: " <<                    
                     (5 == badNumber) << std::endl;          // (2)         
        std::cout << "vec.size() == badNumber: " << 
                     (vec.size() == badNumber) << std::endl; // (3)
        
        std::cout << std::endl;
    }
}

int main(){
   
   Util::compareSize();

}
