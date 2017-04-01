#include <iostream>
using namespace std;
int main()
{
	string A;
	while(cin>>A)
	{
		int H=0;
		for(int i=0; i<A.size(); i++)
			if(A[i]=='8')
				H+=2;
			else if(A[i]=='0' || A[i]=='4' || A[i]=='6' || A[i]=='9')
				H++;
		cout<<H<<endl;
	}
}
