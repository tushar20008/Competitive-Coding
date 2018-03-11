#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	string S;
	while(cin>>S)
	{
		for(int i=0; i<S.length(); i++)
			cout<<char(S[i]-7);
		cout<<endl;
	}
	return 0;
}
