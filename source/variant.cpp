// variant.cpp

#include <variant>
#include <string>
 
int main(){

  std::variant<int, float> v, w;
  v = 12;                              // v contains int
  int i = std::get<int>(v);
  w = std::get<int>(v);
  w = std::get<0>(v);                  // same effect as the previous line
  w = v;                               // same effect as the previous line
 
  //  std::get<double>(v);             // error: no double in [int, float]
  //  std::get<3>(v);                  // error: valid index values are 0 and 1
 
  try{
    std::get<float>(w);                // w contains int, not float: will throw
  }
  catch (std::bad_variant_access&) {}
 
  std::variant<std::string> v("abc");  // converting constructors work when unambiguous
  v = "def";                           // converting assignment also works when unambiguous

}

