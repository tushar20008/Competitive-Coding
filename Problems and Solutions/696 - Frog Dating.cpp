#include <iostream>
#include <math.h>
using namespace std;

long int gcd(long int p, long int q, long int *x, long int *y)
{
	if (p == 0)
	{
		*x = 0;
		*y = 1;
		return q;
	}

	long int x1, y1; 
	long int g = gcd(q%p, p, &x1, &y1);

	*x = y1 - (q/p) * x1;
	*y = x1;

	return g;
	/*
	int x1,y1,g;
	if(q>p)
		return gcd(q,p,y,x);
	if(q==0)
	{
		*x=1,*y=0;
		return p;
	}
	g=gcd(p,p%q,&x1,&y1);
	*x=x1;
	*y=x1 -floor(p/q)*y1;
	return g;
	*/
}
int main()
{
	long int x,y,m,n,L;
	while(cin>>x>>y>>m>>n>>L)
	{
		long int A=n-m;		// Ax=B(mod L)
		long int B=x-y;
		if(B<0 && A<0)
		{
			B=-B;
			A=-A;
		}
		//int B=(x-y)%L;			
		//if(B<0)
		//	B=L+B;
		long int X,Y;
		long int G=0;
		while(G!=1)
		{
			G=gcd(abs(A),abs(B),&X,&Y);
			G=gcd(L,G,&X,&Y);
			//cout<<A<<" "<<B<<" "<<G<<endl;
			A/=G;
			B/=G;
			L/=G;	
		}
		G=gcd(A,L,&X,&Y);
		//cout<<"A = "<<A<<" , L = "<<L<<" , X = "<<X<<" , Y = "<<Y<<"	, G = "<<G<<endl;
		//cout<<"B = "<<B<<endl;
		if(B%G==0)// Ax = B mod L. Let G = gcd(A, L). If G does not divide B, the congruence has no solution.
		{
			int ans=(X*(B/G))%L;	// If A and B are positive
			if(ans>0)
				cout<<ans<<endl;
			else
				cout<<ans+L<<endl;	
		}
		else
			cout<<"Impossible"<<endl;
	}
	return 420;
}
