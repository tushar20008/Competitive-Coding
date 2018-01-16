#include <iostream>
using namespace std;
int n=100000000;
int *A=new int [(n>>6)+1];
 
#define IsComp(n)  (A[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) (A[n>>6]|=(1<<((n>>1)&31)))
 
void ListPrime() 
{
    for (int i = 3; i*i <= n; i += 2)
        if (!IsComp(i))
            for (int j = i*i; j <= n; j += 2*i)
            	SetComp(j);	
}

bool isPrime(int n) 
{
	if(n==2)
		return true;
    if (n < 2 || n % 2 == 0) 
		return false;
    return ! IsComp(n);
}

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	ListPrime();
	int T;
	while (cin>>T)
	{
		int p1,p2;
		bool sum=false;
		if(T%2!=0)		// IF ODD- Even+Odd
		{
			if(isPrime(T-2))
			{
				p1=2;
				p2=T-2;
				sum=true;	
			}
		}	
		else			// IF Even- Odd+Odd
		{
			int Minus=0;
			if(T/2 %2 == 0)
				Minus=1;
			
			for(int i=T/2 - Minus; i>0; i-=2)
			{
				if(i==T-i)
					continue;
				if(i>T-i)
					break;
				if(isPrime(i) && isPrime(T-i))
				{
					p1=i;
					p2=T-i;
					sum=true;
					break;
				}
			}	
		}
		if(sum)
			cout<<T<<" is the sum of "<<p1<<" and "<<p2<<"."<<endl;
		else
			cout<<T<<" is not the sum of two primes!"<<endl;
	}
}
