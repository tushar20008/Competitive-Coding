#include <iostream>
using namespace std;
int main()
{
	string A;
	while(cin>>A)
	{
		bool Z=true,Y=true;
		int size=A.size(), x=0,y=0,z=0;
		for(int i=size-1; i>=0; i--)
		{
			if(A[i]=='+')
				Y=false;
			else if(A[i]=='=')
				Z=false;
			else if(Z)
				z=z*10+A[i]-48;
			else if(Y)
				y=y*10+A[i]-48;
			else
				x=x*10+A[i]-48;
		}
		//cout<<x<<" "<<y<<" "<<z<<endl;
		if(x+y==z)
			cout<<"True"<<endl;
		else
			cout<<"False"<<endl;
		if(x==0 && y==0 && z==0)
			break;
	}
	return 0;
}
