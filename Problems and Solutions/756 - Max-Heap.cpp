#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int H[100001], I;
long long int sum;

void insert()
{
	cin>>H[I];
	sum += H[I];
	
	int parent = I/2, child = I++;
	while(H[parent] < H[child] && parent)
	{
		int temp = H[parent];
		H[parent] = H[child];
		H[child] = temp;
		
		child = parent;
		parent /= 2; 
	} 
}

void pop()
{
	sum -= H[1];
	H[1] = H[--I];
	H[I+1] = -1;
	
	int parent = 1, c1 = 2, c2 = 3;
	while(H[parent] < max(H[c1], H[c2]))
	{
		int temp = H[parent], newChild;
		
		if(H[c1] >= H[c2])
			newChild = c1;
		else
			newChild = c2;
		
		H[parent] = H[newChild];
		H[newChild] = temp;
		
		parent = newChild;
		c1 = parent*2;
		c2 = c1+1;
			
	}
}

int main()
{
	int N;
	
	while(cin>>N)
	{
		memset(H,-1,sizeof(H));
		sum = 0, I = 1;
		while(N--)
		{
			char a;
			cin>>a;
			
			if(a == 'a')	
				insert();
			else if(a == 'p')
				pop();
			else if(a == 'r')
				cout<<sum<<endl;
		}
	}
	
	return 0;
}
