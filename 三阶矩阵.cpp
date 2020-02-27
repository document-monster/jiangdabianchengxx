#include<iostream>
using namespace std;
int main()
{   int a[9],b[9],c[9],i,j,k;
    
    for(i=0;i<9;i++)
		cin>>a[i];
	
	for(i=0;i<9;i++)
		cin>>b[i];

	for(i=0;i<9;i=i+3)
	{   
		k=i;
		for(j=0;j<9;j++)
		{
			c[k]=a[i]*b[j]+a[i+1]*b[j+3]+a[i+2]*b[j+6];
			k+=1;
		}
	}
    k=0;
	for(i=0;i<9;i++)
	{	
		cout<<c[i]<<' ';
		k++;
		if(k%3==0) cout<<endl;
	}
	
}