#include <iostream>
#include <cstring>
using namespace std;

int M[51][51];
bool visited[51][51];

int Check(int i, int j, int h, int w)
{
	return (i >= 0) && (i < h) && (j >= 0) && (j < w) && (M[i][j] && !visited[i][j]);
}

void DFS(int i, int j, int h, int w)
{
	visited[i][j]=true;
	
	int row[] = {-1, -1, -1,  0, 0,  1, 1, 1};
    int col[] = {-1,  0,  1, -1, 1, -1, 0, 1};	
    
    for (int k = 0; k < 8; k++)
        if (Check(i + row[k], j + col[k], h, w) )
            DFS(i + row[k], j + col[k], h, w);
}

int Islands(int h, int w)
{
    memset(visited, 0, sizeof(visited));
	
	int count = 0;
    for (int i = 0; i < h; ++i)
        for (int j = 0; j < w; ++j)
            if (M[i][j] && !visited[i][j]) 
            {                  
                DFS(i, j, h, w);     
                count++;                 
            }
 
    return count;	
}

int main()
{
	int h,w;
	while(cin>>w>>h)
	{
		if(h==0 && w==0)
			break;
			
		for(int i=0; i<h; i++)
			for(int j=0; j<w; j++)
				cin>>M[i][j];
		
		cout<<Islands(h,w)<<endl;
		memset(M, 0, sizeof(M));
	}
	return 0;
}
