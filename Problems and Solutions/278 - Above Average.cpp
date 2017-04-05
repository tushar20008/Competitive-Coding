#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int C;
	cin>>C;
	for(int i=0; i<C; i++)
	{
		int T;
		cin>>T;
		int A[T];
		int Total = 0;
		
		for(int j=0; j<T; j++)
		{
			cin>>A[j];
			Total += A[j];
		}
		
		float avg = Total*1.0 / T;
		
		int aboveAvg = 0;
		for(int j=0; j<T; j++)
			if(A[j] > avg)
				aboveAvg++;
		
		cout << setprecision(3) << fixed <<  aboveAvg*100.0/T	<<	"%"	<<endl;	
	}
	return 0;
}
