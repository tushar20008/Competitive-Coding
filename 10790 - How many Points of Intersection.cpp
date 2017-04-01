#include<iostream>
using namespace std;
int main()
{
	long long T=1, a,b;
	long long ans;
	while(cin>>a>>b)
	{
		if(a==b && a==0)
			break;
		ans=(a*b*(a-1)*(b-1))/4;
		cout<<"Case "<<T++<<": "<<ans<<endl;
	}
}
