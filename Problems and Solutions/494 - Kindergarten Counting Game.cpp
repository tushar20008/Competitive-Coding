#include <iostream>	
#include <cstring>
using namespace std;
int main()
{
	char A[1001];
	while(cin.getline(A,1001))
	{
		int count=0;
		bool word=true;
		for(int i=0; i<strlen(A); i++)
		{
			if((A[i]>='a' && A[i]<='z')||((A[i]>='A' && A[i]<='Z')))
			{
				if(word)
				{
					count++;
					word=false;
				}
			}
			else
				word=true;
		}
		cout<<count<<endl;
	}
}
