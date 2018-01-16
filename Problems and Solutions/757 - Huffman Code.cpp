#include <iostream>
#include <queue>

using namespace std;

struct node{
   int label;
   int freq;
	
	node(int x, int y){
		label = x;
		freq = y;
	}
};

bool operator<(const node& a, const node& b) {
  return a.freq > b.freq;
}

int A[2*100000][3];

int getW(int I, int W)
{
	if(A[I][1] == -1)
		return W*A[I][0];
	else
		return getW(A[I][1], W+1) + getW(A[I][2], W+1);
}

int main()
{
	int N;
	while(cin>>N)
	{
		priority_queue<node> pq;
		int I = N;
		
		for(int i=0; i<N; i++)
		{
			int temp;
			cin>>temp;
			pq.push(node(i,temp));
			A[i][0] = temp;
			A[i][1] = -1;
			A[i][2] = -1;
		}
		
		while(true)
		{
			node a = pq.top();
			pq.pop();
			
			if(pq.empty())
				break;	
			
			node b = pq.top();
			pq.pop();
			
			pq.push(node(I,a.freq+b.freq));
			A[I][0] = a.freq+b.freq;
			A[I][1] = a.label;		
			A[I++][2] = b.label;		
		}
		
		cout<< getW(I-1,0) <<endl;
		
	}
	return 0;	
}
