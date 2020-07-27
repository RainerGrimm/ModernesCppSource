// nonTypeTemplateParameter.cpp

struct ClassType {
    constexpr ClassType(int) {}
};

template <ClassType cl>
auto getClassType() {
    return cl;
}

template <double d>
auto getDouble() {
    return d;
}

int main() {

    auto c1 = getClassType<ClassType(2020)>();

    auto d1 = getDouble<5.5>();
    auto d2 = getDouble<6.5>();

}
