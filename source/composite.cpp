// composite.cpp

#include <iostream>
#include <vector>

class Graphic {
 public:
    virtual void print() const = 0;
    virtual ~Graphic() {} 
};

class GraphicComposite : public Graphic {
    std::vector<const Graphic*> children;
    const std::string& name;
 public:
    explicit GraphicComposite(const std::string& n): name(n){}
    void print() const override {
        std::cout << name << " ";
        for (auto c: children) c->print();
    }

    void add(const Graphic* component) {
        children.push_back(component);
    }

    void remove(const Graphic* component) {
        std::erase(children, component);
    }
};

class Ellipse: public Graphic {
 private:
    const std::string& name;
 public:
    explicit Ellipse(const std::string& n): name (n) {}
    void print() const override {
        std::cout << name << " ";
    }
};

int main(){

    std::cout << '\n';

    Ellipse ellipse1("ellipse1");
    Ellipse ellipse2("ellipse2");
    Ellipse ellipse3("ellipse3");
    Ellipse ellipse4("ellipse4");

    GraphicComposite graphic1("graphic1");
    GraphicComposite graphic2("graphic2");
    GraphicComposite graphic("graphic");

    graphic1.add(&ellipse1);
    graphic1.add(&ellipse2);
    graphic1.add(&ellipse3);

    graphic2.add(&ellipse4);

    graphic.add(&graphic1);
    graphic.add(&graphic2);

    graphic1.print();
    std::cout << '\n';

    graphic2.print();
    std::cout << '\n';

    graphic.print();

    std::cout << '\n';

    graphic.remove(&graphic1);

    graphic.print();

    std::cout << "\n\n";

}
