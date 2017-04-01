#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
int A[501];
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
	int n, m;
	while(cin>>n>>m)
	{
		if(n==0 && m==0)
			break;
		int *D1=new int[m],*D2=new int[m];
		signed int *PPA=new signed int[m];					// signed 32 bit variable
		for(int i=0; i<m; i++)
			cin>>D1[i]>>D2[i]>>PPA[i];
				
		signed int max_ppa=PPA[0];
		
		for(int i=0; i<m; i++)
			if(max_ppa<PPA[i])
				max_ppa=PPA[i];
				
		memset(A,-1,sizeof(A));
		for(int i=0; i<m; i++)
			if(PPA[i]==max_ppa)
				Union(D1[i]-1,D2[i]-1);
					
		int ans=INT_MAX;
		for(int i=0; i<n; i++)
			if(A[i]<ans)
				ans=A[i];
		
		cout<<ans-2*ans<<endl;
				
	}
	return 0;
}
