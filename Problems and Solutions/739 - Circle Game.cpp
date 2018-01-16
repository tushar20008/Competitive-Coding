#include <iostream>
using namespace std;

int main()
{
	int N;
	cin>>N;
	
	int A[2000];
	for(int i=0; i<N; i++)
		cin>>A[i];
	
	int Q;
	cin>>Q;
	
	while(Q--)
	{
		int oper;
		cin>>oper;
		
		if(oper == 1)
		{
			int i, tag;
			cin>>i>>tag;
			
			int temp[2000];
			temp[0] = tag;
			
			int index = 1, start = i;
			while(start!=N)
				temp[index++] = A[start++];
			
			for(int j=0; j<i; j++)
				temp[index++] = A[j];
			
			N++;
			
			for(int j=0; j<N; j++)
				A[j] = temp[j];
			
		}
		else if(oper == 2)
		{
			int i;
			cin>>i;
			
			int temp[2000];
			
			int index = 0;
			while(i!=N)
				temp[index++] = A[i++];
			
			for(int j=0; j<i; j++)
				temp[index++] = A[j];
			
			N--;
			
			for(int j=0; j<N; j++)
				A[j] = temp[j];
			
		}
		else if(oper ==3)
		{
			int i;
			cin>>i;
			
			int temp[2000];
			i--;
			
			cout<<A[i]<<endl;
			
			int index = 0;
			while(i!=N)
				temp[index++] = A[i++];
			
			for(int j=0; j<i; j++)
				temp[index++] = A[j];
			
			for(int j=0; j<N; j++)
				A[j] = temp[j];
		}
	}
	
	return 0;
}
