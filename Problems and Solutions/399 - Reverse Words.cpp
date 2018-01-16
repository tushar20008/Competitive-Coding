#include <iostream>
#include <stack>
#include <cstring>
using namespace std;
stack<char> s;
int main()
{
	int N;
	cin>>N;
	char c;
	c=getchar();
	char A[1001];
	for(int i=1; i<=N; i++)
	{
		cin.getline(A,1001);
		cout<<"Case #"<<i<<": ";
		for(int j=strlen(A)-1; j>=0; j--)
		{
			if(A[j]==' ')
			{
				while(s.size()!=0)
				{
                	putchar(s.top());
                	s.pop();
            	}
            	cout<<A[j];
			}
			else
				s.push(A[j]);
		}
		while(s.size()!=0)
		{
           	putchar(s.top());
            s.pop();
        }	
		cout<<endl;
	}
}
