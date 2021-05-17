// maxExplicitTypeParameter.cpp

template <typename T>
T max(const T& lhs,const T& rhs) {
    return (lhs > rhs)? lhs : rhs;
}

int main() {
  
  auto res1 = max<float>(5.5, 6.0);
  auto res2 = max<bool>(5.5, 6.0);
  auto res3 = max(5.5, 6.0);
  
}