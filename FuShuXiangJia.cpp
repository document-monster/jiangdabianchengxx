//添加重载函数，实现复数的多种加法运算

#include  <iostream> 
#include  <iomanip> 
using  namespace  std;

struct  complex//表示复数的结构体
{
    double  r;
    double  i;
};
//关于复数相加的重载函数
complex add(complex x, complex y)
{
    complex i;
    i.r = x.r + y.r;
    i.i = x.i + y.i;
    return i;

};
complex add(complex m, double n)
{
    complex j;
    j.r = m.r + n;
    j.i = m.i;
    return j;
};
complex add(double p, complex q)
{
    complex k;
    k.r = q.r + p;
    k.i = q.i;
    return k;
};
    int  main()
{
    double  num;
    complex  a, b, c;
    cin >> a.r >> a.i;//输入进行运算的复数或整数
    cin >> b.r >> b.i;
    cin >> num;
    c = add(a, b);
    cout << c.r << "+" << c.i << "i" << endl;
    c = add(a, num);
    cout << c.r << "+" << c.i << "i" << endl;
    c = add(num, b);
    cout << c.r << "+" << c.i << "i" << endl;
}




