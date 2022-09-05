// templateMethodClassic.cpp

#include <iostream>

enum class WindowType {                                 
    DefaultWindow,
    FancyWindow
};

// Product
class Window { 
 public: 
    virtual ~Window() {};
    virtual WindowType getType() const = 0;
    virtual std::string getName() const = 0;
};

// Concrete Products 
class DefaultWindow: public Window { 
 public:
    WindowType getType() const override {
        return WindowType::DefaultWindow;
    }
    std::string getName() const override { 
        return "DefaultWindow";
    }
};

class FancyWindow: public Window {
 public: 
     WindowType getType() const override {
        return WindowType::FancyWindow;
    }
    std::string getName() const override { 
        return "FancyWindow";
    }
};

// Concrete Creator or Client
Window* getNewWindow(Window* window) {                             
    switch(window->getType()){                                     
    case WindowType::DefaultWindow:
        return new DefaultWindow();
        break;
    case WindowType::FancyWindow:
        return new FancyWindow();
        break;
    }
    return nullptr;
}
  
int main() {

    std::cout << '\n';

    DefaultWindow defaultWindow;
    FancyWindow fancyWindow;

    const Window* defaultWindow1 = getNewWindow(&defaultWindow);   
    const Window* fancyWindow1 = getNewWindow(&fancyWindow);       

    std::cout << defaultWindow1->getName() << '\n';
    std::cout << fancyWindow1->getName() << '\n';
  
    delete defaultWindow1;
    delete fancyWindow1;

    std::cout << '\n';
  
}