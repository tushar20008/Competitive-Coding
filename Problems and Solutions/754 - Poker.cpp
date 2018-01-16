#include <iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	
	while(T--)
	{
		int N;
		cin>>N;
		
		int A[100001];
		
		for(int i=0; i<N; i++)
			cin>>A[i];
			
		int M;
		cin>>M;
		
		while(M--)
		{
			char c;
			cin>>c;
			
			if(c == 'r')
				N--;
			else if(c == 'm')
			{
				int high = 0;
				for(int i=0; i<N; i++)
					if(A[i]>high)
						high = A[i];
				
				cout<<high<<endl;
			}
			else
			{
				cin>>A[N];
				N++;
			}
		}
	}

	
	return 0;
}
