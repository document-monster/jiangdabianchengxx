//小明买水，一元一瓶，两个空瓶可换一瓶水，三个瓶盖可换一瓶水，输入钱的数量，求他可以买多少水（递归）
#include<iostream>
using namespace std;
int ping=0, gai=0;
int buyWater(int a)
{
	int b, sum;
	if (a==0) return 0;
	else 
	{   b=a/2+a/3;
	    gai = gai + a%3;
		ping = ping + a%2;
		if (gai >= 3) 
			gai = gai - 3, b += 1;
		if (ping >= 2)
			ping = ping - 2,b += 1;
	    sum=a+buyWater(b);
	}
	    return sum;

}
int main()
{
	int money,c;
	cin>>money;
	c=buyWater(money);
	cout<<c<<endl;
	return 0;
	
}