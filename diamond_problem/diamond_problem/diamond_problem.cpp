#include <iostream>

class Human
{
public:
    Human() { std::cout << "Grandparent ctor" << std::endl; }
    ~Human() { std::cout << "Grandparent dtor" << std::endl; }
};

class Mother : virtual public Human
{
public:
    Mother() { std::cout << "Mother ctor" << std::endl; }
    ~Mother() { std::cout << "Mother dtor" << std::endl; }
};

class Father : virtual public Human
{
public:
    Father() { std::cout << "Father ctor" << std::endl; }
    ~Father() { std::cout << "Father dtor" << std::endl; }
};

class Child : public Mother, public Father
{
public:
    Child() { std::cout << "Child ctor" << std::endl; }
    ~Child() { std::cout << "Child dtor" << std::endl; }
};

int main()
{
    Child* c = new Child();
    delete c;

    return 0;
}