//����������Boat��Car�����߶��г�Աweight���������ߵ���Ԫ����totalweight����������������weight�ĺ͡�
#include<iostream>
using namespace std;
//�������ﲹ����Boat��Car�Ķ��� 
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