//求两个3阶矩阵相乘的结果
#include<iostream>
using namespace std;
int main()
{   int a[9],b[9],c[9],i,j,k;
//输入两行数作为3*3矩阵
for(i = 0;i<9;i++)
	cin>>a[i];

for(i=0;i<9;i++)
	cin>>b[i];
//两矩阵相乘
for(i=0;i<9;i=i+3)
{   
	k=i;int *m=&a[i];
	for(j=0;j<9;j++)
	{
		int *n=&b[j];
		c[k]=*m * *n + *(m+1) * *(n+3) + *(m+2) * *(n+6);
		k+=1;
	}
}
k=0;
for(i=0;i<9;i++)//输出结果
{	
	cout<<c[i]<<' ';
	k++;
	if(k%3==0) cout<<endl;
}
return 0;

}