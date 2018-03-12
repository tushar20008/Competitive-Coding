#include <iostream>
#include <cstring>
using namespace std;

bool isRight(int a, int b, int c)
{
	if(a*a + b*b == c*c)
		return true;
	if(a*a + c*c == b*b)
		return true;
	if(b*b + c*c == a*a)
		return true;
	return false;
}

int main()
{
	int a,b,c;
	while(cin>>a>>b>>c)
	{
		if(a == 0 && b == 0 && c == 0)
			break;
		if(isRight(a,b,c))
			cout<<"right"<<endl;
		else
			cout<<"wrong"<<endl;
	}
	return 0;
}