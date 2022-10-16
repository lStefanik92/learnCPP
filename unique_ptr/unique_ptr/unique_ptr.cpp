#include <iostream>
#include <memory>
#include <string>

class guineaPig {
    std::string s;
public:
    explicit guineaPig(std::string ss) : s(ss) { std::cout << "A new guinea pig named " << s << " in the Lab!" << '\n'; }
    ~guineaPig() { std::cout << "The Pig " << s << " died!" << '\n'; }
};

int main()
{
    auto upr1 = std::make_unique<guineaPig>("upr");   // exception safety
    // guineaPig* upr = new guineaPig;                // memory leak if not deleted
    // auto upr0(upr);                                // error bc copy operations = deleted;
    auto upr2 = std::move(upr1);                      // from now on upr is nullptr
    upr2.reset();                                     // object deleted before std::unique_ptr deletes it by itself, upr2 is left empty
                                                 
    return 0;
}