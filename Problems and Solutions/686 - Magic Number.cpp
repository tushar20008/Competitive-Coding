#include <iostream>
using namespace std;
int main()
{
	string A;
	while(cin>>A)
	{
		bool one=false;
		int four=0;
		for(int i=0; i<A.size(); i++)
		{
			if(A[i]=='1')
			{
				one=true;
				four=0;
			}
			else if(A[i]=='4' && one && four<2)
			{
				four++;
			}
			else
			{
				cout<<"NO"<<endl;
				break;
			}
			if(i==A.size()-1)
				cout<<"YES"<<endl;
		}
	}
	return 0;
}
