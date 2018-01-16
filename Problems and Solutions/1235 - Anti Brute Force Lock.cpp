#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
int A[501*501],B1[501*501],B2[501*501],B3[501*501],D1[501*501],D2[501*501],D3[501*501];
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
int Moves(int a, int b)
{
	int total=0;
	for(int i=0; i<4; i++)
	{
		int x=a%10, y=b%10;
		a=a/10;
		b=b/10;
		int dif;
		if(x-y < 0)
			dif = y - x;
		else
			dif= x - y;
        total += min(dif, 10 - dif);
	}
	return total;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		memset(A,-1,sizeof(A));
		memset(D1,0,sizeof(D1));
		memset(D2,0,sizeof(D1));
		memset(D3,0,sizeof(D1));
		memset(B1,0,sizeof(D1));
		memset(B2,0,sizeof(D1));
		memset(B3,0,sizeof(D1));
		int n;
		cin>>n;
		
		int A[n];
		bool found=false;
		for(int i=0; i<n; i++)
		{
			cin>>A[i];
			if(A[i]==0)
				found=true;
		}
			
		
		int index=0,cost=INT_MAX;
		for(int i=0; i<n; i++)
			for(int j=i+1; j<n; j++)
			{
				D1[index]=i;
				D2[index]=j;
				D3[index++]=Moves(A[i],A[j]);
			}
		
		if(!found)
			for(int i=0; i<n; i++)
				cost=min(cost,Moves(0,A[i]));
		else
			cost=0;

		if(index>1)
			mergesort(0,index);
		int edge=0;
		for(int j=0; j<index; j++)
			if(edge==n-1)
				break;	
			else if(Union(D1[j],D2[j]))
			{
				cost+=D3[j];
				edge++;
			}	
		cout<<cost<<endl;
	}
}
