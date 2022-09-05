// factoryMethod.cpp

#include <iostream>

// Product
class Window{ 
 public: 
    virtual Window* create() = 0;                       
    virtual Window* clone() = 0;                       
    virtual ~Window() {};
};

// Concrete Products 
class DefaultWindow: public Window { 
    DefaultWindow* create() override { 
        std::cout << "Create DefaultWindow" << '\n';
        return new DefaultWindow();
    } 
     DefaultWindow* clone() override { 
        std::cout << "Clone DefaultWindow" << '\n';
        return new DefaultWindow(*this);
    } 
};

class FancyWindow: public Window { 
    FancyWindow* create() override { 
        std::cout << "Create FancyWindow" << '\n';
        return new FancyWindow();
    } 
    FancyWindow* clone() override { 
        std::cout << "Clone FancyWindow" << '\n';
        return new FancyWindow(*this);
    } 
};

// Concrete Creator or Client                             
Window* createWindow(Window& oldWindow) {               
    return oldWindow.create();
}

Window* cloneWindow(Window& oldWindow) {                    
    return oldWindow.clone();
}
  
int main() {

    std::cout << '\n';

    DefaultWindow defaultWindow;
    FancyWindow fancyWindow;
  
    const Window* defaultWindow1 = createWindow(defaultWindow);
    const Window* fancyWindow1 = createWindow(fancyWindow);
    
    const Window* defaultWindow2 = cloneWindow(defaultWindow);
    const Window* fancyWindow2 = cloneWindow(fancyWindow);
  
    delete defaultWindow1;
    delete fancyWindow1;
    delete defaultWindow2;
    delete fancyWindow2;

    std::cout << '\n';
  
}
