#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int N,K,Q;
	int *A=new int [100001];
	int *B=new int [100001];
	while(cin>>N>>K>>Q)
	{
		memset(A,-1,sizeof(int)*100001);
		for(int i=0; i<N; i++)
			cin>>A[i];
		K=K%N;
		int ind=0;
		for(int i=0; i<N; i++)
		{
			if(i+K < N)
				B[i+K]=A[i];
			else
				B[ind++]=A[i];
		}
		for(int i=0; i<Q; i++)
		{
			int q;
			cin>>q;
			cout<<B[q]<<endl;
		}
	}
}
