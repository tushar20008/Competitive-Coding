#include <iostream>
#include <queue>

using namespace std;
queue<int> H,L;

int main()
{
	int N;
	while(cin>>N)
	{	
		int A[N][4];
		for(int i=0; i<N; i++)
		{
			cin>>A[i][0];
			cin>>A[i][1];
			cin>>A[i][2];
		}
		
		int time = 0;
		
		for(int i=0; i<=1000; i++)
		{
			for(int j=0; j<N; j++)
			{
				if(A[j][0] == i)
				{
					if(A[j][2] == 0)
						H.push(j);
					else if(A[j][2] == 1)
						L.push(j);
				}
			}
			
			while(time <= i)
			{
				if(!H.empty())
				{
					time += A[H.front()][1];
					A[H.front()][3] = time;
					H.pop();
				}
				else if(!L.empty())
				{
					time += A[L.front()][1];
					A[L.front()][3] = time;
					L.pop();
				}
				else
					time++;
			}
		}
		while(!H.empty())
		{
			time += A[H.front()][1];
			A[H.front()][3] = time;
			H.pop();
		}
		while(!L.empty())
		{
			time += A[L.front()][1];
			A[L.front()][3] = time;
			L.pop();
		}
		
		for(int i=0; i<N-1; i++)
			cout<<A[i][3]<<" ";
		cout<<A[N-1][3]<<endl;
	}
	return 0;
}
