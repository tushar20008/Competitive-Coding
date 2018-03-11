#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int main()
{
	int a,b;
	bool A[100001];
	memset(A,0,sizeof(A));
	for(int i=0; i*i<100001; i++)
		A[i*i] = true;
	while(cin>>a>>b)
	{
		if(a == 0 && b == 0)
			break;
		int ans = 0;
		for(int i=a; i<=b; i++)
			if(A[i])
				ans++;
		cout<<ans<<endl;
	}
	return 0;
}