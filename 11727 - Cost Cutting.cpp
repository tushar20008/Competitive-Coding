#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=1; i<=T; i++)
	{
		int a,b,c,ans;
		cin>>a>>b>>c;
		if((a>b && a<c) || (a<b && a>c))
			ans=a;
		else if((b>a && b<c) || (b<a && b>c))
			ans=b;
		else if((c>a && c<b) || (c<a && c>b))
			ans=c;
		cout<<"Case "<<i<<": "<<ans<<endl;
	}
}
