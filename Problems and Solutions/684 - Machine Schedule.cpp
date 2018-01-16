#include <iostream>
#include <cstring>
#include <queue>      		
using namespace std;
int f[3000], d[3000];
queue<int> Q;
typedef struct{
   int v;     // edge (u->v)
   int cap;  // edge capacity (w)
   int nxt;  // the next edge connected by node u.
}EDGE;
int head[3000]; // the first edge connected by node u.
int totaledge; // the total number of edges
EDGE edge[3000];

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
	int a,b,p;
	while(cin>>a>>b>>p)
	{
		memset(f,0,sizeof(f));
		cleargraph();
		int s=0, t=a+b+201;
		for(int i=0; i<p; i++)
		{
			int m1,m2;
			cin>>m1>>m2;
			if(m1==0 || m2==0)
				continue;
			else 
			{
				bool f1=false, f2=false, f3=false;
				for (int e = head[s]; e != -1; e = edge[e].nxt )
					if(edge[e].v==m1)
					{
						f1=true;
						//cout<<"found1"<<endl;
						break;
					}
				if(!f1)
				{
					add_edge(0,m1,1);
					add_edge(m1,0,0);	
				}
				for (int e = head[t]; e != -1; e = edge[e].nxt )
					if(edge[e].v==m2+100)
					{
						f2=true;
						//cout<<"found2"<<endl;
						break;
					}
				if(!f2)
				{	
					//add_edge(0,100+m2,0);
					//add_edge(100+m2,0,0);
					add_edge(100+m2,t,1);
					add_edge(t,100+m2,0);
					
					add_edge(m1,100+m2,1);
					add_edge(100+m2,m1,0);
				}
				else
				{
					for (int e = head[m1]; e != -1; e = edge[e].nxt )
					if(edge[e].v==m2+100)
					{
						f3=true;
						break;
					}
					if(!f3)
					{
						add_edge(m1,100+m2,1);            // Check this connection, It creates a new one
						add_edge(100+m2,m1,0);	
					}	
				}
			}
		}/*
		for (int e = head[s]; e != -1; e = edge[e].nxt ){
    printf ( "%d -> %d : %d", s , edge[e].v ,  edge[e].cap );
    cout<<endl;}*/
		cout<<maxFlow(s,t)<<endl;
	}
}
