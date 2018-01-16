#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int gcd(int p, int q, int *x, int *y)
{
	if (p == 0)
	{
		*x = 0;
		*y = 1;
		return q;
	}

	int x1, y1; 
	int g = gcd(q%p, p, &x1, &y1);

	*x = y1 - (q/p) * x1;
	*y = x1;

	return g;
}
int BtoD(char A[])
{
	int m=0, p=0;
	for(int i=strlen(A)-1; i>=0; i--)
	{
		if(A[i]=='1')
			m+=pow(2,p);
		p++;
	}
	return m;
}
int main()
{
	int T;
	cin>>T;
	for(int i=1; i<=T; i++)
	{
		char A[50],B[50];
		cin>>A>>B;
		int a,b,G, X,Y;
		a=BtoD(A);
		b=BtoD(B);
		G=gcd(a,b,&X,&Y);
		//cout<<a<<" "<<b<<" "<<G<<endl;
		if(G!=1)
			cout<<"Pair #"<<i<<": All you need is love!"<<endl;
		else
			cout<<"Pair #"<<i<<": Love is not all you need!"<<endl;
	}
	return 0;
}
