// sourceSIOF2.cpp

int quad(int n) {
    return n * n;
}

int& staticA() {
    
    static auto staticA  = quad(5);
    return staticA;
    
}


