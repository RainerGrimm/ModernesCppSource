struct NoDefault {
    NoDefault() = delete;
};

class Bad {
    const int constInt;
    int& refToInt;
    NoDefault noDefault;

public:
    Bad(int i_, int& intRef)
    {
        constInt = i_;
        retToInt = intRef;
    }
};

int main()
{

    Bad bad;
}
