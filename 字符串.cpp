#include <iostream>
#include<stdio.h>
using namespace std;

int main()
{
    char a[10], b[10]; int j, numb=27,  i;  int c=0;
    cin.get(a,10);//����������ĸ
	cin.get();
    cin.get(b,10);
    for (i = 0; i < 10; i++)//����д��ĸת��ΪСд
    {
        if (a[i] > 'a'|| a[i] == 'a');
        else
            if (a[i] != 0)
                a[i] = a[i] + 32;
            else break;
    }
   for (i = 0; i < 10; i++)
    {
        if (b[i] > 'a'|| b[i] == 'a');
        else
            if (b[i] != 0)
                b[i] = b[i] + 32;
            else break;
    }
    for (i = 0; i < 10; i++)//�����ַ�������ĸ��ֵ����Сֵ
	{	if (a[i] == '\0') break;
	    for(j=0;j<10;j++)
		{   if (b[j] == '\0') break;
		    c=a[i]-b[j];
			if (c < 0) c = 0 - c;
			if (c < numb) numb=c;
		}
	}
	cout<<numb;
	return 0;
	
}