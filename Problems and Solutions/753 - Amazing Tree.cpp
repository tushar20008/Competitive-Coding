#include <iostream>
#include <stack>
using namespace std;

int main()
{
	string S;
	
	while(cin>>S)
	{
		int ans = 0;
		stack<int> I;
		
		for(int i=0; i<S.length(); i++)
			if(S[i] =='(')
				I.push(i);
			else
			{
				int temp = 1+ (i-I.top())/2;
				ans = (ans | temp) & (~ans | ~temp);
				I.pop(); 	
			}		
		
		cout<<ans<<endl;	
	}
	return 0;
}
