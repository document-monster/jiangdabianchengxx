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
    unsigned int m_ID;//���
    string m_Name;//����
    string m_Introductio;//���
    string m_Author;//����
    string m_Date;//����
    unsigned int m_Page;//ҳ��
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
    Store();     //���캯��
    Store(int);  //�Է����ȡ��ͼ��ʱ��Book������и���ʱʹ�õĹ��캯��
    virtual ~Store()//��������
    {
        m_Count = 0;
        if (m_pBook != 0)
            delete[] m_pBook;
        cout << "Store destrutor called!" << endl;
    }
    Store(const Store& other);//�������캯��
    void in(Book& b);//���鱾����Store
    void out(string);//����Ӧ��������ȡ��
    int GetCount() { return m_Count; }//�����������
    Book findbyID(int);//����ID����
    Book findbyName(string);//������������
    void printList();//�����Ŀ

private:
    Book* m_pBook;//ָ������new������̬������Book����
    unsigned int m_Count;//��ʾ�����ͼ�������
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