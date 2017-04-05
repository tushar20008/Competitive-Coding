#include <iostream>
#include <math.h>
#include <cstring>
#include <time.h>
using namespace std;

int n=1000000;
int *B=new int [(n>>6)+1];
 
#define IsComp(n)  (B[n>>6]&(1<<((n>>1)&31)))
#define SetComp(n) (B[n>>6]|=(1<<((n>>1)&31)))
 
void ListPrime() 
{
    for (int i = 3; i*i <= n; i += 2)
        if (!IsComp(i))
            for (int j = i*i; j <= n; j += 2*i)
            	SetComp(j);	
}

bool isPrime(int n) 
{
    if (n < 2 || n % 2 == 0) 
		return false;
    return ! IsComp(n);
}

long p[500] ,count=0;

char isprime(long n)
{
	long i;

	if (n<4) return 1;
	if ((n&1) == 0) return 0; //even

	i=0;
	while(i < count) {
		if(n%(p[i]) == 0) return 0;
		i++;
	}
	if((n-3)/2 < 500) p[count++] = n;
	return 1;
}


int main()
{	
	bool *A= new bool[1000001];
	memset(A,0,sizeof(bool)*1000001);
	memset(p,0,sizeof(p));
	p[count++] = 3; // 3 is prime
	long j=2;
	for(long i=5; i<1000000; i+=2)
		if(isprime(i))
		{
			j++;
			A[i]=1;
		}
	cout<<j<<endl;

	long u=clock();
	ListPrime();
	long v=clock();
	int count=0;
	for(int i=1; i<=n; i++)
		if(isPrime(i))
			count++;
	cout<<count<<endl;
	//cout<<(float) (v-u)/CLOCKS_PER_SEC<<endl;
	for(int i=0; i<5; i++)
	{
		for(int j=0; j<5; j++)
		{
			cout<<i<<" "<<j<<endl;
			if(j==2)
				break;		
		}	
		if(cin.peek()==break)
			continue;
	}
	int n,m;
	while(cin>>n)
	{
		if(n==-1)
			break;
		cin>>m;
		int tot=0;
		//long u = clock();
		for(int i=n; i<=m; i++)
		{
			//if(A[i]==0)
			if(isPrime(i)==false)
				continue;
			int temp=i, size=0;
			bool iscircular=true;
			while(temp>0)
			{
				size++;
				temp/=10;	
			}	
			temp=i;
			//cout<<size<<endl;
			for(int j=0; j<size-1; j++)
			{
				//cout<<temp/10<<" + "<<(temp%10)<<" * "<<pow(10,size-1)<<endl;
				temp=temp/10 + (temp%10)*pow(10,size-1);
				//cout<<temp<<endl;
				if(isPrime(temp)==false)
				//if(A[temp]==0)
				{
					iscircular=false;
					break;
				}	
			}
			if(iscircular)
				tot++;
		}
		//long v = clock();
		//cout<<(float) (v-u)/CLOCKS_PER_SEC<<endl;
		if(tot==0)
			cout<<"No Circular Primes."<<endl;
		else if(tot==1)
			cout<<"1 Circular Prime."<<endl;
		else
			cout<<tot <<" Circular Primes."<<endl;
	}
}
