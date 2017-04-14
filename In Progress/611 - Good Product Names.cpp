#include <iostream>
using namespace std;

int main()
{
	string S;
	while(cin>>S)
	{
		bool isGood = true;
		int isA = 0, isU = 0, isE = 0, isO = 0, isI = 0, isConsonant = 0;
		
		if(S.size() != 8)
			isGood = false;
		else
		{
			for(int i=0; i<S.size(); i++)
				if(S[i] >= 'a' && S[i] <= 'z')
				{
					if(S[i] == 'a')
						isA++;
					else if(S[i] == 'u')
						isU++;
					else if(S[i] == 'e')
						isE++;
					else if(S[i] == 'o')
						isO++;
					else if(S[i] == 'i')
						isI++;
					else
						isConsonant++;
				}
				else
				{
					isGood = false;
					break;
				}
				
			if(isConsonant != 6 && (isA == 2 || isU == 2 || isE == 2 || isO == 2 || isI == 2))
				isGood = false;
		}
		
		if(isGood)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
