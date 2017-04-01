#include <iostream>
using namespace std;
int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		int odd=0;
		for(int i=a; i<=b; i++)
			if(i%2==1 || i%2==-1)
				odd++;
		cout<<odd<<endl;
	}
}
