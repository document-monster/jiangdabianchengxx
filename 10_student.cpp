//定义结构体student，包括stu_id,score两个变量。其中stu_id是一个short型变量，score为short型变量。
//输入n个学生的数据及个数，存储在new新建的数组a中
//用write函数，以二进制将a数组中的n给学生一次性写入out.txt中
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