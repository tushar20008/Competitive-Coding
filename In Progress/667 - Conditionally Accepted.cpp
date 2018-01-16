#include <iostream>
using namespace std;

int main()
{
	int N;
	cin	>>	N;
	while(N--)
	{
		string S;
		int R, A;
		cin>>S>>A>>R;
		
		int score = 0;
		for(int i=0; i<S.size(); i++)
		{
			if(S[i] == 'o')
				score += A;
			else if(S[i] == 'x')
				score -= R;

			if(score < 0)
				break;
		}	
		
		if(score < 0)
			cout<<"REJECT"<<endl;
		else
			cout<<"ACCEPT"<<endl;		
	}
	return 0;
}
