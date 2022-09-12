// factoryMethodWindowIssues.cpp

#include <iostream>

// Product
class Window{ 
 public:                
    virtual Window* clone() { 
        std::cout << "Clone Window" << '\n';
        return new Window(*this);
    }                       
    virtual ~Window() {};
};

// Concrete Products 
class DefaultWindow: public Window { 
     DefaultWindow* clone() override { 
        std::cout << "Clone DefaultWindow" << '\n';
        return new DefaultWindow(*this);
    } 
};

class FancyWindow: public Window { 
    FancyWindow* clone() override { 
        std::cout << "Clone FancyWindow" << '\n';
        return new FancyWindow(*this);
    } 
};

// Concrete Creator or Client                             
Window* cloneWindow(Window& oldWindow) {                    
    return oldWindow.clone();
}
  
int main() {

    std::cout << '\n';

    Window window;
    DefaultWindow defaultWindow;
    FancyWindow fancyWindow;

    const Window* window1 = cloneWindow(window);
    const Window* defaultWindow1 = cloneWindow(defaultWindow);
    const Window* fancyWindow1 = cloneWindow(fancyWindow);
  
    delete window1;
    delete defaultWindow1;
    delete fancyWindow1;

    std::cout << '\n';
  
}