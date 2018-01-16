#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	string A;
	while(cin>>A)
	{
		int ind=0;
		if(A[0]=='-')
		{
			cout<<"-";
			ind++;
		}
		int size=A.size();
		int ans=0, p=0;
		for(int i=size-1; i>=ind; i--)
		{
			if(A[i]>='0' && A[i]<='9')
				ans+=(A[i]-48)*pow(16,p);
			if(A[i]>='A' && A[i]<='F')
				ans+=(A[i]-55)*pow(16,p);
			p++;
		}
		cout<<ans<<endl;	
	}
}
