//定义Point类，重载前置++和后置++，重载流插入运算符，实现对Point对象的格式化输出
#include  <iostream> 
using  namespace  std;
class Point
{
private:
    int x, y;
public:
    Point(int, int);
    friend ostream & operator<<(ostream & out,Point  n);
    Point operator ++();
    Point operator ++(int)
    {
        Point n(0, 0);
        n.x = x;n.y = y;
        x++;y++;
        return n;
    }
};
Point::Point(int X,int Y)
{
    x = X, y = Y;
}
 Point Point::operator ++()
{
     x++, y++;
     return *this;
}
 ostream & operator<<(ostream & out, Point n)
 {
     cout << "(" << n.x << "," << n.y << ")" << endl;
     return out;
 }
 
int  main()
{
    Point  a(1, 3);
    cout << a;
    cout << a++;
    cout << ++a;
    return  0;
}