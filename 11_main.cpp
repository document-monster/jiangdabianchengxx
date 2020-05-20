//�벹����ʵ�ͷ�ļ� 
#include<iostream>
#include<string>
#include<exception>
using  namespace  std;
//�붨���쳣��MyException1 
class MyException1
{   
public:
    string what()
    {
        return "12MyException1";
    }
};

//�붨���쳣��MyException2 
class MyException2
{
public:
    string what()
    {
        return "12MyException2";
    }
};
//�붨�庯��divide()���Գ�0���������쳣 
int divide(int a,int b)
{
    
    if (b == 0)
        throw b;
    else
        return a/b;

}

int  main()
{
    int  id, k;
    cin >> id;
    char  a;
    string  s = "hello";
    try
    {
        switch (id)
        {
        case  1:
            throw  MyException1();
            break;
        case  2:
            throw  MyException2();
            break;
        case  3:
            k = divide(8, 0);
            break;
        case  4:
            a = s.at(10);
            cout << a << endl;
            break;
        default:
            break;
        }
    }
    catch (MyException1 & e)
    {
        cout << "exception:  " << e.what() << endl;
    }
    catch (MyException2 & e)
    {
        cout << "exception:  " << e.what() << endl;
    }
    catch (int& e)
    {
        cout << "exception:  " << e << endl;
    }
    catch (exception & e)
    {
        cout << "exception:  " << e.what() << endl;
    }
    cout << "Return  to  main()" << endl;
    return  0;
}