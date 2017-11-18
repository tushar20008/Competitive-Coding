#include <iostream>
using namespace std;

struct node {
	int parent;
	int depth;
	
	void init(int p, int d)
	{
		parent = p;
		depth = d;
	}
};

int main()
{
	int T;
	cin>>T;

	while(T--)
	{
		
		int R, N;
		cin>>R>>N;
		node * Nodes = new node[N+1];
		Nodes[R].init(-1,0);
		
		for(int i=1; i<N; i++)
		{
			int m,p;
			cin>>m>>p;
			Nodes[m].init(p,Nodes[p].depth+1);
		}
		
		int a,b;
		cin>>a>>b;
		
		while(Nodes[a].depth > Nodes[b].depth)
			a = Nodes[a].parent;
		
		while(Nodes[a].depth < Nodes[b].depth)
			b = Nodes[b].parent;	
			
		while(Nodes[a].parent != Nodes[b].parent)
		{
			a = Nodes[a].parent;
			b = Nodes[b].parent;
		}
		
		if(a == b)
			cout<<a<<endl;
		else
			cout<<Nodes[a].parent<<endl;
	}
	
	return 0;
}
