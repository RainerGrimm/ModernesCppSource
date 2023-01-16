// adl.cpp

namespace MyNamespace {
    struct MyStruct {};
    void function(MyStruct) {}
}   

int main() {

    MyNamespace::MyStruct obj;  
    function(obj); 

}