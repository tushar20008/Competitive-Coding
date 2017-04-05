#include <iostream>

using namespace std;  //not working

int main()
{
	int k,n,s,d,box;
	
	while(cin>>k>>n>>d>>s)
	{
		box=0;
		
		while((d>=k-1) && n>0)
		{
			n=n-(s*k);
			box++;
			d=d-(k-1);
		}
		
		while(n>0)
		{
			n=n-(s*(d+1));
			box++;
			d=0;
		}
		
		cout<<box<<endl;
	}
	
	return 0;
}
