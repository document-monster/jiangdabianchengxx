//
#include  <iostream>
using  namespace  std;
//编写类
class vehicle
{
private:
    int maxspeed, weight;
public:
    vehicle(int, int);
    ~vehicle();
    void run();
    void stop();
};
vehicle::vehicle(int speed, int Weight)
{
    maxspeed = speed;
    weight = Weight;
    cout << "vehicle constructor called.maxspeed:" << maxspeed << ";weight" << weight << endl;
}
vehicle::~vehicle()
{
    cout << "vehicle destructor called.maxspeed:" << maxspeed << ";weight" << weight << endl;
}
void vehicle::run()
{
    cout << "vehicle run" << endl;
 }
void vehicle::stop()
{
    cout << "vehicle stop" << endl;
}

class bicyle :virtual public vehicle
{
private:
    int height;
public:
    bicyle(int Height, int speed, int Weight) :vehicle(speed, Weight)
    {
        height = Height;
        cout << "bicycle constructor called.height:" << height << endl;
        
    }
    ~bicyle() { cout << "bicycle destructor called.height:" << height << endl; };
};

class motorcar :virtual public vehicle
{
private:
    int seatnum;
public:
    motorcar(int Seatnum,int speed,int Weight):vehicle(speed,Weight)
    {
        seatnum = Seatnum;
        cout << "motorcar constructor called.seatnum:" << seatnum << endl;
    }
    ~motorcar()
    {
        cout << "motorcar destructor called.seatnum:" << seatnum << endl;

    }
};

class motorcycle :public bicyle , public motorcar
{
public:
    motorcycle(int a, int b, int c, int d) :vehicle(c, d), bicyle(a, c, d),motorcar(b, c, d)
    {
        cout << "motorcycle constructor called" << endl;
    }
    ~motorcycle() 
    {
        cout << "motorcycle destructor called" << endl;
    }
    
};
int  main(int  argc, char* argv[])
{
    motorcycle  m(1, 2, 3, 4);//1表示height，2表示setnum，3表示maxspeed，4表示weight 
    m.run();
    m.stop();
    return  0;
}