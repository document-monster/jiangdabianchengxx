//将+/-重载为友元函数，实现复数对象之间或复数与浮点数的相加或相减
#include  <iostream> 
using  namespace  std;
class Complex
{
private:
    float real; int image;
public:
    Complex(int, int);
    Complex();
    void print();
    friend Complex operator +(Complex,Complex);
    friend Complex operator +(Complex, float);
    friend Complex operator +(float, Complex);
    friend Complex operator -(Complex, Complex);
    friend Complex operator -(Complex, float);
    friend Complex operator -(float, Complex);
};
Complex::Complex(int Real, int Image)
{
    real = Real;
    image = Image;
}
Complex::Complex()
{
    real = 0;image = 0;
}
void Complex::print()
{
    cout << real << "+" << image << "i" << endl;
}
Complex operator +(Complex a, Complex b)
{
    Complex n;
    n.real = a.real + b.real;
    n.image = a.image + b.image;
    return n;
}
Complex operator +(Complex a, float b)
{
    Complex n;
    n.real = a.real + b;
    n.image = a.image;
    return n;
}
Complex operator +(float a, Complex b)
{
    Complex n;
    n.real = a + b.real;
    n.image = b.image;
    return n;
}
Complex operator -(Complex a, Complex b)
{
    Complex n;
    n.real = a.real - b.real;
    n.image = a.image - b.image;
    return n;
}
Complex operator -(Complex a, float b)
{
    Complex n;
    n.real = a.real - b;
    n.image = a.image;
    return n;
}
Complex operator -(float a, Complex b)
{
    Complex n;
    n.real = a - b.real;
    n.image = -b.image;
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
    c = 100 + a;
    cout << "100+a=";
    c.print();
    cout << endl;
    c = 2.5 - a;
    cout << "2.5-a=";
    c.print();
    cout << endl;
    return  0;
}