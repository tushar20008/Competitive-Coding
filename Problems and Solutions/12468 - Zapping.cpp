#include <iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(a==b && a==-1)
			break;
		if(a>b)
		{
			int tmp=a;
			a=b;
			b=tmp;
		}
		cout<<min(b-a,100-(b-a))<<endl;
	}
}
