#include <iostream>
#include <cstring>
using namespace std;
int A[101];
int Find (int element)  
{
	if (A[element] < 0)
		return element;
	else
		return A[element]=Find(A[element]);
}

void UnionSet (int set1, int set2) 
{
	A[set1] += A[set2]; 
	A[set2] = set1;     
}

bool Union (int a, int b) 
{
	int root1=Find(a);
	int root2=Find(b);
	//cout<<root1<<" "<<root2<<endl;
	if(root1 == root2)
		return false;
	else if  (A[root1] <= A[root2]) 		
		UnionSet(root1, root2);
	else
		UnionSet(root2, root1);
	
	return true;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		memset(A,-1,sizeof(A)); 
			
		int D[m][3];
		for(int i=0; i<m; i++)
			cin>>D[i][0]>>D[i][1]>>D[i][2];
			
		int cost1=0;
		
		for(int i=1; i<m; i++)
			for(int j=m-1; j>=i; j--)
				if(D[j-1][2]>D[j][2])
				{
					int t0=D[j-1][0], t1=D[j-1][1], t2=D[j-1][2];
					D[j-1][0]=D[j][0];
					D[j-1][1]=D[j][1];
					D[j-1][2]=D[j][2];
					D[j][0]=t0;
					D[j][1]=t1;
					D[j][2]=t2;
				}
	
		bool M1[m];
		memset(M1,0,sizeof(M1));
		
		for(int i=0; i<m; i++)
			if(Union(D[i][0],D[i][1]))
			{
				cost1+=D[i][2];
				M1[i]=true;
			}	
				
		int cost2=0;
		for(int i=0; i<m; i++)
		{
			int edge=0,local_cost=0;
			bool M2[m];
			memset(M2,0,sizeof(M2));
			memset(A,-1,sizeof(A));
			
			for(int j=0; j<m; j++)		
				if(j!=i && Union(D[j][0],D[j][1]))
				{
					local_cost+=D[j][2];
					edge++;
					M2[j]=true;
				}
			
			for(int k=0; k<m; k++)
				if(M1[k]!=M2[k])
				{
					if(edge==n-1)
					{
						if(cost2==0)
							cost2=local_cost;
						else
							cost2=min(cost2,local_cost);
					}
					break;
				}		
		}
		cout<<cost1<<" "<<cost2<<endl;
	}
}
