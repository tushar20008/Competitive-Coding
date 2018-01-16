#include <iostream>
#include <string>
#include <set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);					// These 2 Lines to increase I/O Speed
    cin.tie(NULL); 
	char letter;
	string Word;
	set<string> D;
	set<string>::iterator it;
	while( scanf("%c", &letter) != EOF )
	//while(cin>>letter)
	{
		if(isalpha(letter))
			Word += tolower(letter);
		else if(Word != "" )
		{
			 D.insert(Word);
      		 Word = "";
		}
	}
	if( Word != "" )
    	D.insert(Word);
	for(it = D.begin() ; it != D.end() ; it++ )
   		cout<<it->c_str()<<endl;
    return 420;
}
