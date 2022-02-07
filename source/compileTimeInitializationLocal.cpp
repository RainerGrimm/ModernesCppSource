// compileTimeInitializationLocal.cpp

consteval auto doubleMe(auto val) {
  return 2 * val;
}

int main() {

auto res = doubleMe(1010);
++res;          // 2021

}