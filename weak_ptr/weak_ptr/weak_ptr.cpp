#include <iostream>
#include <memory>
#include <string>

class guineaPig {
    std::string s;
public:
    explicit guineaPig(std::string ss) : s(ss) { std::cout << "A new guinea pig named " << s << " is in the Lab!" << '\n'; }
    ~guineaPig() { std::cout << "The pig " << s << " died!" << '\n'; }
};

int main()
{
    {
        std::weak_ptr<guineaPig> wptr1 ;
        {
            std::shared_ptr<guineaPig> shptr1 = std::make_shared<guineaPig>("Piggy");      // 1 strong ref
            wptr1 = shptr1;                                                                // 1 strong and weak ref
        }
        std::cout << "Return 1 if managed object has been deleted: " << wptr1.expired() << '\n';
        
    }
    system("pause");
}