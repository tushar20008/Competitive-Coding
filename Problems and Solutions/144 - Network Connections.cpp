#include <iostream>
#include <cstring>			
using namespace std;
int A[65501];

int Find (int element)  
{
	if (A[element] < 0)
		return element;
	else
		return A[element]=Find(A[element]);
}

void UnionSet (int set1, int set2) 
{
	A[set1] += A[set2]; 
	A[set2] = set1;     
}

void Union (int a, int b) 
{
	int root1=Find(a);
	int root2=Find(b);

	if(root1 == root2)
		return;
	else if  (A[root1] <= A[root2]) 		
		UnionSet(root1, root2);
	else
		UnionSet(root2, root1);
}

int main()
{
	int d;
	cin>>d;
	while(d--)
	{
		int n;
		cin>>n;
		
		int C=0,W=0;
		memset(A,-1,sizeof(A));
		
		cin.get();
		while(cin.peek() !='\n')
		{
			char c;
			int a,b;
			cin>>c>>a>>b;
			if(c=='c')
				Union(a-1,b-1);
			else if(c=='q')
			{
				if(Find(a-1) == Find(b-1))
					C++;
				else
					W++;	
			}
			cin.get();
		}
		cout<<C<<","<<W<<endl;
		
		if(d)
			cout<<endl;
	}
}
