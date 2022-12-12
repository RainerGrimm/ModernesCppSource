// templatesPolicy.cpp

#include <iostream>
#include <unordered_map>

struct MyInt{
    explicit MyInt(int v):val(v){}
    int val;
};

struct MyHash{                                                        // (1)
    std::size_t operator()(MyInt m) const {
        std::hash<int> hashVal;
        return hashVal(m.val);
    }
};

struct MyEqual{
    bool operator () (const MyInt& fir, const MyInt& sec) const {      // (2)
        return fir.val == sec.val;
    }
};

std::ostream& operator << (std::ostream& strm, const MyInt& myIn){     // (3)
    strm << "MyInt(" << myIn.val << ")";
    return strm;
}

int main(){

    std::cout << '\n';

    using MyIntMap = std::unordered_map<MyInt, int, MyHash, MyEqual>;  // (4)

    std::cout << "MyIntMap: ";
    MyIntMap myMap{{MyInt(-2), -2}, {MyInt(-1), -1}, {MyInt(0), 0}, {MyInt(1), 1}};

    for(auto m : myMap) std::cout << '{' << m.first << ", " << m.second << "}";

    std::cout << "\n\n";

}