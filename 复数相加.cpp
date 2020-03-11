//设计函数，求两复数相加，结果保留两位小数
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