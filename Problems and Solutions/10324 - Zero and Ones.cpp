#include <iostream>
using namespace std;
int main()
{
	string A;
	int T=1;
	while(cin>>A)
	{
		int n;
		cin>>n;
		cout<<"Case "<<T++<<":"<<endl;
		for(int i=1; i<=n; i++)
		{
			int a,b;
			cin>>a>>b;
			if(a>b)
			{
				int tmp=a;
				a=b;
				b=tmp;
			}
			bool same=true;
			char c=A[a];
			for(int j=a+1; j<=b; j++)
				if(A[j]!=c)
				{
					same=false;
					break;
				}	
			if(same)
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
	}
}
