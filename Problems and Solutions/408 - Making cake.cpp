#include <iostream>
#include <cstring>
using  namespace std;

int main()
{
	int N;
	while(cin>>N)
	{
		int A, prev = -1;
		int cakes = 0;
		
		while(N--)
		{
			cin >> A;
			if(prev == -1)
			{
				cakes += A;
				
			}
			else
			{
				if(prev < A)
					cakes += A - prev;
			}
			prev = A;
		}
		cout <<	cakes	<<endl;
	}
	return 0;
}
