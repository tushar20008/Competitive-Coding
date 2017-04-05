#include <iostream>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int i=1; i<=T; i++)
	{
		long int a,b,c;
		cin>>a>>b>>c;
		if(a<=0 || b<=0 || c<=0 || a+b<=c || a+c<=b || b+c<=a)
			cout<<"Case "<<i<<": Invalid"<<endl;
		else if(a==b && b==c)
			cout<<"Case "<<i<<": Equilateral"<<endl;
		else if(a==b || a==c || b==c)
			cout<<"Case "<<i<<": Isosceles"<<endl;
		else
			cout<<"Case "<<i<<": Scalene"<<endl;
	}
	return 0;
}
