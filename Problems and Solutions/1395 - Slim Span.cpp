#include <iostream>
#include <cstring>
#include <climits>
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
	int n,m;
	while(cin>>n>>m)
	{
		if(n==00 && m==0)
			break;
			
		memset(A,-1,sizeof(A)); 
			
		int D[m][3];
		for(int i=0; i<m; i++)
			cin>>D[i][0]>>D[i][1]>>D[i][2];
			
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
	
		int slim=INT_MAX;
		bool Has=false;
		for(int i=0; i<=m; i++)
		{
			int edge=0, max_w=INT_MAX,min_w=INT_MAX;
			memset(A,-1,sizeof(A));
			
			for(int j=i; j<m; j++)		
				if(Union(D[j][0],D[j][1]))
				{
					if(max_w==INT_MAX)
						max_w=D[j][2];
					else
						max_w=max(max_w,D[j][2]);
					if(min_w==INT_MAX)
						min_w=D[j][2];
					else
						min_w=min(min_w,D[j][2]);
					edge++;
				}
			
			if(edge==n-1)
			{
				if(slim==INT_MAX)
					slim=max_w-min_w;
				else
					slim=min(slim,max_w-min_w);
				Has=true;
			}
		}
		if(Has)
			cout<<slim<<endl;
		else
			cout<<-1<<endl;
	}
}
