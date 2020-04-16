#include<iostream>
#include<string>
using namespace std;
class Book
{
public:
    Book();
    Book(const Book& other);
    void SetID(int x) { m_ID = x; }
    void SetName(string x) { m_Name = x; }
    void SetIntroduction(string x) { m_Introductio = x; }
    void SetAuthor(string x) { m_Author = x; }
    void SetDate(string x) { m_Date = x; }
    void SetPage(int x) { m_Page = x; }
    int GetID() { return m_ID; }
    string GetName() { return m_Name; }
    string GetIntroduction() { return m_Introductio; }
    string GetAuthor() { return m_Author; }
    string GetDate() { return m_Date; }
private:
    unsigned int m_ID;//编号
    string m_Name;//书名
    string m_Introductio;//简介
    string m_Author;//作者
    string m_Date;//日期
    unsigned int m_Page;//页数
};
Book::Book()
{
    m_ID = 0;
    m_Name = " ";
    m_Introductio = " ";
    m_Author = " ";
    m_Date = " ";
    m_Page = 0;
}
Book::Book(const Book& other)
{
    m_ID = other.m_ID;
    m_Name = other.m_Name;
    m_Introductio = other.m_Introductio;
    m_Author = other.m_Author;
    m_Date = other.m_Date;
    m_Page = other.m_Page;
}

class Store
{
public:
    Store();     //构造函数
    Store(int);  //对放入或取出图书时对Book数组进行更改时使用的构造函数
    virtual ~Store()//析构函数
    {
        m_Count = 0;
        if (m_pBook != 0)
            delete[] m_pBook;
        cout << "Store destrutor called!" << endl;
    }
    Store(const Store& other);//拷贝构造函数
    void in(Book& b);//将书本放入Store
    void out(string);//将对应书名的书取出
    int GetCount() { return m_Count; }//返回书的数量
    Book findbyID(int);//利用ID找书
    Book findbyName(string);//利用书名找书
    void printList();//输出书目

private:
    Book* m_pBook;//指向利用new操作动态创建的Book数组
    unsigned int m_Count;//表示库存中图书的数量
};
Store::Store()
{
    m_Count = 0;
    m_pBook = 0;
    cout << "Store default constructor called!" << endl;
}
Store::Store(int n)
{

    m_pBook = new Book[n];
    cout << "Store constructor with (int n) called!" << endl;
}
Store::Store(const Store& other)
{

    cout << "Store copy cinstructor called!" << endl;
}
void Store::in(Book& b)
{
    Book* p;
    p = m_pBook;
    m_Count += 1;
    unsigned int i;
    i = m_Count;
    m_pBook = new Book[m_Count];
    for (i = 0;i < m_Count - 1;i++)
        *(m_pBook + i) = *(p + i);
    *(m_pBook + m_Count - 1) = b;
    delete[] p;

}
void Store::out(string n)
{
    unsigned int i, j = 0;
    for (i = 0;i < m_Count;i++)
    {
        string m = m_pBook[i].GetName();
        if (m == n)
            j = i;
    }
    Book* p;
    p = m_pBook;
    m_Count -= 1;
    m_pBook = new Book[m_Count];
    for (i = 0;i < m_Count;i++)
    {
        if (i != j)
            *(m_pBook + i) = *(p + i);
        else
            *(m_pBook+i)=*(p+j+1);
    }
    delete[] p;
}

Book Store::findbyID(int n)
{
    unsigned int i, j = 0;int m;
    for (i = 0;i < m_Count;i++)
    {
        m = m_pBook[i].GetID();
        if (m == n)
            j = i;
    }
    Book p;
    if (j == 0)
    {
        return p;
    }
    else
        return *(m_pBook + j);
}
Book Store::findbyName(string n)
{
    unsigned int i, j = 0;string m;
    for (i = 0;i < m_Count;i++)
    {
        m = m_pBook[i].GetName();
        if (m == n)
            j = i;
    }
    Book p;
    if (j == 0)
    {
        return p;
    }
    else
        return *(m_pBook + j);
}
void Store::printList()
{
    unsigned int i;
    cout << "There are totally " << m_Count << " Books:" << endl;
    for (i = 0;i < m_Count;i++)
    {
        cout << "ID=" << (m_pBook + i)->GetID() << ";  ";
        cout << "Name:" << (m_pBook + i)->GetName() << ";  ";
        cout << "Auther:" << (m_pBook + i)->GetAuthor() << ";  ";
        cout << "Date:" << (m_pBook + i)->GetDate() << ";  " << endl;
    }
}

int  main()
{
    Store  s;
    Book  b1, b2, b3;
    b1.SetID(1);
    b1.SetName("C++  语言程序设计(第4版)");
    b1.SetAuthor("郑莉");
    b1.SetIntroduction("介绍C++及面向对象的知识");
    b1.SetDate("201007");
    b1.SetPage(529);
    b2.SetID(2);
    b2.SetName("离散数学");
    b2.SetAuthor("左孝凌");
    b2.SetIntroduction("介绍命题逻辑、谓词逻辑、集合论、代数系统和图论");
    b2.SetDate("198209");
    b2.SetPage(305);
    b3.SetID(3);
    b3.SetName("c程序设计");
    b3.SetAuthor("谭浩强");
    b3.SetIntroduction("介绍C程序设计中的基本知识，如语句格式、语法等");
    b3.SetDate("201006");
    b3.SetPage(355);

    cout << "第一本书入库" << endl;
    s.in(b1);
    cout << "第二本书入库" << endl;
    s.in(b2);
    cout << "第三本书入库" << endl;
    s.in(b3);
    cout << "现有库存书籍数量：" << s.GetCount() << endl;
    cout << "查找并出库图书：离散数学" << endl;
    Book  tmpbook = s.findbyName("离散数学");
    if (tmpbook.GetID() != 0)
    {
        s.out("离散数学");
        cout << "离散数学  已成功出库" << endl;
    }
    else
        cout << "没有找到name为离散数学的书" << endl;
    cout << "现有库存书籍数量：" << s.GetCount() << endl;

    cout << "查找图书  ID：3" << endl;
    tmpbook = s.findbyID(3);
    if (tmpbook.GetID() != 0)
        cout << "找到ID为" << 3 << "的书，书名：" << tmpbook.GetName() << endl;
    else
        cout << "没有找到ID为" << 3 << "的书" << endl;

    cout << "查找图书  name：离散数学" << endl;
    tmpbook = s.findbyName("离散数学");
    if (tmpbook.GetID() != 0)
        cout << "找到name为离散数学的书，ID：" << tmpbook.GetID() << endl;
    else
        cout << "没有找到name为离散数学的书" << endl;

    cout << "输出所有库存图书的信息" << endl;
    s.printList();
    cout << "程序运行结束" << endl;
    return  0;
}