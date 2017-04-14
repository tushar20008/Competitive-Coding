#include <iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	
	for(int i=1; i<=T; i++)
	{
		int N, M, C;
		cin	>>	N	>>	M	>>	C;
		
		int Seats = N*(M-1);
		
		int B[C][2];
		for(int j=0; j<2; j++)
			for(int k=0; k<C; k++)
				cin>>B[k][j];
		
		for(int j=0; j<C; j++)
			for(int k=C-1; k>=1; k--)
				if(B[k-1][0]>B[k][0] || (B[k-1][0] == B[k][0] && B[k-1][1]>B[k][1]))
				{
					int t0=B[k-1][0], t1=B[k-1][1];
					B[k-1][0]=B[k][0];
					B[k-1][1]=B[k][1];
					B[k][0]=t0;
					B[k][1]=t1;
				}
		
		for(int j=0; j<C; j++)
		{
			if(B[j][1] == 1 || B[j][1] == M)
				Seats--;
			else
				Seats -=2;
			
			if(j == C-1)
				continue;
				
			if(B[j][0] == B[j+1][0] && B[j][1]+1 == B[j+1][1])
				Seats++;
		}
		
		cout<<"Case #"<<i<<": "<<Seats<<endl;		
	}
	return 0;
}
