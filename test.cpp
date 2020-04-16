#include<iostream>
#include<string>
#include  <vector>
using namespace std;
class  Book
{
    //���ڴ˴�����Book��Ķ��� 
private:
    unsigned int m_ID;//���
    string m_Name;//����
    string m_Introductio;//���
    string m_Author;//����
    string m_Date;//����
    unsigned int m_Page;//ҳ��
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
};
//���ڴ˴�����Book��ĳ�Ա����ʵ�� 
Book::Book()
{
    m_ID = 0;
    m_Name = "0";
    m_Introductio = "0";
    m_Author = "0";
    m_Date ="0";
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
class  Store
{
    //���ڴ˴�����Store��Ķ��� 
private:
    vector <Book> m_Books;
public:
    unsigned int GetCount() { return m_Books.size(); }
    Store();
    Store(int);
    virtual ~Store();
    Store(const Store& other);
    void in(Book& b);
    void out(string name);
    Book findbyID(int ID);
    Book findbyName(string name);
    void printList();
};
//���ڴ˴�����Store��ĳ�Ա����ʵ�� 
Store::Store()
{
    cout << "Store defualt constructor called!" << endl;
}
Store::Store(int n)
{
    m_Books.reserve(n);
    cout << "Store constructor with (int n) called!" << endl;
}
Store::~Store()
{
    cout << "Store destructor called!" << endl;
}
Store::Store(const Store& other)
{
    m_Books = other.m_Books;
    cout << "Store copy constructor called!" << endl;
}
void Store::in(Book& b)
{
    m_Books.push_back(b);
}
void Store::out(string name)
{
    unsigned int i;
    for (i = 0;i < GetCount();i++)
    {
        if (m_Books[i].GetName() == name)
            m_Books.erase(m_Books.begin() + i);
    }
}
Book Store::findbyID(int n)
{
    unsigned int i, j = 0;
    for (i = 0;i < GetCount();i++)
    {
        if (m_Books[i].GetID() == n)
            j = i;
    }
    if (j == 0)
    {
        Book p;
        return p;
    }
    else
        return m_Books[j];
}
Book Store::findbyName(string name)
{
    unsigned int i, j = 0;
    for (i = 0;i < GetCount();i++)
    {
        if (m_Books[i].GetName() == name)
            j = i;
    }
    Book p;
    if (j == 0)
    {
       
        return p;
    }
    else
    {
        return m_Books[j];
       
    }
}
void Store::printList()
{
    unsigned int i;
    for (i = 0;i < GetCount();i++)
    {
        cout << "ID=" << m_Books[i].GetID() << ";";
        cout << "Name:" << m_Books[i].GetName() << ";";
        cout << "Author:" << m_Books[i].GetAuthor() << ";";
        cout << "Date:" << m_Books[i].GetDate() << ";" << endl;
    }
}
int  main()
{
    Store  s;
    Book  b1, b2, b3;
    b1.SetID(1);
    b1.SetName("C++  ���Գ������(��4��)");
    b1.SetAuthor("֣��");
    b1.SetIntroduction("����C++����������֪ʶ");
    b1.SetDate("201007");
    b1.SetPage(529);
    b2.SetID(2);
    b2.SetName("��ɢ��ѧ");
    b2.SetAuthor("��Т��");
    b2.SetIntroduction("���������߼���ν���߼��������ۡ�����ϵͳ��ͼ��");
    b2.SetDate("198209");
    b2.SetPage(305);
    b3.SetID(3);
    b3.SetName("c�������");
    b3.SetAuthor("̷��ǿ");
    b3.SetIntroduction("����C��������еĻ���֪ʶ��������ʽ���﷨��");
    b3.SetDate("201006");
    b3.SetPage(355);

    cout << "��һ�������" << endl;
    s.in(b1);
    cout << "�ڶ��������" << endl;
    s.in(b2);
    cout << "�����������" << endl;
    s.in(b3);
    cout << "���п���鼮������" << s.GetCount() << endl;
    cout << "���Ҳ�����ͼ�飺��ɢ��ѧ" << endl;
    Book  tmpbook = s.findbyName("��ɢ��ѧ");
    if (tmpbook.GetID() != 0)
    {
        s.out("��ɢ��ѧ");
        cout << "��ɢ��ѧ  �ѳɹ�����" << endl;
    }
    else
        cout << "û���ҵ�nameΪ��ɢ��ѧ����" << endl;
    cout << "���п���鼮������" << s.GetCount() << endl;

    cout << "����ͼ��  ID��3" << endl;
    tmpbook = s.findbyID(3);
    if (tmpbook.GetID() != 0)
        cout << "�ҵ�IDΪ" << 3 << "���飬������" << tmpbook.GetName() << endl;
    else
        cout << "û���ҵ�IDΪ" << 3 << "����" << endl;

    cout << "����ͼ��  name����ɢ��ѧ" << endl;
    tmpbook = s.findbyName("��ɢ��ѧ");
    if (tmpbook.GetID() != 0)
        cout << "�ҵ�nameΪ��ɢ��ѧ���飬ID��" << tmpbook.GetID() << endl;
    else
        cout << "û���ҵ�nameΪ��ɢ��ѧ����" << endl;

    cout << "������п��ͼ�����Ϣ" << endl;
    s.printList();
    cout << "�������н���" << endl;
    return  0;
}