#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		int cow=0;
		int R[n][n];
		memset(R,0,sizeof(R));
		for(int i=0; i<n; i++)
			R[i][i]=1;
			
		int i,j;
		
		while(m--)
		{
			cin>>i>>j;
			R[--i][--j]=1;
		}
		
		for (int k = 0; k < n; k++)
        	for (i = 0; i < n; i++)
    	    	for (j = 0; j < n; j++)
                	R[i][j] = R[i][j] || (R[i][k] && R[k][j]);
    /*        			
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
			cout<<R[i][j]<<" ";
		cout<<endl;
	}	
	*/		
		for (int i = 0; i < n; i++)
    	{	
			bool temp = true;
			for (int j = 0; j <n; j++)
	    		if (!R [i][j] && !R [j][i])
	    		{
					temp = false;
					break;
	    		}
		
			if (temp)
	    	cow++;
		}
		cout<<cow<<endl;
	}
}
