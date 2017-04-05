#include <iostream>
#include <cstring>   
#include <math.h>
using namespace std;


int Ways(int n, int m, int len)
{
    int *T=new int[1000000 + 10];
    memset(T, 0 , sizeof(int)*1000010);
    T[0] = 1;
    for(int i=0; i<len; i++)
        for(int j=1; j<=m; j++)
            if( pow(n,i) <= j)
                T[j] =(T[j] + T[j- (int)pow(n,i)]) % 1000000007;
    
    int total=T[m];
    delete T;
    return total;
}  

int main()
{
	int m,n;
	while(cin>>m>>n)
	{
		int i;
		for(i=0; pow(n,i)<=m; i++)
		{
		}
		cout<<Ways(n,m,i)<<endl;
	}
	return 0;
}
