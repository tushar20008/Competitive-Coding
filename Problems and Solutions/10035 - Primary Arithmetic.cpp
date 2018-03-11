#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string A,B;
	while(cin>>A>>B)
	{
		if(A == "0" && B == "0")
			break;
		int a = A.length();
		int b = B.length();

		int prev = 0, ans = 0;
		while(a != -1 && b != -1)
		{
			if(A[a--] -48 + B[b--] -48 + prev > 9)
			{
				prev = 1;
				ans++;
			}
			else
				prev = 0;
		}
		while(a != -1 && A[a--] - 48 + prev > 9)
			ans++;
		while(b != -1 && B[b--] - 48 + prev > 9)
			ans++;
		if(ans == 0)
			cout<<"No carry operation."<<endl;
		else if(ans == 1)
			cout<<"1 carry operation."<<endl;
		else
			cout<<ans<<" carry operations."<<endl;
	}
	return 0;
}