#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int A[1025][1025], B[12][1025*1025], counter;

void store(int x1, int y1, int x2, int y2)
{
	if(x2 - x1 == 2 && y2 - y1 == 2)
	{
		B[0][counter] = A[x1][y1];
		A[x1][y1] = counter++;
		B[0][counter] = A[x1][y1+1];
		A[x1][y1+1] = counter++;
		B[0][counter] = A[x1+1][y1];
		A[x1+1][y1] = counter++;
		B[0][counter] = A[x1+1][y1+1];
		A[x1+1][y1+1] = counter++;
	}
	else
	{
		store(x1,y1, (x1+x2)/2, (y1+y2)/2);
		store(x1, (y1+y2)/2, (x1+x2)/2, y2);
		store((x1+x2)/2,y1, x2, (y1+y2)/2);
		store((x1+x2)/2,(y1+y2)/2, x2,y2);
	}
}

int main()
{
	int T1;
	cin>>T1;
	
	while(T1--)
	{
		int K;
		cin>>K;
		
		int size = pow(2,K);
		
		for(int i=0; i<size; i++)
			for(int j=0; j<size; j++)
			{
				char c;
				cin>>c;
			
				A[i][j] = c-48;
			}
		
		int C[12];
		long long int ans = 1;
		memset(C,0,sizeof(C));
		counter = 0;
		if(size == 1)
			B[0][C[0]++] = A[0][0];
		else
		{
			store(0,0,size,size);
			C[0] = counter;
			
			for(int i=1; i<12; i++)
			{	
				for(int j=0; j<C[i-1]; j++)
				{
					if(B[i-1][j] == B[i-1][j+1] && B[i-1][j] == B[i-1][j+2] && B[i-1][j] == B[i-1][j+3] && B[i-1][j] != -1)
						B[i][C[i]++] = B[i-1][j];
					else
					{
						B[i][C[i]++] = -1;
						ans += 4;	
					}
					j +=3;
				}	
				if(C[i] == 1)
					break;
			}
		}
				
		int T2;
		cin>>T2;
		
		while(T2--)
		{
			int r,c;
			cin>>r>>c;
			r--;
			c--;
				
			int I = A[r][c];//(size/2)*4*(r/2) + (c/2)*4 + c%2 + 2*(r%2);
			long long int newV, newAns = ans;
			if(B[0][I] == 1)
				newV = 0;
			else
				newV = 1;
			 
			for(int i=0; i<12; i++)
			{
				if(C[i] == 1)
					break;
				
				//cout<<i<<"	:	"<<I<<endl;
				//cout<<"New V	:	"<<newV<<endl;
				//cout<<"Old V	:	"<<B[i][I]<<endl;
				
				if(B[i][I] == newV)
					break;
					
				int newLower = I - I % 4;
				if(B[i][newLower] == B[i][newLower+1] && B[i][newLower] == B[i][newLower+2] && B[i][newLower] == B[i][newLower+3])
				{
					//cout<<"OLD IS GOLD"<<endl;
					if(B[i][newLower] != -1)
						newAns += 4;
					B[i][I] = newV;
					newV = -1;
				}	
				else
				{
					B[i][I] = newV;
					if(B[i][newLower] == B[i][newLower+1] && B[i][newLower] == B[i][newLower+2] && B[i][newLower] == B[i][newLower+3])
					{
						//cout<<"Apparently Not"<<endl;
						if(newV != -1)
							newAns -= 4;
					}
					else
						newV = -1;
				}
					
				I /= 4;
			}
			
			ans = newAns;
			cout<<newAns<<endl;	
		}
	}
	return 0;
}
