//������غ�����ʵ�ָ����Ķ��ּӷ�����

#include  <iostream> 
#include  <iomanip> 
using  namespace  std;

struct  complex//��ʾ�����Ľṹ��
{
    double  r;
    double  i;
};
//���ڸ�����ӵ����غ���
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
    cin >> a.r >> a.i;//�����������ĸ���������
    cin >> b.r >> b.i;
    cin >> num;
    c = add(a, b);
    cout << c.r << "+" << c.i << "i" << endl;
    c = add(a, num);
    cout << c.r << "+" << c.i << "i" << endl;
    c = add(num, b);
    cout << c.r << "+" << c.i << "i" << endl;
}




