// typeErasureDetection.cpp

#include <experimental/type_traits>                                 // (1)          

#include <iostream>
#include <memory>
#include <string>
#include <vector>

template<typename T>
using getName_t = decltype( std::declval<T&>().getName() );         // (2)

class Object {                                              
	 
public:
    template <typename T>                                   
    Object(const T& obj): object(std::make_shared<Model<T>>(std::move(obj))){   // (3)
      
        static_assert(std::experimental::is_detected<getName_t, decltype(obj)>::value, 
                                                     "No method getName available!");
        
    }
      
    std::string getName() const {                           
        return object->getName(); 
    }
	
   struct Concept {                                         
       virtual ~Concept() {}
	   virtual std::string getName() const = 0;
   };

   template< typename T >                                   
   struct Model : Concept {
       Model(const T& t) : object(t) {}
	   std::string getName() const override {
		   return object.getName();
	   }
     private:
       T object;
   };

   std::shared_ptr<const Concept> object;
};


void printName(std::vector<Object> vec){                    
    for (auto v: vec) std::cout << v.getName() << std::endl;
}

struct Bar{
    std::string get() const {                           
        return "Bar";
    }
};

struct Foo{
    std::string get_name() const {                           
        return "Foo";
    }
};

int main(){
	
    std::cout << std::endl;
	
    std::vector<Object> vec{Object(Foo()), Object(Bar())};  
	
    printName(vec);
	
    std::cout << std::endl;

}
