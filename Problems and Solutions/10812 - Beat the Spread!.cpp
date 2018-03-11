#include <iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		long s,d;
		cin>>s>>d;
		long a = (s+d)/2;
		long b = s-a;
		if(b<0 || a+b != s || a-b != d)
			cout<<"impossible"<<endl;
		else
			cout<<a<<" "<<b<<endl;
	}
	return 0;
}