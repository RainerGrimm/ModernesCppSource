// covariantReturnTypeUniquePtr.cpp

#include <iostream>
#include <memory>
#include <string>

class Window{ 
 public:                
    virtual std::unique_ptr<Window> clone() { 
        return std::make_unique<Window>(*this);
    }
    virtual std::string getName() const {
        return "Window";
    }                       
    virtual ~Window() {};
};

class DefaultWindow: public Window { 
     std::unique_ptr<Window> clone() override { 
        return std::make_unique<DefaultWindow>(*this);
    } 
    std::string getName() const override {
        return "DefaultWindow";
    }   
};

class FancyWindow: public Window { 
    std::unique_ptr<Window> clone() override { 
        return std::make_unique<FancyWindow>(*this);
    } 
    std::string getName() const override {
        return "FancyWindow";
    }   
};
                
auto cloneWindow(std::unique_ptr<Window>& oldWindow) {                    
    return oldWindow->clone();
}
  
int main() {

    std::cout << '\n';

    std::unique_ptr<Window> window = std::make_unique<Window>();
    std::unique_ptr<Window> defaultWindow = std::make_unique<DefaultWindow>();
    std::unique_ptr<Window> fancyWindow = std::make_unique<FancyWindow>();

    const auto window1 = cloneWindow(window);
    std::cout << "window1->getName(): " << window1->getName() << '\n';

    const auto defaultWindow1 = cloneWindow(defaultWindow);
    std::cout << "defaultWindow1->getName(): " << defaultWindow1->getName() << '\n';

    const auto fancyWindow1 = cloneWindow(fancyWindow);
    std::cout << "fancyWindow1->getName(): " << fancyWindow1->getName() << '\n';

    std::cout << '\n';
  
}