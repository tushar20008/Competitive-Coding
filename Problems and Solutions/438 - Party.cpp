#include <iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a;
		cin>>a;
		if(a>1)
			cout<<a-2<<endl;
		else
			cout<<0<<endl;
	}
	return 0;
}
