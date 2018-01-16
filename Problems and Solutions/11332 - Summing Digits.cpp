#include <iostream>
using namespace std;
int main()
{
	int N;
	while(cin>>N)
	{
		if(N==0)
			break;
		int sum=N;
		while(sum>9)
		{
			N=sum;
			sum=0;
			//cout<<N<<" "<<sum<<endl;
			while(N!=0)
			{
				sum+=N%10;
				N=N/10;
			}
		}
		cout<<sum<<endl;
	}
}
