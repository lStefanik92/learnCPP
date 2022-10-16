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
    {
        auto shptr1 = std::make_shared<guineaPig>("sptr");
        std::cout << "RC = " << shptr1.use_count() << '\n';
        {
            auto shptr2 = shptr1;
            std::cout << "RC = " << shptr1.use_count() << '\n';
        }
        std::cout << "RC = " << shptr1.use_count() << '\n';
    }
    system("pause");
}