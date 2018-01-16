#include <iostream>
#include <cstring>
#include <queue>
#include <climits>      		
using namespace std;
int f[5000], d[5000];
queue<int> Q;
typedef struct{
   int v;     // edge (u->v)
   int cap;  // edge capacity (w)
   int nxt;  // the next edge connected by node u.
}EDGE;
int head[5000]; // the first edge connected by node u.
int totaledge; // the total number of edges
EDGE edge[5000];

int dinic(int u,int T,int Sum){
	if(u==T) return Sum;
	int v,tp = Sum;
	for(int e=head[u];e!=-1 && Sum;e=edge[e].nxt){
		v = edge[e].v;
		// find augmenting path by d[]
		if(d[v]==d[u]+1 && edge[e].cap>f[e]){
	int canflow = dinic(v,T,min(Sum,edge[e].cap-f[e]));
			f[e] += canflow;
			f[e^1] -= canflow;
			Sum -= canflow;
		// do not break, because may find more than 1 path
		}
	}
	return tp - Sum;
}

bool bfs(int S,int T){
int u,v;
memset(d,-1,sizeof(d));
while(!Q.empty())Q.pop();
Q.push(S);
d[S]=0;
while(!Q.empty()){
	u = Q.front();
	Q.pop();
	for(int e=head[u]; e!=-1; e=edge[e].nxt){
		v = edge[e].v;
		// d[v]=-1,then v is not visited yet
		// and the flow did not reach the capacity
		if((d[v]==-1) && edge[e].cap > f[e]){
			d[v] = d[u]+1;
			Q.push(v);
		}
	}
}
return d[T]>=0;
}

int maxFlow(int S,int T){
	int ans =  0;
	while(bfs(S,T))
		ans += dinic(S,T,0x3F);
	return ans;
}

void cleargraph(){
    totaledge = 0 ;
    memset( head,  -1, sizeof(head) );
}

void add_edge (int u, int v, int cap){
    edge[totaledge].v       =   v;
    edge[totaledge].cap  =   cap;
    edge[totaledge].nxt  =   head[u];
    head[u] = totaledge;
    totaledge++;
}

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		memset(f,0,sizeof(f));
		cleargraph();
		int s=0, t=2*n+1;
		for(int i=1; i<n+1; i++)
		{
			int a,b;
			cin>>a>>b;
			add_edge(s,i,a);
			add_edge(i,s,0);
			add_edge(i,i+n,b);
			add_edge(i+n,i,0);
			add_edge(i+n,t,INT_MAX);
			add_edge(t,i+n,INT_MAX);
		}
		for(int i=0; i<m; i++)		
		{
			int a,b,cost;
			cin>>a>>b>>cost;
			add_edge(a,b,cost);
			add_edge(b,a,cost);
			add_edge(b+n,a+n,cost);
			add_edge(a+n,b+n,cost);
		}
		cout<<maxFlow(s,t)<<endl;
	}
}
