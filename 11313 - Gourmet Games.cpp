#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		n--;
		m--;
		if(n%m==0)
			cout<<n/m<<endl;
		else
			cout<<"cannot do this"<<endl;
	}
	return 0;
}
