#include <iostream>	// WA
#include <cstring>			
#include <map>
using namespace std;
int A[401], D1[79801], D2[79801], D3[79801], B1[79801], B2[79801], B3[79801];
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
		memset(D1,-1,sizeof(D1));
		memset(D2,-1,sizeof(D2));
		memset(D3,-1,sizeof(D3));
		memset(B1,-1,sizeof(B1));
		memset(B2,-1,sizeof(B2));
		memset(B3,-1,sizeof(B3));
		int index = 0;
        map <string, int> p;
        for(int i=0; i<n; i++)
        {
        	string place;
        	cin>>place;
        	 p [place] = index++;
		}
		for(int i=0; i<m; i++)
		{
			string n1,n2;
			cin>>n1>>n2>>D3[i];
			D1[i]=p [n1];
			D2[i]=p [n2]; 			
		}
		string s;
		cin>>s;
	
		mergesort(0,m);
		int cost=0,edge=0;
		for(int j=0; j<m; j++)
			if(edge==n-1)
				break;		
			else if(Union(D1[j],D2[j]))
			{
				cost+=D3[j];
				edge++;
			}	
		if(edge==n-1)
			cout<<cost<<endl;
		else
			cout<<"Impossible"<<endl;
	}
}
