#include <iostream>
#include <cstring>

using namespace std;
int A[200000+10],D1[200000+10],D2[200000+10],D3[200000+10],B1[200000+10],B2[200000+10],B3[200000+10];
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
void mergesort(int low, int up)
{
	if (low < up)
	{
		int m = (low+up)/2; 
		mergesort(low,m);
		mergesort(m+1,up);
		int i=low, j=m+1, k=low; 
		while (i<=m && j<=up) 
			if (D3[i] < D3[j]) 
			{	
				B2[k]=D2[i];
				B1[k]=D1[i];
				B3[k++]=D3[i++];		
			}
			else 
			{
				B2[k]=D2[j];
				B1[k]=D1[j];		
				B3[k++]=D3[j++];
			}
		while (i<=m)
		{
			B2[k]=D2[i];
			B1[k]=D1[i];
			B3[k++]=D3[i++];				
		}
		while (j<=up)
		{	
			B2[k]=D2[j];
			B1[k]=D1[j];
			B3[k++]=D3[j++];
		}
		for (k=low; k<=up; k++)
		{
			D3[k]=B3[k];	
			D2[k]=B2[k];
			D1[k]=B1[k];
		}
	}
}
int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0 && m==0)
			break;
			
		memset(A,-1,sizeof(A));
		memset(D1,-1,sizeof(A));
		memset(D2,-1,sizeof(A));
		memset(D3,-1,sizeof(A));
		memset(B1,-1,sizeof(A));
		memset(B2,-1,sizeof(A));
		memset(B3,-1,sizeof(A));
		
		int cost=0;
		for(int i=0; i<m; i++)
		{
			cin>>D1[i]>>D2[i]>>D3[i];
			cost+=D3[i];
		}
		
		mergesort(0,m);
		
		int edge=0;
		for(int j=0; j<m; j++)
			if(edge==n-1)
				break;		
			else if(Union(D1[j],D2[j]))
			{
				cost-=D3[j];
				edge++;
			}
			
		cout<<cost<<endl;
	}
}
