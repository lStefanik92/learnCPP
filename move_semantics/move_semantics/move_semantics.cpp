#include <iostream>
#include <utility>

struct A
{
    std::string s;

    A() : s("test") { std::cout << "def ctor" << std::endl; }

    A(const A& other) : s(other.s) { std::cout << "copy ctor" << std::endl; }

    A(A&& other) : s(move(other.s)) { std::cout << "move ctor" << std::endl; }

    A& operator= (const A& other) {
        s = other.s;
        std::cout << "copy assigned" << std::endl;
        return *this;
    }

    A& operator= (A&& other) {
        if (this != &other)
            s = std::exchange(other.s, 0);
        std::cout << "move assigned" << std::endl;
        return *this;
    }
};

A foo(A a) { return a; }

int main()
{
    A a1, a2;
    A ax(std::move(a1));
    A ay = std::move(a2);
    std::cout << ax.s << std::endl;
    std::cout << ay.s << std::endl;
    std::cout << a1.s << std::endl;
    std::cout << a2.s << std::endl;

    return 0;
}