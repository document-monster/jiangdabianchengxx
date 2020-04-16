//
#include  <iostream> 
using  namespace  std;
const  float  pi = 3.14159;
//编写类
class Shape
{
private:
    int m_ID;
public:
    int GetID() { return m_ID; }
    void SetID(int n) { m_ID = n; }
    float getArea() { return 0; }
    Shape(int);
    ~Shape();
};
Shape::Shape(int n)
{
    m_ID = n;
    cout << "Shape constructor called:" << n << endl;
}
Shape::~Shape()
{
    cout << "Shape destructor called:" << m_ID << endl;
}

class Circle :public Shape
{
private:
    float r;
public:
    float Getr() { return r; }
    void Setr() {};
    int getArea();
    Circle(int,int);
    ~Circle();
};
Circle::Circle(int R,int ID):Shape(ID)
{
    cout << "Circle constructor called:" << ID << endl;
    r = R;
}
Circle::~Circle()
{
    cout << "Circle destructor called:" << GetID() << endl;
}
int Circle::getArea()
{
    int area;
    area = r * r * pi;
    return area;
}

class Rectangle :private Shape
{
private:
    int h, w;
public:
    Rectangle(int, int, int);
    ~Rectangle();
    int getArea();
};
Rectangle::Rectangle(int H, int W, int ID):Shape(ID)
{
    cout << "Rectangle constructor called:" << ID << endl;
    h = H;w = W;
}
Rectangle::~Rectangle()
{
    cout << "Rectangle destructor called:" << GetID() << endl;
}
int Rectangle::getArea()
{
    int area;
    area = h * w;
    return area;
}
int  main()
{
    Shape  s(1);//1表示ID 
    Circle  c(4, 2);//4表示半径，2表示ID 
    Rectangle  r(4, 5, 3);//4和5表示长和宽，3表示ID 
    cout << "Shape的面积" << s.getArea() << endl;
    cout << "Circle的面积" << c.getArea() << endl;
    cout << "Rectangle的面积" << r.getArea() << endl;
}