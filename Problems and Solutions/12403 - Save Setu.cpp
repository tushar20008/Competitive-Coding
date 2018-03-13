#include <iostream>
using namespace std;

int main()
{
	int T, account = 0;
	cin>>T;
	while(T--)
	{
		string S;
		cin>>S;
		if(S == "report")
			cout<<account<<endl;
		else
		{
			int temp;
			cin>>temp;
			account += temp;
		}
	}
	return 0;
}