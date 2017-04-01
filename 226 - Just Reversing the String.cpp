#include <iostream>
using namespace std;
int main()
{
	string A;
	while(cin>>A)
	{
		for(int i=A.size()-1; i>=0; i--)
		{
			if(A[i]>='a' && A[i]<='z')
				cout<<(char)(A[i]-32);
			else if(A[i]>='A' && A[i]<='Z')
				cout<<(char)(A[i]+32);
			else
				cout<<A[i];
		}
		cout<<endl;
	}
}
