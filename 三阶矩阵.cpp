//������3�׾�����˵Ľ��
#include<iostream>
using namespace std;
int main()
{   int a[9],b[9],c[9],i,j,k;
//������������Ϊ3*3����
for(i = 0;i<9;i++)
	cin>>a[i];

for(i=0;i<9;i++)
	cin>>b[i];
//���������
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
for(i=0;i<9;i++)//������
{	
	cout<<c[i]<<' ';
	k++;
	if(k%3==0) cout<<endl;
}
return 0;

}