//定义一个复数类，设计+/-的重载函数，实现对两个复数的相加或相减及复数与浮点数的相加和相减
#include  <iostream> 
using  namespace  std;
class Complex
{
private:
    float real;int image;
public:
    Complex(int, int);
    Complex();
    void print();
    Complex operator +(Complex);
    Complex operator +(float);
    Complex operator -(Complex);
    Complex operator -(float);
};
Complex::Complex(int Real, int Image)
{
    real = Real;
    image = Image;
}
Complex::Complex()
{
    real = 0;
    image = 0;
}
void Complex::print()
{
    cout << real << "+" << image << "i" << endl;
}
Complex Complex:: operator +(Complex x)
{
    Complex n;
    n.real = real + x.real;
    n.image = image + x.image;
    return n;
}
Complex Complex:: operator -(Complex x)
{
    Complex n;
    n.real = real - x.real;
    n.image = image - x.image;
    return n;
}
Complex Complex:: operator -(float x)
{
    Complex n;
    n.real = real - x;
    n.image = image;
    return n;
}
Complex Complex:: operator +(float x)
{
    Complex n;
    n.real = real + x;
    n.image = image;
    return n;
}

int  main()
{
    Complex  a(3, 4), b(1, -1), c;
    c = a + b;
    cout << "a+b=";
    c.print();
    cout << endl;
    c = a - b;
    cout << "a-b=";
    c.print();
    cout << endl;
    c = a + 100;
    cout << "a+100=";
    c.print();
    cout << endl;
    c = a - 2.5;
    cout << "a-2.5=";
    c.print();
    cout << endl;

    return  0;
}