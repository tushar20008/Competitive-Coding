#include <iostream>
#include <math.h>
using namespace std;

int A[1025][1025];

int main()
{
	int K;
	while(cin>>K)
	{
		int size = pow(2,K), N = size*size;
		
		for(int i=0; i<size; i++)
			for(int j=0; j<size; j++)
			{
				char c;
				cin>>c;
			
				A[i][j] = c;
			}
		
		int ans = 1, r = size, c = size;
		while(true)
		{
			if(r == 1)
				break;
				
			for(int i=0; i<r; i++)
			{
				for(int j=0; j<c; j++)
				{
					int maxV = max(max(max(A[i][j],A[i][j+1]),A[i+1][j]),A[i+1][j+1]);
					int minV = min(min(min(A[i][j],A[i][j+1]),A[i+1][j]),A[i+1][j+1]);
					
					if(maxV == minV && minV != -1)
						A[i/2][j/2] = minV;
					else 
					{
						A[i/2][j/2] = -1;
						ans += 4;
					}
					j++;
				}
				i++;
			}
			r /= 2;
			c /= 2;
		}
		cout<<ans<<endl;
	}
	return 0;
}
