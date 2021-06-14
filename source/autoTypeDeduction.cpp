// autoTypeDeduction.cpp

class RVal{};

int main() {

    const int lVal{};
    const int& ref = lVal;
  
    auto val1 = lVal;          // (1)
    auto val2 = ref;
  
    auto& val3 = lVal;         // (2)
  
    auto&& val4 = lVal;        // (3)
    auto&& val5 = RVal();

}