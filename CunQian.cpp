//���������û��������
#include  <iostream> 
#include  <iomanip> 
#include  <cmath>
using  namespace  std;
//��Ǯ����
class Account
{
    public:
        void init(string inNumber, string inName, string inGender, int inage, double inmoney);
        void printmoney();
        void  deposit(double income);
        void  withdraw(double moneyOut);
    private:
        string num, name, gender;
        int age;
        double money;
};
void Account::init(string  inNumber, string inName, string inGender, int inage, double inmoney)
{
    
    num = inNumber;
    name = inName;
    gender = inGender;
    age = inage;
    money = inmoney;
    double m;
    m = (int)(inmoney * 1000) % 10;
    if (m != 0)
    {
        cout << "������Ľ��Ϸ�" << endl;money = 0;
    }
    else
        money = inmoney;
};
void Account::printmoney()
{
    cout << fixed << setprecision(2);
    cout<<name<<"�Ĵ��Ϊ"<<money << endl;
};
void  Account :: deposit(double income)
{
    double m;
    m = (int)(income * 1000) % 10;
    if (m != 0)
        cout << "������Ľ��Ϸ�" << endl;
    else
        money = income + money;
};
void  Account :: withdraw(double moneyOut)
{
    double n;
    n = (int)(moneyOut * 100) % 10;
    if (n != 0)
        cout << "������Ľ��Ϸ�" << endl;
    else
        if (moneyOut > money)
            cout << "���Ĵ�����" << endl;
        else
            money = money - moneyOut;
};
int  main()
{
    Account  tom;
    tom.init("32020320011001876X", "Tom  Black", "��", 19, 2000.89);//���������Ϣ
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89 
    tom.deposit(89.471);//�������������Ľ��Ϸ��������������ౣ����λС�� 
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ2000.89 
    tom.deposit(10000);
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ12000.89 
    tom.withdraw(10001);
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
    tom.withdraw(10000.123);//�����������Ľ��Ϸ� 
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
    tom.withdraw(10000.9);//��������Ĵ����� 
    tom.printmoney();//�����Tom  Black�Ĵ��Ϊ1999.89 
    Account  jerry;
    jerry.init("320203200910116569", "Jerry  Black", "Ů", 11, 100.956);//�����������Ľ��Ϸ� 
    jerry.printmoney();//�����Jerry  Black�Ĵ��Ϊ0.00 
}