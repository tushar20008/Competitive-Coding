#include <iostream>
#include <cstring>
#include <queue>
#include <math.h>
using namespace std;
int A[1+200+1][1+200+1];

bool BFS(int n, int s, int t, int parent[])
{
    bool visited[n];
    memset(visited, 0, sizeof(visited));
 
    queue <int> q;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
 
        for (int v=0; v<n; v++)
        {
            if (visited[v]==false && A[u][v] > 0)
            {
                q.push(v);
                parent[v] = u;
                visited[v] = true;
                //cout<<u<<" "<<v<<endl;
            }
        }
    }
    return (visited[t] == true);
}

int maxFlow(int n, int s, int t)
{
    int parent[n],max_flow = 0; 
    while (BFS(n, s, t, parent))
    {
        int path_flow = 0x3F,u,v;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, A[u][v]);
            //cout<<u<<" "<<v<<" -> "<<path_flow<<endl;
        }
 
        for (v=t; v != s; v=parent[v])
        {
            u = parent[v];
            A[u][v] -= path_flow;
            A[v][u] += path_flow;
        }
 	    max_flow += path_flow;
    }
    return max_flow;
}

int main()
{
	int L,W,N,D, cases=1;
	while(cin>>L>>W>>N>>D)
	{
		if(L==0 && W==0 && N==0 && D==0)
			break;
		
		int G[N][2];
		int North=2*N, South= 2*N+1;
		for(int i=0; i<N; i++)
			cin>>G[i][0]>>G[i][1];
		
		memset(A,0,sizeof(A));
		for(int i=0; i<N; i++)
		{
			A[i*2][i*2+1]=1;
			if(G[i][1] <= D)
				A[North][i*2]=1;
			if(W - G[i][1] <= D)
				A[i*2+1][South]=1;
		}
		
		for(int i=0; i<N; i++)
			for(int j=0; j<N; j++)
				if(pow(G[i][0]-G[j][0],2) + pow(G[i][1]-G[j][1],2) <= pow(2*D,2))
					A[i*2+1][2*j]=1;
		
		cout<<"Case "<<cases++<<": "<<maxFlow(South+1,North,South)<<endl;	
	}
}

