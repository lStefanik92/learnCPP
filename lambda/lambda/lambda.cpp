#include <iostream>

enum class mathOp {add, subt};

int main()
{
    int x = 1;
    int y = 1;
    std::cout << "x0 = " << x << '\n';
    std::cout << "y0 = " << y << '\n';

    auto lambdaX = [x](auto val, mathOp op) mutable -> double {
        if (op == mathOp::add) {
            std::cout << x + val << '\n';
            x += val;
        }
        else if (op == mathOp::subt) {
            std::cout << x - val << '\n';
            x -= val;
        }
        return x;
    };

    auto lambdaY = [&y](auto val, mathOp op) -> double {
        if (op == mathOp::add) {
            std::cout << y + val << '\n';
            y += val;
        }
        else if (op == mathOp::subt) {
            std::cout << y - val << '\n';
            y -= val;
        }
        return y;
    };

    lambdaX(2.2, mathOp::add);
    lambdaY(4.5, mathOp::subt);

    std::cout << "x = " << x << '\n';
    std::cout << "y = " << y << '\n';

    return 0;
}

