#include <iostream>

class Sort{
public:
 virtual void processData() final {
    readData();
    sortData();
    writeData();
  }
  virtual ~Sort() = default;
private:
    virtual void readData(){}
    virtual void sortData()= 0;
    virtual void writeData(){}
};


class QuickSort: public Sort{
    void readData() override {
        std::cout << "readData" << '\n';
    }
    void sortData() override {
        std::cout <<  "sortData" << '\n';
    }
    void writeData() override {
        std::cout << "writeData" << '\n';
    }
};

class BubbleSort: public Sort{
    void sortData() override {
        std::cout <<  "sortData" << '\n';
    }
};


int main(){

    std::cout << '\n';

    QuickSort quick;
    Sort* sort = &quick;
    sort->processData();

    std::cout << "\n\n";

    BubbleSort bubble;
    sort = &bubble;
    sort->processData();

    std::cout << '\n';
  
}