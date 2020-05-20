//a.txt文件中已预先存储了一组数据，以空格分隔，数据的个数不确定。从a.txt文件中读取数据并将从小到大的排序后的数据输出到b.txt文件
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