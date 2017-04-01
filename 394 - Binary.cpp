#include<iostream>
using namespace std;

void Binary(int  x)
{
	if(x==0)
	{
		cout<<0;
		return;
	}
	if(x==1)
	{
		cout<<1;
		return;	
	}
	Binary(x/2);
	cout<<x%2;
}
 
int main()
{
	int x;
	while(cin>>x)
	{
		Binary(x);
		cout<<endl;
	}
	return 0;
}
