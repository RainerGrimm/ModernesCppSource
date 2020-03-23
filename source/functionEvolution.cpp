// functionEvolution.cpp

int func1() {
    return 1972;
}

int func2(int arg) {
    return arg;
}

double func2(double arg) {
    return arg;
}

template <typename T>
int func3(T arg) {
    return arg;
}

struct FuncObject4 {
    int operator()() {
        return 1998;
    }
};

auto func5 = [] {
    return 2011;
};

auto func6 = [] (auto arg){
    return arg;
};

int main() {

    func1();        // 1972

    func2(1998);    // 1998
    func2(1998.0);  // 1998.0
    func3(1998);    // 1998
    func3(1998.0);  // 1998.0
    FuncObject4 func4;
    func4();        // 1998

    func5();        // 2011

    func6(2014);    // 2014
    func6(2014.0);  // 2014

}   
