#include <iostream>
using namespace std;
int main()
{
	long long L,U;
	while(cin>>L>>U)
	{
		if(L==0 && U==0)
			break;
		if(L>U)
		{
			long long temp=U;
			U=L;
			L=temp;
		}
		long long V=0, S=0;
		for(long long i=L; i<=U; i++)
		{
			long long count=1, T=i;
			if(T%2==0)
				T=T/2;
			else
				T=3*T+1;
			while(T!=1)
			{
				count++;
				if(T%2==0)
					T=T/2;
				else
					T=T*3+1;
			}
			if(count>S)
			{
				V=i;
				S=count;
			}
		}
		cout<<"Between "<<L<<" and "<<U<<", "<<V<<" generates the longest sequence of "<<S<<" values."<<endl;
	}
}
