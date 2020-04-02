//定义两个类Boat和Car，两者都有成员weight，定义两者的友元函数totalweight（），求两个对象weight的和。
#include<iostream>
using namespace std;
//请在这里补充类Boat和Car的定义 
class Car;
class Boat
{
    public:
        Boat(int a) { weight = a; }
        friend int totalweight(Boat& b,Car& c);
    private:
        int weight;
};

class Car
{
    public:
        Car(int a) { weight = a; }
        friend int totalweight(Boat& b, Car& c);
    private:
        int weight;
};

int  totalweight(Boat& b, Car& c)
{
    return  b.weight + c.weight;
}
int  main()
{
    Boat  b(100);
    Car  c(200);
    cout << totalweight(b, c) << endl;
    return  0;
}