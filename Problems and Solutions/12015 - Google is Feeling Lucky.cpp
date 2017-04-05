#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=1; i<=T; i++)
	{
		string A[11];
		int R[11];
		int F=-1;
		for(int j=0; j<10; j++)
		{
			cin>>A[j]>>R[j];
			if(F==-1)
				F=R[j];
			else if(F<R[j])
				F=R[j];
		}
		cout<<"Case #"<<i<<":"<<endl;
		for(int j=0; j<10; j++)
			if(R[j]==F)
				cout<<A[j]<<endl;
	}
}
