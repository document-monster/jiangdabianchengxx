//简易银行用户管理程序
#include  <iostream> 
#include  <iomanip> 
#include  <cmath>
using  namespace  std;
//存钱的类
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
        cout << "您输入的金额不合法" << endl;money = 0;
    }
    else
        money = inmoney;
};
void Account::printmoney()
{
    cout << fixed << setprecision(2);
    cout<<name<<"的存款为"<<money << endl;
};
void  Account :: deposit(double income)
{
    double m;
    m = (int)(income * 1000) % 10;
    if (m != 0)
        cout << "您输入的金额不合法" << endl;
    else
        money = income + money;
};
void  Account :: withdraw(double moneyOut)
{
    double n;
    n = (int)(moneyOut * 100) % 10;
    if (n != 0)
        cout << "您输入的金额不合法" << endl;
    else
        if (moneyOut > money)
            cout << "您的存款金额不足" << endl;
        else
            money = money - moneyOut;
};
int  main()
{
    Account  tom;
    tom.init("32020320011001876X", "Tom  Black", "男", 19, 2000.89);//输入个人信息
    tom.printmoney();//输出：Tom  Black的存款为2000.89 
    tom.deposit(89.471);//输出：”您输入的金额不合法“，存款数额最多保留两位小数 
    tom.printmoney();//输出：Tom  Black的存款为2000.89 
    tom.deposit(10000);
    tom.printmoney();//输出：Tom  Black的存款为12000.89 
    tom.withdraw(10001);
    tom.printmoney();//输出：Tom  Black的存款为1999.89 
    tom.withdraw(10000.123);//输出：您输入的金额不合法 
    tom.printmoney();//输出：Tom  Black的存款为1999.89 
    tom.withdraw(10000.9);//输出：您的存款金额不足 
    tom.printmoney();//输出：Tom  Black的存款为1999.89 
    Account  jerry;
    jerry.init("320203200910116569", "Jerry  Black", "女", 11, 100.956);//输出：您输入的金额不合法 
    jerry.printmoney();//输出：Jerry  Black的存款为0.00 
}