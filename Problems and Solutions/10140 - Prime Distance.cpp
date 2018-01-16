#include <iostream>
#include <cstring>
#include <climits>
#include <math.h>
using namespace std;
int n=100000000;
int *A=new int [(n>>6)+1];
int *B=new int[100000000], c=0;
#define IsComp(n)  (A[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) (A[n>>6]|=(1<<((n>>1)&31)))

bool isPrime(int n) 
{
	if(n<100000000)
	{
		if(n==2)
			return true;
    	if (n < 2 || n % 2 == 0) 
			return false;
    	return ! IsComp(n);
	}
	else
	{
		for(int i = 0; i <c && B[i] <= sqrt(n); i++)
        	if(n%B[i] == 0)
            	return 0;
    	return 1;
	}
}
 
void ListPrime() 
{
    for (int i = 3; i*i <= n; i += 2)
        if (!IsComp(i))
            for (int j = i*i; j <= n; j += 2*i)
            	SetComp(j);
	for(int i=2; i<n; i++)
		if(isPrime(i))
			B[c++]=i;
}

int main()
{
	ListPrime();
	//cout<<c<<endl;
	int L,U;
	while(cin>>L>>U)
	{
		int prev = -1, p1, p2, p3, p4;
        bool found = false;
        int close = INT_MAX, dist = INT_MIN;
		for(long long i=L; i<=U; i++)
		{
			if(isPrime(i))
			{
				if(prev==-1)
					prev=i;
				else
				{
					if(i-prev < close) 
					{
                        close = i-prev;
                        p1 = prev;
						p2 = i;
                    }
                    if(i-prev > dist) 
					{
                        dist = i-prev;
                        p3 = prev, p4 = i;
                    }
                    prev = i;
                    found = true;
				}	
			}	
		}
		if(!found)
        	cout<<"There are no adjacent primes."<<endl;
        else 
            cout<<p1<<","<<p2<<" are closest, "<<p3<<","<<p4<<" are most distant."<<endl;
	}
	return 0;
}

