//a.txt�ļ�����Ԥ�ȴ洢��һ�����ݣ��Կո�ָ������ݵĸ�����ȷ������a.txt�ļ��ж�ȡ���ݲ�����С��������������������b.txt�ļ�
#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
int main()
{ 
	vector<float> h;float d;int i = 0;
	fstream myFile;
	myFile.open("a.txt", ios::in);
	if (myFile)
	{
		while (myFile.good())
		{
			myFile>>d;
			
			h.push_back(d),i++;
			
		}
	}
	myFile.close();
	sort(h.begin(), h.end());
	ofstream Myfile("b.txt", ios::out);
	int j;
	for (j = 0;j < i;j++)
	{
		Myfile << h[j] << ' ';
	}
	
	Myfile.close();
	return 0;
}