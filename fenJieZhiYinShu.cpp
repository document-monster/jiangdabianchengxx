//求一个数的质因数
#include<iostream>
#include<cmath>
using namespace std;
//判断是否为素数 ，不是回0，是回1
int  isPrime(long  num) 
{ 
	int i; double j;
	j = sqrt((double)num);
	for (i = 2; i < j; i++ )
		{
			if (num % i == 0)
			{return 1 ; break;}
	    }
    if (i > j)
		return 0;
} 

//计算质因素分解， 
void  factorization(long  n,long a[100],int &b) 
{ 
	int i, j;
	if ( isPrime(n))
		for (i = 0;;i++)
		{
			for (j = 2;; j++)
			{
				if (n % j == 0)
				{a[i] = j, n = n / j, b++;break;}
				else;
			}
			if (isPrime(n));
			else 
			{a[i+1] = n, b++;break;}
		}
	else a[0] = n, b++;

	return; 
} 

void  main() 
{ 
        long  n; 
        long  factor[100]; 
        int  numofFactor  =  0; 
        cin  >>  n; 
        factorization(n,  factor,  numofFactor); 
        for  (int  i  =  0;  i  <  numofFactor;  i++) 
        { 
                cout  <<  factor[i]  <<  "  "; 
        } 
        cout  <<  endl; 
        system("pause"); 
}