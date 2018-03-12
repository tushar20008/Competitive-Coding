#include <iostream>
using namespace std;

int main()
{
	int N, B, H, W;
	while(cin>>N>>B>>H>>W)
	{
		int cost = B+1;
		for(int i=0; i<H; i++)
		{
			int rent;
			cin>>rent;
			for(int j=0; j<W; j++)
			{
				int beds;
				cin>>beds;
				if(beds>=N && cost > rent*N)
					cost = rent*N;
			}
		}
		if(cost > B)
			cout<<"stay home"<<endl;
		else
			cout<<cost<<endl;
	}
	return 0;
}