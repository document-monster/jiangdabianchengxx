//�������Ͱ���г������һ���࣬Ҫ�����Ͱ���������������Ͱ�������Ƥ���
#include  <iostream> 
#include<iomanip> 
#include  <cmath> 
using  namespace  std;

const  double  PI = 3.1415926;
//������Ͱ�����ʵ����
class cylinder
{
    public:
        void init(double h, double r);
        double getvolumn();
        double getarea();
    private:
        double r, h;//hΪ��Ͱ�ĸߣ�rΪ��Ͱ�İ뾶
};
void cylinder :: init(double hight, double raidou)
{
    h = hight;
    r = raidou;
};
double cylinder :: getvolumn()//����Ͱ���ݻ�
{
    double v;
    v = r * r * PI * h;
    return v;
};
double cylinder :: getarea()//����Ͱ�ı����
{
    double a;
    a = PI * 2 * r * h + PI * r * r * 2;
    return a;
};

int  main()
{
    double  d, h;
    cin >> d >> h;//����ֱ���͸�
    cylinder can;
    can.init(h, d / 2);
    cout << fixed << setprecision(6);
    cout << "��Ͱ���ݻ���" << can.getvolumn() << "  " << endl;
    cout << "��Ƥ�������" << can.getarea() << endl;
}
