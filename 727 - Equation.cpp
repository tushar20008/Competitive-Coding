#include <iostream>
#include <cctype>
#include <stack>
using namespace std;

int main()
{
	stack <char> S;
	int n;
	cin>>n;
	while(n--)
	{
		char s[51];
		int count=0;
		while(cin>>s[count])
		{
			count++;
			cin.get();
			if(cin.peek() == '\n')
				break;	
		}	
		for(int i=0; i<count; i++)
		{
			if(isdigit(s[i]))
				cout<<s[i];
			else if(s[i]=='(')
				S.push(s[i]);
			else if(s[i]==')')
			{
				while(S.top() != '(' )
				{
					cout<<S.top();
					S.pop();
				}	
				S.pop();
			}
			else
			{
				while(!S.empty() && S.top() != '(' && (!(S.top() == '+' || S.top() == '-') || !(s[i] == '/' || s[i] == '*')))
				{
					cout<<S.top();
					S.pop();
				}
				S.push(s[i]);
			}
		}
		while(!S.empty())
		{
			cout<<S.top();
			S.pop();
		}
	
		cout<<endl;
		if(n)
			cout<<endl;
	}
}
