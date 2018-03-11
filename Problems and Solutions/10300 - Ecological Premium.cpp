#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int i=0; i<T; i++)
	{
		int F;
		cin>>F;
		long long int ans = 0;
		while(F--)
		{
			int a,b,c;
			cin>>a>>b>>c;
			ans += a*c;
		}
		cout<<ans<<endl;
	}
	return 0;
}