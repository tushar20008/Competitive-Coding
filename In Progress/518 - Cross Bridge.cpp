#include <iostream>
using namespace std;

int main()
{
	int N;
	while(cin>>N)
	{
		int S1 = -1, S2 = -1, F1 = -1, F2 = -1, input;
		while(N--)
		{
			cin>> input;
			if(S1 == -1)
			{
				S1 = input;
				F1 = input;
			}
			else
			{
				if(input < F1)
				{
					F2 = F1;
					F1 = input;
				}	
				else if(input < F2 || F2 == -1)
					F2 = input;
					
				if(input > S1)
				{
					S2 = S1;
					S1 = input;	
				}
				else if(input > S2 || S2 == -1)
					S2 = input;
			}
		}
		cout<<min(2*F1 + S1 + S2 , 2*F2 + F1 + S1)<<endl;
	}
	return 0;
}
