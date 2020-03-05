//简单八皇后问题，已知其余七个皇后的正确位置，求最后一个皇后的位置
#include <iostream> 
using namespace std;
int main()
{
	char a[8]; int b[8][8], c[8], line, lie;
	//输入已知皇后的位置
	for ( line  =  0; line < 8; line++)
		cin>>a[line];

	for ( line = 0; line < 8; line++)
	{   if ( a[line] !=  '*' )
		   c[line]  =  a[line]-'0';
	    else
			c[line]  =  0;
	}
	//判断最后一个皇后的位置
	for ( line = 0; line < 8; line++)
		for( lie = 0; lie < 8; lie++)
			b[line][lie] = 1;

	for ( line = 0; line < 8; line++ )
	{
		if ( c[line] != 0)
		{   int j;
			for ( j = 0; j < 8; j++)
				b[line][j] = 0;

			for ( j = 0; j < 8; j++)
				b[j][c[line]-1] = 0;

			int k = c[line] - 1, q = line;
			if ( q > k) q = q - k, k = 0; 
			else k = k - q, q = 0; 
			for ( j = q; j < 8; j++)
			    b[j][k] = 0,k++;

			k = c[line] - 1, q = line;
			if ( line < 7 - q ) q = 0, k = k + q; 
			else k = 0, q = q - ( 7 - q );
			for ( j = q; j > 0 && k > 0; j++)
				b[j][k] = 0,k--;
		}
		else ;
	}

	int n = 0;
	for( line = 0; line < 8; line++)
		for( lie = 0; lie < 8; lie++)
		{
			if ( b[line][lie] == 1) n = lie + 1;
		}
	if ( n == 0) 
		cout << "No Answer";
	else 
		cout << n;

	return 0;
	
}