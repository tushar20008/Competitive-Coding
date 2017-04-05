#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=1; i<=T; i++)
	{
		int n;
		cin>>n;
		string A;
		cin>>A;
		int ans=0;
		for(int j=0; j<A.size(); j++)
		{
			if(A[j]=='.')
			{
				ans++;
				j+=2;
			}
		}
		cout<<"Case "<<i<<": "<<ans<<endl;
	}
}
