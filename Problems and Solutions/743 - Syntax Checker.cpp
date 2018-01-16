#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool ArePair(char opening,char closing)
{
	if(opening == '(' && closing == ')') 
		return true;
	else if(opening == '{' && closing == '}') 
		return true;
	else if(opening == '[' && closing == ']') 
		return true;
	return false;
}

int main()
{
	string S;
	while(getline(cin,S))
	{
		stack<char>  E;
		stack<int>  I;
		bool balance = true;
		
		for(int i=0; i<S.length(); i++)
			if(S[i] == '(' || S[i] == '{' || S[i] == '[')
			{
				E.push(S[i]);
				I.push(i+1);
			}
			else if(S[i] == ')' || S[i] == '}' || S[i] == ']')
			{
				if(E.empty() || !ArePair(E.top(),S[i]))
				{
					cout<<i+1<<endl;
					balance = false;
					break;
				}
				else
				{
					E.pop();
					I.pop();	
				}
			}
		
		if(!E.empty() && balance)
		{
			balance = false; 
			int ans = -1;
			
			while(!E.empty())
			{
				ans = I.top();
				E.pop();
				I.pop();
			}
			cout<<ans<<endl;
		}
		
		if(balance)
			cout<<"Success"<<endl;
	}
	return 0;
}
