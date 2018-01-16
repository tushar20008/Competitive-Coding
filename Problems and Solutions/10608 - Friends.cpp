#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
int A[30001];

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
	int n;
	cin>>n;
	while(n--)
	{
		memset(A,-1,sizeof(A));
		int town,pairs;
		cin>>town>>pairs;
		while(pairs--)
		{
			int a,b;
			cin>>a>>b;
			Union(a-1,b-1);
		}
		
		int F=INT_MAX;
		for(int i=0; i<town; i++)
			if(A[i]<F)
				F=A[i];
		
		cout<<F-2*F<<endl;
		
		/*
		for(int i=0; i<town; i++)
			//A[A[i]%town] = A[A[i]%town] + town;	 // O(n) To find the max frequency
		
		int friends=A[0]/town;
		for(int i=1; i<town; i++)
			if(A[i]/town > friends)
				friends=A[i]/town;
		cout<<friends<<endl;*/
	}
}
