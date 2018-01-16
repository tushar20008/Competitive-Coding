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
	//cout<<"		->"<<n<<endl;
	if(n==2)
		return true;
    if (n < 2 || n % 2 == 0) 
		return false;
    return ! IsComp(n);
}


int main()
{
	ListPrime();
	int A;
	while(cin>>A)
	{
		if(A == 0)
			break;
			
		if(isPrime(A))
			cout<<0<<endl;
		else
		{
			int count = 1;
			
			for(int i=A; i<1299709; i++)
				if(!isPrime(i))
					count++;
				else
					break;
			
			for(int i=A-1; i>0; i--)
				if(!isPrime(i))
					count++;
				else
					break;
			
			cout<<count<<endl;
		}
	}
	return 0;
}
