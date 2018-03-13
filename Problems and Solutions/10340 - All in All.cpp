#include <iostream>
using namespace std;

int main()
{
	string S1, S2;
	while(cin>>S1>>S2)
	{
		int len = S1.length(), matched = 0;
		for(int i=0; i<S2.length(); i++)
			if(S2[i] == S1[matched])
				matched++;
		if(matched == len)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl; 
	}
	return 0;
}