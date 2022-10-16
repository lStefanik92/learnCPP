#include <iostream>
class myClass {
public:
    explicit myClass (int)   // explicit specifier removes the implicit conversion using conv ctor             
    {
        std::cout << "int" << std::endl;
    };
    myClass (double)
    {
        std::cout << "double" << std::endl;
    };
};

int main()
{
    myClass ex(7);           // direct initialisation, int, 
    myClass imp = 7;         // copy initialisation, double, 
    return 0;
}