#include <iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int i=1; i<=T; i++)
	{
		int N;
		cin>>N;
		int speed = 0;
		while(N--)
		{
			int temp;
			cin>>temp;
			if(temp > speed)
				speed = temp;
		}
		cout<<"Case "<<i<<": "<<speed<<endl;
	}
	return 0;
}