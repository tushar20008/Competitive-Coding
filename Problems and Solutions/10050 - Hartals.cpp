#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int D[3651];
	int T;
	cin>>T;
	while(T--)
	{
		memset(D,1,sizeof(D));
		for(int i=6; i<3651; i += 7)
		{
			D[i] = -1;
			D[i+1] = -1;
		}
		int N, P;
		cin>>N>>P;
		while(P--)
		{
			int temp;
			cin>>temp;
			for(int i=temp; i<=N; i += temp)
				if(D[i] != -1)
					D[i] = 0;
		}
		int loss = 0;
		for(int i=1; i<=N; i++)
			if(D[i] == 0)
				loss++;
		cout<<loss<<endl;
	}
	return 0;
}
