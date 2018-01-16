#include <iostream>
#include <cstring>
#include <iomanip>
#include <queue>
using namespace std;
 
struct Edge
{
  int source, dest, speed;
};

bool operator<(const Edge &e1,const Edge &e2)
{
    return true;
}
 
int G[35][35], S[35][35]; 
bool V[35][35][35];
double T[35][35][35];

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	int n,m;
	while(cin>>n>>m)
	{
		if(n==0 && m==0)
			break;
		
		int s,D;
		cin>>s>>D;
		s--;
		D--;
		memset(G,-101,sizeof(G));
		memset(S,0,sizeof(S));
		memset(V,false,sizeof(V));
		for(int i=0; i<35; i++)
			for(int j=0; j<35; j++)
				for(int k=0; k<35; k++)
					T[i][j][k]=1<<30;
		for(int i=0; i<m; i++)
		{
			int x,y,dist,speed;
			cin>>x>>y>>dist>>speed;
			G[--x][--y]=dist;
			G[y][x]=dist;
			S[x][y]=speed;
			S[y][x]=speed;
		}
		T[s][s][0]=0;
		double short_time=-9211;
		priority_queue< pair<double,Edge> > pq;
		
		Edge e;
		e.source=s;
		e.dest=s;
		e.speed=0;
		pq.push(make_pair(0,e));
		while(!pq.empty())
		{
        	pair<double,Edge> top=pq.top(); 
			pq.pop();
            int source=top.second.source;
			int des=top.second.dest;
			int speed=top.second.speed;
            if(V[source][des][speed]==true) 
				continue;
            V[source][des][speed]=true;
            if(source==D && speed==1)
			{
                short_time=T[source][des][speed];
                break;
            }
            
            for(int i=0; i<n; i++)
			{
            	if(G[source][i] ==-101 || i==des) 
					continue;
                for(int j=-1; j<=1; j++)
				{
                    int speed2=speed+j;
                    if(1<=speed2 && speed2<=S[source][i])
					{
                        double time2=T[source][des][speed]+(double)G[source][i]/speed2;
                        if(time2 < T[i][source][speed2])
						{
							Edge add_e;
							add_e.source=i;
							add_e.dest=source;
							add_e.speed=speed2;
                            pq.push(make_pair(-time2,add_e));
                            T[i][source][speed2]=time2;
                        }
                    }
                }
            }
    	}
		if(short_time < 0)
			cout<<"unreachable"<<endl;
		else
			cout<<fixed<<setprecision(5)<<short_time<<endl;
	}
	return 420;
}
