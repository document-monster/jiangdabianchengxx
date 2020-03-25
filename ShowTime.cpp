//声明一个表示时间的类，精确地表示年、月、日、小时、分、秒，并计算两个日期之间相隔的天数。
#include<iostream>
using namespace std;
int c=1;
int runNian(int a)//判断是否为闰年
{
    if (a % 400 == 0)
        return 1;
    else
        if (a % 100 != 0 && a % 4 == 0)
            return 1;
        else 
            return 0;
}
class CTime     //定义类CTime
{
private:
    int year, month, day, hour, minute, second;
public:
    CTime(int inYear = 0, int inMonth = 0, int inDay = 0, int inHour = 0, int inMinute = 0, int inSecond = 0);
    CTime(CTime& a);
    ~CTime();
    void showTime();
    int isvalid();
    int dayDiff(CTime b);
};                               
CTime::CTime(int inYear, int inMonth, int inDay, int inHour, int inMinute, int inSecond )
{                             //构造函数，输入日期和时间，并判断是否错误,错误则时间调零
    int i = 1, k = 1;
    year = inYear;month = inMonth;day = inDay;hour = inHour;minute = inMinute;second = inSecond;
    if (month > 12 || day > 31)
    {
       i = 0;
    }
    if (hour > 23 || minute > 59 || second > 59)
    {
        k = 0;
    }
    switch (month)
    {
    case 1: {if (day > 31)i = 0;break;}
    case 2:break;
    case 3: {if (day > 31) i = 0;break;}
    case 4: {if (day >= 31)i = 0;break;}
    case 5: {if (day > 31) i = 0;break;}
    case 6: {if (day >= 31) i = 0;break;}
    case 7: {if (day > 31)i = 0;break;}
    case 8: {if (day > 31) i = 0;break;}
    case 9: {if (day >= 31) i = 0;break;}
    case 10:{if (day > 31) i = 0;break;}
    case 11:{if (day >= 31) i = 0;break;}
    case 12:{if (day > 31) i = 0;break;}
    default: {i = 0;break;}
    }
    if (month == 2)
        if (day > 29) { i = 0; }
        else
            if (runNian(year));
            else
                if(day>28)
                {
                    i = 0;
                }
    switch (i + k)
    {
        case 2:break;
        case 1:
        {
            if (i == 0)cout << "date error!" << endl;
            else cout << "time error!" << endl;
            c = 0;
            break;
        }
        case 0:
        {
            cout << "date and time error!" << endl;
            c = 0;
            break;
        }
    }
        
    if (i == 0||k==0)   
        year = day =month= hour=minute=second=0;
    cout << "构造函数被调用" << endl;
}

CTime::CTime(CTime& a)
{
    year = a.year;month = a.month;day = a.day;hour = a.hour;minute = a.minute;second = a.second;
    cout << "拷贝构造函数被调用" << endl;
}

CTime::~CTime()
{
    cout << "析构函数被调用" << endl;
}

int CTime::isvalid()
{
    if (c == 1)return 1;
    else return 0;
}
int yuecha(int dy, int xy, int a[12])
{
    int i,days=0;
    for (i = xy - 1;i < dy - 1;i++)
        days += a[i];
    return days;
}

int CTime::dayDiff(CTime t)    //计算两日期之间的天数
{
    int days;
    int monthDays[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if (year == t.year)
        if (month >= t.month)
        {
            days = yuecha(month, t.month, monthDays) + day - t.day;
            if (month > 2 && runNian(t.year)) days += 1;
        }
        else
        {
            days = yuecha(t.month, month, monthDays) + t.day - day;
            if (t.month > 2 && runNian(year)) days += 1;
        }
    else
    if (year > t.year)
        if (month >= t.month)
        {
            days = (year - t.year) * 365 + (year - t.year) / 4 + day - t.day + yuecha(month, t.month, monthDays);
            if (month > 2 && runNian(t.year)) days += 1;
        }
        else
        {
            days = (year - t.year) * 365 + (year - t.year) / 4 - yuecha(t.month, month, monthDays) - day + t.day;
            if (t.month > 2 && runNian(year)) days -= 1;
        }
    else
        if (month > t.month)
        {
            days = (t.year - year) * 365 + (t.year - year) / 4 - yuecha(month,t.month, monthDays) - t.day + day;
            if (month > 2 && runNian(year)) days -= 1;
        }
        else
        {
            days = (t.year - year) * 365 + (t.year - year) / 4 - day + t.day + yuecha(t.month, month, monthDays);
            if (t.month > 2 && runNian(t.year)) days += 1;
        }
            return days;
}

void CTime::showTime()        //显示时间
{
    cout << year << '/' << month << '/' << day << ' ' << hour << ':' << minute << ':' << second << endl;
}
int  main()
{
    int  year, month, day, hour, minute, second;
    cin >> year >> month >> day >> hour >> minute >> second;
    CTime  t1(year, month, day, hour, minute, second);
    t1.showTime();
    CTime  t2(2000, 1, 1);  //利用默认形参将时间初始化为00:00:00 
    if (t1.isvalid())          //如果日期和时间合法，则计算天数 
    {
        int  days = 0;
        days = t1.dayDiff(t2);
        cout << "这两天之间相隔了" << days << "天" << endl;
        days = t2.dayDiff(t1);
        cout << "这两天之间相隔了" << days << "天" << endl;
    }
    return 0;
}