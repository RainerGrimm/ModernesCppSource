// templateTypeDeduction.cpp

template <typename T>
void funcValue(T param) { }

template <typename T>
void funcReference(T& param) { }

template <typename T>
void funcUniversalReference(T&& param) { }

class RVal{};

int main() {

    const int lVal{};
    const int& ref = lVal;
  
    funcValue(lVal);                  // (1)
    funcValue(ref);
  
    funcReference(lVal);              // (2)
  
    funcUniversalReference(lVal);     // (3)
    funcUniversalReference(RVal());

}