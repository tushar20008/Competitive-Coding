#include <iostream>
#include <cstring>
using namespace std;
int A[50001];
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

void Union (int a, int b) 
{
	int root1=Find(a);
	int root2=Find(b);
	//cout<<root1<<" "<<root2<<endl;
	if(root1 == root2)
		return;
	else if  (A[root1] <= A[root2]) 		
		UnionSet(root1, root2);
	else
		UnionSet(root2, root1);
}

int main()
{
	int n,m;
	int c=1;
	while(cin>>n>>m)
	{
		if(n==0 && m==0)
			break;
		
		memset(A,-1,sizeof(A));
		for(int i=0; i<m; i++)
		{
			int a,b;
			cin>>a>>b;
			Union(a-1,b-1);
		}
		
		int r=0;
		for(int i=0; i<n; i++)
			if(A[i]<0)
				r++;
		
		cout<<"Case "<<c++<<": "<<r<<endl;
	}
}
