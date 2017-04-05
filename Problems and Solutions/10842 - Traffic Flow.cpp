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
	int T,cases=1;
	cin>>T;
	while(T--)
	{
		int n,m;
		cin>>n>>m;
		
		memset(A,-1,sizeof(A));
				
		int D[m][3];
		for(int i=0; i<m; i++)
			cin>>D[i][0]>>D[i][1]>>D[i][2];
			
		for(int i=1; i<m; i++)					// Improve Sorting Algo. to decrease time limit
			for(int j=m-1; j>=i; j--)
				if(D[j-1][2]<D[j][2])
				{
					int t0=D[j-1][0], t1=D[j-1][1], t2=D[j-1][2];
					D[j-1][0]=D[j][0];
					D[j-1][1]=D[j][1];
					D[j-1][2]=D[j][2];
					D[j][0]=t0;
					D[j][1]=t1;
					D[j][2]=t2;
				}
		
		int cap=D[0][2];
		for(int j=0; j<m; j++)		
			if(Union(D[j][0],D[j][1]))
				cap=min(cap,D[j][2]);	
		cout<<"Case #"<<cases++<<": "<<cap<<endl;
	}
	return 0;
}
