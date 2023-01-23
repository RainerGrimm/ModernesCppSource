#include <iostream>

struct Strange { 
  
    Strange(): p(new int(2011)) {}
    
    // deep copy 
    Strange(const Strange& a) : p(new int(*a.p)) {}                 
  
    // shallow copy
    // equivalent to Strange& operator = (const Strange&) = default;
    Strange& operator = (const Strange& a) {                                 
        p = a.p;
        return *this;
    }  
   
    int* p;
    
};

int main() {
  
    std::cout << '\n';
  
    std::cout << "Deep copy" << '\n';
  
    Strange s1;
    Strange s2(s1);                                                                                 
  
    std::cout << "s1.p: " << s1.p << "; *s1.p: " << *s1.p << '\n';
    std::cout << "s2.p: " << s2.p << "; *s2.p: " << *s2.p << '\n';
  
    std::cout <<  "*s2.p = 2017" << '\n';
    *s2.p = 2017;                                                                               
  
    std::cout << "s1.p: " << s1.p << "; *s1.p: " << *s1.p << '\n';
    std::cout << "s2.p: " << s2.p << "; *s2.p: " << *s2.p << '\n';
  
    std::cout << '\n';
  
    std::cout << "Shallow copy" << '\n';

    Strange s3;
    s3 = s1;                                                                                           
  
    std::cout << "s1.p: " << s1.p << "; *s1.p: " << *s1.p << '\n';
    std::cout << "s3.p: " << s3.p << "; *s3.p: " << *s3.p << '\n';
  
  
    std::cout <<  "*s3.p = 2017" << '\n';
    *s3.p = 2017;                                                                                
  
    std::cout << "s1.p: " << s1.p << "; *s1.p: " << *s1.p << '\n';
    std::cout << "s3.p: " << s3.p << "; *s3.p: " << *s3.p << '\n';
  
    std::cout << '\n';
  
    std::cout << "delete s1.p" << '\n';                              
    delete s1.p;                                        
  
    std::cout << "s2.p: " << s2.p << "; *s2.p: " << *s2.p << '\n'; 
    std::cout << "s3.p: " << s3.p << "; *s3.p: " << *s3.p << '\n';
  
    std::cout << '\n';
  
}