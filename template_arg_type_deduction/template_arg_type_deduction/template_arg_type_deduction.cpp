
#include <iostream>

template<typename T>
void returnTypeVal(T param) {
    param++;
    std::cout << param << std::endl;
};

template<typename T>
void returnTypeRef(T& param) {
    param++;
    std::cout << param << std::endl;
};

template<typename T>
void returnTypePtr(T* param) {
    (*param)++;
    std::cout << *param << std::endl;
};

template<typename T>
void returnTypeURef(T&& param) {
    param++;
    std::cout << param << std::endl;
};

int main()
{
    int a = 1;
    int b = 10;
    int c = 100;
    int d = 1000;

    std::cout << "Original a = " << a << std::endl;
    returnTypeVal(a);
    std::cout << a << std::endl << std::endl;

    std::cout << "Original b = " << b << std::endl;
    returnTypeRef(b);
    std::cout << b << std::endl << std::endl;

    std::cout << "Original c = " << c << std::endl;
    returnTypePtr(&c);
    std::cout << c << std::endl << std::endl;

    std::cout << "Original d = " << d << std::endl;
    returnTypeURef(d);
    std::cout << d << std::endl << std::endl;

    returnTypeURef(1);

    //system("pause");
    return 0;
}
