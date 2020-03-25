//计算油桶容和油桶表面积（带盖）运用构造函数和析构函数
#include<iostream>
#include<iomanip>
using namespace std;
const double PI = 3.1415926;
class cylinder
{
    private:
        double r, h;//油桶的半径和高
    public:
        double getvolumn();
        double getarea();

        cylinder(double hight, double radium);
        ~cylinder();
};
double cylinder::getvolumn()//计算容积
{
    return  PI * r * r * h;
}
double cylinder::getarea()//计算体积
{
    return 2 * PI * r * r + PI * 2 * r * h;
}
cylinder::cylinder(double hight, double radium)//构造函数对类进行初始化
{
    r = radium;
    h = hight;
    cout << "构造函数被调用" << endl;
}
cylinder::~cylinder()
{
    cout << "析构函数被调用" << endl;
}
int main()
{
    double d, h;
    cin >> d >> h;
    cylinder can(h, d / 2);
    cout << fixed << setprecision(6);
    cout << "油桶的容积是" << can.getvolumn() << " " << endl;
    cout << "铁皮的面积是" << can.getarea() << endl;
    return 0;
}