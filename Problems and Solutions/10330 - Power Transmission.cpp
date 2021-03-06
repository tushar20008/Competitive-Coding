#include <iostream>
#include <cstring>
#include <climits>
#include <queue>      			// f should be inti 0, add 2 edges everytime
using namespace std;
int f[70000*2], d[70000*2];
queue<int> Q;
typedef struct{
   int v;     // edge (u->v)
   int cap;  // edge capacity (w)
   int nxt;  // the next edge connected by node u.
}EDGE;
int head[70000*2]; // the first edge connected by node u.
int totaledge; // the total number of edges
EDGE edge[70000*2];

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
		ans += dinic(S,T,INT_MAX);
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
	int N;
	while(cin>>N)
	{
		memset(f,0,sizeof(f));
		cleargraph();
		int s=0,t=2*2*N+1;
		for(int i=1; i<=N; i++)
		{
			int P;
			cin>>P;
			add_edge(2*i,2*i+1,P);
			add_edge(2*i+1,2*i,0);
		}
		int M;
		cin>>M;
		while(M--)
		{
			int x,y,P;
			cin>>x>>y>>P;
			add_edge(2*x+1,2*y,P);
			add_edge(2*y,2*x+1,0);
		}
		int a,b;
		cin>>a>>b;
		while(a--)
		{
			int y;
			cin>>y;
			add_edge(s,2*y,INT_MAX);
			add_edge(2*y,s,0);
		}
		while(b--)
		{
			int x;
			cin>>x;
			add_edge(2*x+1,t,INT_MAX);
			add_edge(t,2*x+1,0);
		}
		cout<<maxFlow(s,t)<<endl;
	}
}
