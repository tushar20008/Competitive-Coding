#include <iostream>
using namespace std;

bool isPrime(int n)
{
	bool isP = true;
	for(int i = 2; i <= n / 2; ++i)
    	if(n % i == 0)
    		isP = false;
    return isP;
}

int main()
{
	string S;
	while(cin>>S)
	{
		int n = 0;
		for(int i=0; i<S.length(); i++)
			if(S[i] >= 'a' && S[i] <= 'z')
				n += S[i] - 'a' + 1;
			else
				n += S[i] - 'A' + 27;
		if(isPrime(n))
			cout<<"It is a prime word."<<endl;
		else
			cout<<"It is not a prime word."<<endl;
	}
	return 0;
}