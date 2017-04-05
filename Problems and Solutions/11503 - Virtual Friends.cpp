#include <iostream>
#include <cstring>			
#include <map>
using namespace std;
int *A=new int[100000 + 10];


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
	cout<<A[set1]*-1<<endl;  
}

void Union (int a, int b) 
{
	int root1=Find(a);
	int root2=Find(b);
	
	if(root1 == root2)
	{
		cout<<A[root1]*-1<<endl;
		return;
	}
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
		int F;
		cin>>F;
		memset(A,-1,sizeof(int)*100000 + 10);
		int index = 1;
        map <string, int> m;
		while(F--)
		{
			string n1,n2;
			cin>>n1>>n2;
			
			if ( !m [n1] )
                m [n1] = index++;
            if ( !m [n2])
                m [n2] = index++;
 
			Union(m [n1], m [n2]);			
		}
	}
}
