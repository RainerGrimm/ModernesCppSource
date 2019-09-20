// constructorAssignment.cpp

struct NoDefault {
    NoDefault(int) {};
};

class Bad {
    const int constInt;
    int& refToInt;
    NoDefault noDefault;

public:
    Bad(int i, int& iRef)
    {
        constInt = i;
        refToInt = iRef;
    }
    // Bad(int i, int& iRef): constInt(i), refToInt(iRef), noDefault{i} {}
};

int main()
{

    int i = 10;
    int& j = i;

    Bad bad(i, j);
}
