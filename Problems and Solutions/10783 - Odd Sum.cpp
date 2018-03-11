#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int T;
	while(cin>>T)
		for(int i=1; i<=T; i++)
		{
			int a,b, ans;
			cin>>a>>b;
			if(a%2 == 0)
				a++;
			if(b%2 == 0)
				b--;
			ans = ((a + b)*((b-a)/2+1))/2;
			cout<<"Case "<<i<<": "<<ans<<endl;
		}
	return 0;
}
