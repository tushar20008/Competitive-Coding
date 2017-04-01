#include <iostream>
#include <cstring>
using namespace std;
int A[55];
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
	int n;
	while(cin>>n)
	{
		if(n==0)
			break;
		
		int C[n][n];
		for(int i=0; i<n; i++)
		{
			char c;
			for(int j=0; j<n; j++)
			{
				cin>>c;
				C[i][j]=c-48;
			}
		}	
		
		int B[n][n];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin>>B[i][j];
		int D[n][n];
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin>>D[i][j];
		
		memset(A,-1,sizeof(A));
		
		int cost=0;
		
		int Des[n*n][3], index=0;
		for(int i=0; i<n; i++)
			for(int j=i; j<n; j++)
				if(C[i][j])
				{
					Des[index][0]=i;
					Des[index][1]=j;
					Des[index++][2]=-D[i][j];
					//cout<<i+1<<" -> "<<j+1<<" D-> "<<D[i][j]<<endl;
				}
		for(int i=1; i<index; i++)
			for(int j=index-1; j>=i; j--)
				if(Des[j-1][2]>Des[j][2])
				{
					int t0=Des[j-1][0], t1=Des[j-1][1], t2=Des[j-1][2];
					Des[j-1][0]=Des[j][0];
					Des[j-1][1]=Des[j][1];
					Des[j-1][2]=Des[j][2];
					Des[j][0]=t0;
					Des[j][1]=t1;
					Des[j][2]=t2;
				}
		for(int i=0; i<index; i++)
			if(!Union(Des[i][0],Des[i][1]))
				{
					//cout<<Des[i][0]+1<<" - (D) > "<<Des[i][1]+1<<" = "<<Des[i][2]<<endl;
					cost+=-Des[i][2];	
				}
		//cout<<cost<<endl;
		int R[n*n][3];
		index=0;		
		for(int i=0; i<n; i++)
			for(int j=i; j<n; j++)
				if(i!=j)
				{
					R[index][0]=i;
					R[index][1]=j;
					R[index++][2]=B[i][j];
					//cout<<i+1<<" -> "<<j+1<<" B-> "<<B[i][j]<<endl;
				}
				
		for(int i=1; i<index; i++)
			for(int j=index-1; j>=i; j--)
				if(R[j-1][2]>R[j][2])
				{
					int t0=R[j-1][0], t1=R[j-1][1], t2=R[j-1][2];
					R[j-1][0]=R[j][0];
					R[j-1][1]=R[j][1];
					R[j-1][2]=R[j][2];
					R[j][0]=t0;
					R[j][1]=t1;
					R[j][2]=t2;
				}
		
		for(int i=0; i<index; i++)
			if(Union(R[i][0],R[i][1]))
			{
				//cout<<R[i][0]+1<<"->"<<R[i][1]+1<<" = "<<R[i][2]+1<<endl;
				cost+=R[i][2];
			}			
		
		cout<<cost<<endl;
	}
}
