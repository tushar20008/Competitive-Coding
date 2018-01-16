#include <iostream>
#include <cstring>
#include <climits>
using namespace std;   
int D[130*130];
int Track[130*130];

void ShowPath(int i)
{
	if(i==0)
		cout<<0;
	else
	{
		ShowPath(Track[i]);
		cout<<"->"<<i;
	}
		
}
int minDis(int D[], bool visited[],int N)
{
	int dis=INT_MAX, index;
	for(int i=0; i<N; i++)
	{
		if(!visited[i] && D[i]<=dis)
		{
			index=i;
			dis=D[i];
		}
	}
	return index;
}
void Relax(int u, int v, int w)
{
	if(D[v]>D[u]+w)
	{
		D[v]=D[u]+w;
		Track[v]=u;	
	}
}
int main()
{
	
	int n,count=1;
	while(cin>>n)
	{
		if(n==0)
			break;
			
		int A[n][n];
		
		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
				cin>>A[i][j];
	
		int N=n*n;
		for(int i=0; i<N; i++)
			D[i]=INT_MAX;
		D[0]=0;
		bool visited[N];
		memset(visited,0,sizeof(visited));
		for(int k=0; k<N-1; k++)  
     	{  
     		int u=minDis(D,visited,N);
			visited[u]=true; 
			int V[2][4],index=0;  
         	int i=u/n, j=u%n;
         	if(i!=n-1)
         	{	
				V[0][index]=u+n;
				V[1][index]=A[i+1][j];
				index++;         	
			}	
			if(i!=0)
			{
				V[0][index]=u-n;
				V[1][index]=A[i-1][j];
				index++;
			}
			if(j!=0)
			{
				V[0][index]=u-1;
				V[1][index]=A[i][j-1];
				index++;
			}
			if(j!=n-1)
			{
				V[0][index]=u+1;
				V[1][index]=A[i][j+1];
				index++;
			}
			for(int i=1; i<index; i++)
				for(int j=index; j>=i; j--)
					if(V[1][j-1]>V[1][j])
					{
						int temp1=V[0][j-1];
						int temp2=V[1][j-1];
						
						V[0][j-1]=V[0][j];
						V[1][j-1]=V[1][j];
						
						V[0][j]=temp1;
						V[1][j]=temp2;
					}
			for(int i=0; i<index; i++)
				Relax(u,V[0][i],V[1][i]);
     	}  
		ShowPath(n*n-1);  	
		cout<<"Problem "<<count<<": "<<D[n*n-1]+A[0][0]<<endl;
		count++;
	}
}
