#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int N;
	while(cin>>N)
	{
		if(N==0)
			break;
		int A[101];
		memset(A,0,sizeof(A));
		for(int i=0; i<N; i++)
		{
			int temp;
			cin>>temp;
			A[temp]++;
		}
		for(int i=0; i<101; i++)
			if(A[i]!=0)
			{
				cout<<i;
				A[i]--;
				if(A[i] != 0)
					i--;
				N--;
				if(N!=0)
					cout<<" ";
			}
		cout<<endl;
	}
	return 0;
}