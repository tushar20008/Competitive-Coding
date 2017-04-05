#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;
int main()
{
	int T;
	cin>>T;
	char gar=getchar();
	while(T--)
	{
		char A[10001];
		cin.getline(A,10001);
		float n=strlen(A);
		n=sqrt(n);
		//cout<<n<<endl;
		if(n!=(int)n)
			cout<<"INVALID"<<endl;
		else
		{
			int ind=0,N=n;
			char C[N][N];
			for(int i=0; i<N; i++)
				for(int j=0; j<N; j++)
					C[i][j]=A[ind++];
			for(int i=0; i<N; i++)
				for(int j=0; j<N; j++)
					cout<<C[j][i];
			cout<<endl;
		}
	}
	return 0;
}
