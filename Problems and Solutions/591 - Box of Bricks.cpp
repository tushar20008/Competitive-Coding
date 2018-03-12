#include <iostream>
#include <math.h>
using namespace std;

int main()
{
	int N, set = 1;
	while(cin>>N)
	{
		if(N == 0)
			break;
		int A[N], sum = 0;
		for(int i=0; i<N; i++)
		{
			cin>>A[i];
			sum += A[i];
		}	
		int avg = sum/N;
		int moves = 0;
		for(int i=0; i<N; i++)
			moves += abs(avg - A[i]);
		cout<<"Set #"<<set++<<endl;
		cout<<"The minimum number of moves is "<<moves/2<<"."<<endl<<endl;;
	}
	return 0;
}