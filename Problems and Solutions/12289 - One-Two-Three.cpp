#include <iostream>
#include <cstring>
using namespace std;

bool isMatch(string S, string isMatch)
{
	int charM = 0;
	for(int i=0; i<S.length(); i++)
		if(S[i] == isMatch[i])
			charM++;
	if(charM >= 2)
		return true;
	return false;
}

int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		string S;
		cin>>S;
		if(S.length() == 5)
			cout<<3<<endl;
		else if(isMatch(S,"two"))
			cout<<2<<endl;
		else
			cout<<1<<endl;
	}
	return 0;
}