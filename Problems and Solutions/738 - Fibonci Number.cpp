#include <iostream>
using namespace std;

int main()
{
	int ans[1001];
	ans[0] = 0;
	ans[1] = 1;
	
	for(int i=2; i<1001; i++)
		ans[i] = (ans[i-1] + ans[i-2]) % 10;
	
	int n;
	while(cin>>n)
	{
		cout<<ans[n]<<endl;
	}
	return 0;
}
