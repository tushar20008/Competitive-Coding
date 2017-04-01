#include <iostream> 
#include <cstring>
#include <cctype>
#include <stack>
using namespace std;
stack <char>O;
stack <int>S;

void Hexa(int n)
{
	if(n/16 > 0)
		Hexa(n/16);
	
	if(n%16 < 10)
		cout<<n%16;
	else
		cout<<(char)(65 + ((n%16)-10));
}

void Apply()
{
	char operand = O.top();
	O.pop();
	int b=S.top();
	S.pop();
	int a=S.top();
	S.pop();
	
	if(operand=='+')
		S.push(a+b);
	else if(operand=='*')
		S.push(a*b);	
	//cout<<S.top();
}

int main()
{
	char s[101];
	while(cin>>s)
	{
		int len=strlen(s);
		for(int i=0; i<len; i++)
		{
			if(isdigit(s[i]))
				S.push(s[i]-48);
			else if(isalpha(s[i]))
				S.push(s[i]-55);
			else if(s[i]=='(')
				O.push(s[i]);
			else if(s[i]==')')
			{
				while(O.top()!='(')
					Apply();
				O.pop();
			}
			else if(s[i]=='+' || s[i]=='*')
			{
				while(!O.empty() && O.top()!='(' && (O.top()!='+' || s[i]!='*'))
					Apply();
				O.push(s[i]);
			}
		}
		while(!O.empty())
			Apply();
		
		//cout<<S.top()<<endl;	
		Hexa(S.top());
		cout<<endl; 
	}
	return 0;
}

