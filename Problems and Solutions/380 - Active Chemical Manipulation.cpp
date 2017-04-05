#include <iostream>
#include <iomanip>
using namespace std;
int main ()
{
	int n;
	while(cin>>n)
	{
		int D[n][n];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin>>D[i][j];
		
		for(int k=0; k<n; k++)
			for(int i=0; i<n; i++)
				for(int j=0; j<n; j++)
					if (D[i][k] + D[k][j] < D[i][j])
                    	D[i][j] = D[i][k] + D[k][j];
		
		for(int i=0; i<n; i++)
		for(int k=0; k<n; k++)
			for(int j=0; j<n-1; j++)
			{
				if(D[i][j]<D[i][j+1])
				{
					int temp=D[i][j];
					D[i][j]=D[i][j+1];
					D[i][j+1]=temp;
				}
			}
		if(n%2!=0)
			for(int i=0; i<n; i++)
				cout<<D[i][n/2]<<endl;
		else
			for(int i=0; i<n; i++)
			{
				double ans=D[i][n/2]+D[i][(n/2)-1];
				cout<<ans/2<<endl;			
			}
	}
}
