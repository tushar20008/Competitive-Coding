#include <iostream>
using namespace std;

int main()
{
	long long res=0,a,b;
	string s;
	while(cin>>a>>s>>b)
	{
		if(s=="+")
			cout<<a+b<<endl;
		if(s=="-")
			cout<<a-b<<endl;
	}
	return 0;
}
