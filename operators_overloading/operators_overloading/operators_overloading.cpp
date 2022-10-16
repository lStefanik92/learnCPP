
#include <iostream>

using namespace std;

class cVector {
    float fx;
    float fy;
public:
    cVector(float X, float Y) : fx(X), fy(Y) {}

    friend cVector operator+(cVector& v1, cVector& v2)
    {
        return cVector(v1.fx + v2.fx, v1.fy + v2.fy);
    }

    cVector operator*(float fNum)
    {
        return cVector(fx * fNum, fy * fNum);
    }

    friend cVector operator*(cVector& v1, cVector& v2)
    {
        return cVector(v1.fx * v2.fx, v1.fy * v2.fy);
    }

    void display()
    {
        cout << fx << ", " << fy << endl;
    }

};

int main()
{
    cVector c1(2, 3);
    cVector c2(2, 3);
    cVector c3 = c1 + c2;
    cVector c4 = c1 * 3;
    cVector c5 = c4 * c3;
    c3.display();
    c4.display();
    c5.display();

    return 0;
}