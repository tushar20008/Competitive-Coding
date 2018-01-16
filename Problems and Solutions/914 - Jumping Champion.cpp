#include <iostream>
#include <cstring>
#include <time.h>
#include <math.h>
#include <bitset>
using namespace std;

const int n = 1000000;
const int LIMIT = sqrt(n)+1;
bool prime[n];
	void sieve() {
		memset(prime,1,sizeof(prime));
		prime[1]=0;
		for(int i=3;i<=LIMIT;i+=2) {
			if (prime[i])
				for (int j = i*i; j <= n; j += 2*i)
					prime[j]=0;
		}
	}
bool isPrime(int n) 
{
	if(n==2)
		return true;
    if (n < 2 || n % 2 == 0) 
		return false;
    return prime[n];
}

int main()
{
	sieve();
	int T;
	cin>>T;
	while(T--)
	{
		int *A = new int[1000000];
		int ind=0;
		int L,U;
		cin>>L>>U;
		int prev=-1;
		for(int i=L; i<=U; i++)
		{
			if(isPrime(i))
			{
				if(prev==-1)
					prev=i;
				else
				{
					//cout<<i<<" "<<prev<<endl;
					A[ind++]=i-prev;
					prev=i;
				}
			}
		}
		if(ind==0)
			cout<<"No jumping champion"<<endl;
		else
		{
			int *B = new int[1000000];
			memset(B,0,sizeof(int)*1000000);
			for(int i=0; i<ind; i++)
			{
				B[A[i]]++;
				//cout<<A[i]<<" "<<B[A[i]]<<endl;
			}	
			int ans=0, freq=0, same=0;
			for(int i=0; i<1000000; i++)
				if(B[i]>freq)
				{
					freq=B[i];
					ans=i;
				}
				else if(freq==B[i])
					same=freq;	
			/*
			for(int i=0; i<ind; i++)			
				for(int j=0; j<ind-1; j++)
					if(A[j]>A[j+1])
					{
						int temp=A[j];
						A[j]=A[j+1];
						A[j+1]=temp;
					}
			int ans=0, freq=0, Prev=A[0], count=1;
			//cout<<Prev<<" ";
			for(int i=1; i<ind; i++)
			{
				//cout<<A[i]<<" ";
				if(Prev==A[i])
					count++;
				else
				{
					if(count>freq)
					{
						ans=Prev;
						freq=count;
						Prev=A[i];
						count=1;
					}
				}
			}
			//cout<<endl;
			*/
			if(freq==same)
				cout<<"No jumping champion"<<endl;
			else
				cout<<"The jumping champion is "<<ans<<endl;
		}
	}
}


