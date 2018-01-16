#include <iostream>
#include <cstring>
using namespace std;

int M[101][101];
bool visited[101][101];

int count=0, ans=0;

int Check(int i, int j, int h, int w)
{
	return (i >= 0) && (i < h) && (j >= 0) && (j < w) && (M[i][j] && !visited[i][j]);
}

void DFS(int i, int j, int h, int w)
{
	visited[i][j]=true;
	//cout<<i<<" "<<j<<endl;
	count++;
	int row[] = {-1,  0, 0, 1};
    int col[] = { 0, -1, 1, 0};	
    
    for (int k = 0; k < 4; k++)
        if (Check(i + row[k], j + col[k], h, w) )
            DFS(i + row[k], j + col[k], h, w);
}

void Islands(int h, int w)
{
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            if (M[i][j] && !visited[i][j]) 
            {   
				count=0;               
                DFS(i, j, h, w);
                //cout<<endl;
				if(count>ans)
					ans=count;              
            }
}

int main()
{
	int n,m,K;
	while(cin>>n>>m>>K)
	{
		ans=0;
		memset(M, 0, sizeof(M));
		while(K--)
		{
			int x,y;
			cin>>x>>y;
			M[--x][--y]=1;
		}
		Islands(n,m);
		cout<<ans<<endl;
	}
	return 0;
}
