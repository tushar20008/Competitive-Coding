#include <iostream>
#include <cstring>
#include <queue>
#include <climits>
using namespace std;
int A[100][100];

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
        int path_flow = INT_MAX,u,v;
        for (v=t; v!=s; v=parent[v])
        {
            u = parent[v];
            path_flow = min(path_flow, A[u][v]);
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
	int n,count=1;
	while(cin>>n)
	{
		if(n==0)
			break;
			
		memset(A,0,sizeof(A));
		int s,d,c;
		cin>>s>>d>>c;
		while(c--)
		{
			int n1,n2,B;
			cin>>n1>>n2>>B;
			A[n1-1][n2-1]+=B;
			A[n2-1][n1-1]+=B;
		}
		cout<<"Network "<<count++<<endl;
		cout<<"The bandwidth is "<<maxFlow(n,s-1,d-1)<<"."<<endl<<endl;
	}
}
