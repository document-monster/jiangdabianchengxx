//请根据油桶进行抽象，设计一个类，要求解油桶的容量和制造该油桶所需的铁皮面积
#include  <iostream> 
#include<iomanip> 
#include  <cmath> 
using  namespace  std;

const  double  PI = 3.1415926;
//关于油桶的类的实例化
class cylinder
{
    public:
        void init(double h, double r);
        double getvolumn();
        double getarea();
    private:
        double r, h;//h为油桶的高，r为油桶的半径
};
void cylinder :: init(double hight, double raidou)
{
    h = hight;
    r = raidou;
};
double cylinder :: getvolumn()//求油桶的容积
{
    double v;
    v = r * r * PI * h;
    return v;
};
double cylinder :: getarea()//求油桶的表面积
{
    double a;
    a = PI * 2 * r * h + PI * r * r * 2;
    return a;
};

int  main()
{
    double  d, h;
    cin >> d >> h;//输入直径和高
    cylinder can;
    can.init(h, d / 2);
    cout << fixed << setprecision(6);
    cout << "油桶的容积是" << can.getvolumn() << "  " << endl;
    cout << "铁皮的面积是" << can.getarea() << endl;
}
