//���һ��CRectangle,���а�������CRectangle������������Ա����ʾ���ϽǺ����½ǵ������㡣Ҫ�������������
#include<iostream>
using namespace std;
class CPoint        //һ�����ڵ���࣬���Լ�¼������
{
    public:
        CPoint();
        CPoint(int x, int y);
        CPoint(CPoint& a);
        int gx()
        {
            return x;
        }
        int gy()
        {
            return y;
        }
    private:
        int x, y;
};
class CRectangle//������йص���
{
    public:
        CRectangle();
        CRectangle(CPoint a, CPoint b);
        CRectangle(int, int, int, int);
        CRectangle(CRectangle& a);
        int GetArea();
    private:
        CPoint l;CPoint r;//��¼���Ͻǵ���������½ǵ�����

};
CPoint::CPoint()
{
    x = 0, y = 0;
    cout << "CPoint contstructor with default value(0,0) is called" << endl;
}
CPoint::CPoint(int inx, int iny)
{
    x = inx;y = iny;
    cout << "CPoint contstructor with default value(0,0) is called" << endl;
}
CPoint::CPoint(CPoint& a)
{
    x = a.x;y = a.y;
    cout << "CPoint copy contstructor is called" << endl;
}


CRectangle::CRectangle()
{
    cout << "CRectangle default contstructor is called" << endl;
}
CRectangle::CRectangle(CPoint a, CPoint b):l(a),r(b)
{
    cout << "CRectangle contstructor with (CPoint,CPoint) is called" << endl;
}
CRectangle::CRectangle(int a, int b, int c, int d):l(a,b),r(c,d)
{
    cout << "CRectangle contstructor with (int,int,int,int) is called" << endl;
}
CRectangle::CRectangle(CRectangle& a):l(a.l),r(a.r)
{
    cout << "CRectangle copy contstructor is called" << endl;
}
int CRectangle::GetArea()
{
    int area, lon, hight;
    lon = r.gx()-l.gx();
    hight =r.gy()-l.gx();
    area = lon * hight;
    return area;
}
int main()
{
    int a = 1, b = 1, c = 6, d = 11;
    cout << "# Define p1 ######" << endl;
    CPoint p1;
    cout << "# Define p2 ######" << endl;
    CPoint p2(10, 20);
    cout << "# Define rect1 ######" << endl;
    CRectangle rect1;
    cout << "# Define rect2 ######" << endl;
    CRectangle rect2(p1, p2);
    cout << "# Define rect3 ######" << endl;
    CRectangle rect3(a, b, c, d);
    cout << "# Define rect4 ######" << endl;
    CRectangle rect4(rect2);
    cout << "# Calculate area ######" << endl;
    cout << "rect1���Ϊ" << rect1.GetArea() << endl;
    cout << "rect2���Ϊ" << rect2.GetArea() << endl;
    cout << "rect3���Ϊ" << rect3.GetArea() << endl;
    cout << "rect4���Ϊ" << rect4.GetArea() << endl;
    system("pause");
    return 0;
}