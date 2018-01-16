#include <iostream>
#include <stack>  

using namespace std;

int main()
{
	string A;
	stack<int> S;
	while(getline(cin,A))
	{
		for(int i=0; i<A.length(); i++)
		{
			if(A[i] == '-')
			{
				int a = S.top();
				S.pop();
				int b = S.top();
				S.pop();
				S.push(b-a); 	
			}
			else if(A[i] == '+')
			{
				int a = S.top();
				S.pop();
				int b = S.top();
				S.pop();
				S.push(b+a); 	
			}
			else if(A[i] == '*')
			{
				int a = S.top();
				S.pop();
				int b = S.top();
				S.pop();
				S.push(b*a); 	
			}
			else if(A[i] != ' ')
				S.push(A[i]-48);
		}
		cout<<S.top()<<endl;
	}
	return 0;
}
