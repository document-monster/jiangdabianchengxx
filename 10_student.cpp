//����ṹ��student������stu_id,score��������������stu_id��һ��short�ͱ�����scoreΪshort�ͱ�����
//����n��ѧ�������ݼ��������洢��new�½�������a��
//��write�������Զ����ƽ�a�����е�n��ѧ��һ����д��out.txt��
#include<iostream>
#include<fstream>
using namespace std;
struct student
{
	short std_id;
	short score;
};

int main()
{
	int n;cin >> n;
	student *p=new student[n];
	int i;
	for (i = 0;i < n;i++)
	{
		cin >> p[i].std_id;
		cin >> p[i].score;
	}

	fstream file("out.txt", ios::out | ios::binary);
	file.write(reinterpret_cast<char*>(p), sizeof(p));
	file.close();

	student* p2 = new student[n];
	file.open("out.txt", ios::in|ios::binary);if (file)cout << 1;
	for (i = 0;i < n;i++)
	{
		file.read(reinterpret_cast<char*> (p2 + i), sizeof(student));
	}
	file.close();

	file.open("out,txt", ios::out|ios::app);
	file.write(reinterpret_cast<char*>(p2), sizeof(student));
	file.close();

	delete []p;
	delete[]p2;
	return 0;
}