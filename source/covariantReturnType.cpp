// covariantReturnType.cpp

#include <iostream>
#include <string>

class Window{ 
 public:                
    virtual Window* clone() { 
        return new Window(*this);
    }
    virtual std::string getName() const {
        return "Window";
    }                       
    virtual ~Window() {};
};

class DefaultWindow: public Window { 
     DefaultWindow* clone() override { 
        return new DefaultWindow(*this);
    } 
    std::string getName() const override {
        return "DefaultWindow";
    }   
};

class FancyWindow: public Window { 
    FancyWindow* clone() override { 
        return new FancyWindow(*this);
    } 
    std::string getName() const override {
        return "FancyWindow";
    }   
};
                
Window* cloneWindow(Window& oldWindow) {                    
    return oldWindow.clone();
}
  
int main() {

    std::cout << '\n';

    Window window;
    DefaultWindow defaultWindow;
    FancyWindow fancyWindow;

    const Window* window1 = cloneWindow(window);
    std::cout << "window1->getName(): " << window1->getName() << '\n';

    const Window* defaultWindow1 = cloneWindow(defaultWindow);
    std::cout << "defaultWindow1->getName(): " << defaultWindow1->getName() << '\n';

    const Window* fancyWindow1 = cloneWindow(fancyWindow);
    std::cout << "fancywindow1->getName(): " << fancyWindow1->getName() << '\n';
  
    delete window1;
    delete defaultWindow1;
    delete fancyWindow1;

    std::cout << '\n';
  
}