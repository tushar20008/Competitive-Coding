#include <iostream>
#include <cstring>
using namespace std;

int A[101][101];

void FW(int n)
{
	int D[n][n];
	for(int i=0; i<n; i++)
		for(int j=0; j<n; j++)
			D[i][j]=A[i][j];
			
	for(int k=0; k<n; k++)
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				if (D[i][k] + D[k][j] < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
    /*               
	for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)	
				cout<<D[i][j]<<" ";
			cout<<endl;
		}
	*/
	int cap=1;
	int SP=1000000 * 100;
	
	for(int i=0; i<n; i++)
	{
		int dis=0;
		for(int j=i+1; j<n; j++)
			dis+=D[i][j];
		
		for(int j=i-1; j>-1; j--)
			dis+=D[j][i];
		
		//cout<<i+1<<" "<<dis<<endl;
		if(dis<SP)
		{
			cap=i+1;
			SP=dis;
		}
	}
	cout<<cap<<endl;
}

int main()
{
	int n;
	while(cin>>n)
	{
		int m;
		cin>>m;
		
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)	
				A[i][j]=1000000 * 100;
		}
		for(int i=0; i<n; i++)
			A[i][i]=0;
			
		while(m--)
		{
			int i,j,dis;
			cin>>i>>j>>dis;
			A[i-1][j-1]=dis;
			A[j-1][i-1]=dis;
		}
		/*
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)	
				cout<<A[i][j]<<" ";
			cout<<endl;
		}
		*/
		FW(n);
	}
}
/*
10 16
1 7 8
1 8 4
2 4 3
2 5 3
2 6 3
3 6 5
3 8 5
3 9 8
4 6 6
4 9 10
4 10 8
5 7 10
6 9 9
7 8 1
8 9 10
8 10 5
*/
