// typeErasure.cpp

#include <iostream>
#include <memory>
#include <string>
#include <vector>

class Object {                                              // (2)
	 
public:
    template <typename T>                                   // (3)
    Object(const T& obj): object(std::make_shared<Model<T>>(std::move(obj))){}
      
    std::string getName() const {                           // (4)
        return object->getName(); 
    }
	
   struct Concept {                                         // (5)
       virtual ~Concept() {}
	   virtual std::string getName() const = 0;
   };

   template< typename T >                                   // (6)
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


void printName(std::vector<Object> vec){                    // (7)
    for (auto v: vec) std::cout << v.getName() << std::endl;
}

struct Bar{
    std::string getName() const {                           // (8)
        return "Bar";
    }
};

struct Foo{
    std::string getName() const {                           // (8)
        return "Foo";
    }
};

int main(){
	
    std::cout << std::endl;
	
    std::vector<Object> vec{Object(Foo()), Object(Bar())};  // (1)
	
    printName(vec);
	
    std::cout << std::endl;

}
