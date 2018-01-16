#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
	int n,count=1;
	while(cin>>n)
	{
		if(n==0)
			break;
		
		int A[n][2];
		cin>>A[0][0]>>A[0][1];
		cin>>A[n-1][0]>>A[n-1][1];
		for(int i=1; i<n-1; i++)
			cin>>A[i][0]>>A[i][1];
			
		double D[n][n];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				D[i][j]= sqrt(pow(A[i][0]-A[j][0], 2) + pow(A[i][1]-A[j][1], 2));
		
		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
                    	D[i][j] = min(D[i][j],max(D[i][k],D[k][j]));
			
		cout<<"Scenario #"<<count++<<endl;
		cout<<"Frog Distance = "<<fixed<<setprecision(3)<<D[0][n-1]<<endl<<endl;
	}
	return 0;
}

