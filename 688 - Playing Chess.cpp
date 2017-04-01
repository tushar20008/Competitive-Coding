#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

char M[8][8];
bool visited[8][8];
int cost[8][8];

int Check(int i, int j)
{
	return (i >= 0) && (i < 8) && (j >= 0) && (j < 8) && (M[i][j]!='*' && !visited[i][j]);
}

void BFS(int i, int j)
{
	visited[i][j]=true;
	cost[i][j]=0;
	
	int row[] = {-2, -2, -1, -1,  1,  1,  2, 2};
    int col[] = {-1,  1, -2,  2, -2,  2, -1, 1};	
    
    queue<int>Q;
    Q.push(i);
    Q.push(j);
    while(!Q.empty())
    {
        int u=Q.front();
        Q.pop();
        int v=Q.front();
        Q.pop();
        for(int k=0; k<8; k++)
        {
            int r=row[k]+u;
            int c=col[k]+v;
            if(Check(r,c))
            {
                visited[r][c]=true;
                cost[r][c]=cost[u][v]+1;
                Q.push(r);
                Q.push(c);
            }
        }
	}
}

int main()
{
	int n;
	cin>>n;
	for(int t=0; t<n; t++)
	{
		int b1,b2,w1,w2;
		char s[9];
		for(int i=0; i<8; i++)
		{
			cin>>s;
			for(int j=0; j<8; j++)
			{
				M[i][j]=s[j];
				if(M[i][j]=='#')
				{
					b1=i;
					b2=j;
				} 
				else if(M[i][j]=='@')
				{
					w1=i;
					w2=j;
				}
			}	
		}	
		memset(cost,0,sizeof(cost));
        memset(visited,0,sizeof(visited));
		BFS(b1,b2);
		if(cost[w1][w2]!=0)
			cout<<"Case " << t+1 << ": " <<cost[w1][w2]<<endl;
		else
			cout<<"Case " << t+1 << ": IMPOSSIBLE"<<endl;
	}
	return 0;
}


