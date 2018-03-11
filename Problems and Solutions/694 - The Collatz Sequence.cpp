#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int main()
{
	long long int A,L;
	int cases = 1;
	while(cin>>A>>L)
	{
		if(A < 0 && L < 0)
			break;
		int t = 0;
		long long int tempA = A;
		while(tempA <= L)
		{
			if(tempA % 2 == 0)
				tempA /= 2;
			else
				tempA = (3*tempA)+1;
			t++;
			if(tempA == 1)
			{
				t++;
				break;
			}
		}
		cout<<"Case "<<cases++<<": A = "<<A<<", limit = "<<L<<", number of terms = "<<t<<endl;
	}
	return 0;
}