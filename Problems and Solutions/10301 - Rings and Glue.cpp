#include <iostream>
#include <math.h>
#include <cstring>
using namespace std;

struct Circle
{
	float x,y,r;
	bool overlap(Circle C)
	{
		if(x==C.x && y==C.y && r==C.r)
			return true;
		float D=sqrt(pow((x-C.x),2)+pow((y-C.y),2));
		float modR=r-C.r;
		if(modR<0)
			modR*=-1;
		if(D<=r+C.r && D>=modR)
			return true;
		return false;
	}
};

int A[20000];

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
	//cout<<root1<<" "<<root2<<endl;
	if(root1 == root2)
		return;
	else if  (A[root1] <= A[root2]) 		
		UnionSet(root1, root2);
	else
		UnionSet(root2, root1);
}

int main()
{
	int N;
	while(cin>>N)
	{
		if(N==-1)
			break;
		else if(N==0)
			cout<<"The largest component contains 0 rings."<<endl;
		else
		{
			memset(A,-1,sizeof(A));
			Circle C[N];
			for(int i=0; i<N; i++)
				cin>>C[i].x>>C[i].y>>C[i].r;
			int X=0;
			for(int i=0; i<N; i++)
			{
				for(int j=0; j<N; j++)
					if(j==i)
						continue;
					else if(C[i].overlap(C[j]))
						Union(i,j);
			}
			for(int i=0; i<N; i++)
				if(A[i]<X)
					X=A[i];
			X=-X;
			if(X==1)
				cout<<"The largest component contains 1 ring."<<endl;
			else 
				cout<<"The largest component contains "<<X<<" rings."<<endl;
		}
	}
}
