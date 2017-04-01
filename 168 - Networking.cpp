#include <iostream>
#include <cstring>
using namespace std;
int A[51];

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

bool Union (int a, int b) 
{
	int root1=Find(a);
	int root2=Find(b);
	
	if(root1 == root2)
		return false;
	else if  (A[root1] <= A[root2]) 		
		UnionSet(root1, root2);
	else
		UnionSet(root2, root1);
	
	return true;
}
int main()
{
	int P;
	while(cin>>P)
	{
		if(P==0)
			break;
		
		int R;
		cin>>R;
		int Data[R][3];
		for(int i=0; i<R; i++)
			cin>>Data[i][0]>>Data[i][1]>>Data[i][2];
		
		for(int i=1; i<R; i++)
			for(int j=R-1; j>=i; j--)
				if(Data[j-1][2]>Data[j][2])
				{
					int t0=Data[j-1][0], t1=Data[j-1][1], t2=Data[j-1][2];
					Data[j-1][0]=Data[j][0];
					Data[j-1][1]=Data[j][1];
					Data[j-1][2]=Data[j][2];
					Data[j][0]=t0;
					Data[j][1]=t1;
					Data[j][2]=t2;
				}
		/*
		for(int i=0; i<R; i++)
			cout<<Data[i][2]<<" ";
		cout<<endl;
		*/
		int len=0;
		memset(A,-1,sizeof(A));
		for(int i=0; i<R; i++)
		{
			if(Union(Data[i][0],Data[i][1]))
				len+=Data[i][2];
		}
		cout<<len<<endl;
	}	
	return 0;
}
