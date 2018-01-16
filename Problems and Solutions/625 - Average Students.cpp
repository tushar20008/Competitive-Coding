#include <iostream>
#include <climits>
using namespace std;
int main()
{
	int N;
	while(cin>>N)
	{
		int A[100];
		for(int i=1; i<=N; i++)
			cin>>A[i];
		for(int i=1; i<=N; i++)
			for(int j=1; j<N; j++)
				if(A[j]>A[j+1])
				{
					int tmp=A[j];
					A[j]=A[j+1];
					A[j+1]=tmp;	
				}	
		int B[50];
		for(int i=1; i<=N/2; i++)
			B[i]=A[i]+A[N+1-i];
		int min=INT_MAX, max=INT_MIN;
		for(int i=1; i<=N/2; i++)
		{
			//cout<<B[i]<<endl;
			if(B[i]<min)
				min=B[i];
			if(B[i]>max)
				max=B[i];
		}	
		//cout<<min<<" "<<max<<endl;
		cout<<max-min<<endl;
	}
}
