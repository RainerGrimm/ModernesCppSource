// pimpl.cpp

#include <iostream>
#include <memory>
 
// interface (widget.h)
class widget {
    class impl;
    std::unique_ptr<impl> pImpl;
 public:
    void draw();
    bool shown() const { return true; } 
    widget(int);
    ~widget(); 
    widget(widget&&) = default;  
    widget(const widget&) = delete;
    widget& operator=(widget&&); 
    widget& operator=(const widget&) = delete;
};
 
// implementation (widget.cpp)
class widget::impl {
    int n; // private data
 public:
    void draw(const widget& w) {                             // (1)
        if(w.shown())
            std::cout << "drawing a widget " << n << '\n';
    }
    impl(int n) : n(n) {}
};
void widget::draw() { pImpl->draw(*this); }                  // (2)
widget::widget(int n) : pImpl{std::make_unique<impl>(n)} {}
widget::~widget() = default;                                 // (3)
widget& widget::operator=(widget&&) = default;
 
// user (main.cpp)
int main()
{
    std::cout << std::endl;
	
    widget w(7);
    w.draw();
	
    std::cout << std::endl;
   
}