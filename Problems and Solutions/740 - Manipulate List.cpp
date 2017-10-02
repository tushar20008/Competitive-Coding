#include <iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;
	
	int A[2000];
	for(int i=1; i<=N; i++)
		cin>>A[i];
	
	int Q;
	cin>>Q;
	
	while(Q--)
	{
		int oper;
		cin>>oper;
		
		if(oper == 1)
		{
			int i,val;
			cin>>i>>val;
			
			for(int j=i+1; j<=N; j++)
			{
				int temp = A[j];
				A[j] = val;
				val = temp;
			}
			N++;
		}
		else if(oper == 2)
		{
			int i;
			cin>>i;
			
			for(int j=i; j<N; j++)
				A[j]=A[j+1];
			N--;
		}
		else if(oper == 3)
		{
			int i,j;
			cin>>i>>j;
			
			int temp[2000];
			
			for(int start=i; start<=j; start++)
				temp[start] = A[start];
				
			int start = i;
			for(int end=j; end>=i; end--)
				A[start++] = temp[end];
		}
		else if(oper == 4)
		{
			int i;
			cin>>i;
			cout<<A[i]<<endl;
		}
	}
	
	return 0;
}
