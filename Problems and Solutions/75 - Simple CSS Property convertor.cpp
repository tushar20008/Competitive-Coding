#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		string A;
		cin>>A;
		for(int i=0; i<A.size(); i++)
		{
			if(A[i]=='-')
			{
				cout<<(char)(A[++i]-32);
			}
			else
				cout<<A[i];
		}
		cout<<endl;
	}
}
