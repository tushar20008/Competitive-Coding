#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
	{
		char s[53];
		cin>>s;
		
		char temp=s[0];
		int again=0;
		for(int j=0; j<strlen(s); j++)
		{
			if(s[j]>temp)
			{
				again=j;
				temp=s[j];
			}
				
			if(j==strlen(s)-1)
			{
				cout<<temp;
				temp=s[again+1];
				j=again++;
			}	
		}
		cout<<endl;
	}
	return 0;
}
