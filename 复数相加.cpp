//��ƺ���������������ӣ����������λС��
#include<iostream>
#include<iomanip>
using namespace std;
void min(float a, float b, float c, float d)
{
	float i,j;
	i = a - c;
	j = b - d;
	cout<<fixed<<setprecision(2)<<i
		<<' '
		<<fixed<<setprecision(2)<<j
		<<endl;
	return ;
}
int main()
{
	float a, b, c, d;
	cin>>a>>b>>c>>d;
	min(a, b, c, d);
	return 0;
}