// differentReturnTypes.cpp

template <typename T>
auto getValue(T x)
{
    if (x < 0) // int
        return -1;
    else if (x > 0)
        return 1.0; // double
    else
        return 0.0f; // float
}

int main()
{

    getValue(5.5);
}
