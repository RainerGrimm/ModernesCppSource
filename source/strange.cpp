// strange.cpp (https://github.com/RainerGrimm/ModernesCppSource)

#include <iostream>

struct Strange{ 
  
  Strange(): p(new int(2011)){}
    
  // deep copy 
  Strange(const Strange& a) : p(new int(*(a.p))){}    // (1)
  
  // shallow copy
  Strange& operator=(const Strange& a){               // (2)
    p = a.p;
    return *this;
  }  
   
  int* p;
    
};

int main(){
  
  std::cout << std::endl;
  
  std::cout << "Deep copy" << std::endl;
  
  Strange s1;
  Strange s2(s1);                                     // (3)
  
  std::cout << "s1.p: " << s1.p << "; *(s1.p): " << *(s1.p) << std::endl;
  std::cout << "s2.p: " << s2.p << "; *(s2.p): " << *(s2.p) << std::endl;
  
  std::cout <<  "*(s2.p) = 2017" << std::endl;
  *(s2.p) = 2017;                                     // (4)
  
  std::cout << "s1.p: " << s1.p << "; *(s1.p): " << *(s1.p) << std::endl;
  std::cout << "s2.p: " << s2.p << "; *(s2.p): " << *(s2.p) << std::endl;
  
  std::cout << std::endl;
  
  std::cout << "Shallow copy" << std::endl;

  Strange s3;
  s3 = s1;                                            // (5)
  
  std::cout << "s1.p: " << s1.p << "; *(s1.p): " << *(s1.p) << std::endl;
  std::cout << "s3.p: " << s3.p << "; *(s3.p): " << *(s3.p) << std::endl;
  
  
  std::cout <<  "*(s3.p) = 2017" << std::endl;
  *(s3.p) = 2017;                                     // (6)
  
  std::cout << "s1.p: " << s1.p << "; *(s1.p): " << *(s1.p) << std::endl;
  std::cout << "s3.p: " << s3.p << "; *(s3.p): " << *(s3.p) << std::endl;
  
  std::cout << std::endl;
  
  std::cout << "delete s1.p" << std::endl; 
  delete s1.p;                                        // (7)
  
  std::cout << "s2.p: " << s2.p << "; *(s2.p): " << *(s2.p) << std::endl;
  std::cout << "s3.p: " << s3.p << "; *(s3.p): " << *(s3.p) << std::endl;
  
  std::cout << std::endl;
  
}
