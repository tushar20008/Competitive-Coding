#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		string A[n];
		int p=0;
		for(int i=0; i<n; i++)
		{
			cin>>A[i];
			if(A[i]=="SAME")
			{
				cin>>A[i];
				int tmp;
				cin>>tmp;
				A[i]=A[tmp-1];
			}
			if(A[i]=="LEFT")
				p--;
			else if(A[i]=="RIGHT")
				p++;
			//cout<<p<<endl;
		}
		cout<<p<<endl;
	}
}
