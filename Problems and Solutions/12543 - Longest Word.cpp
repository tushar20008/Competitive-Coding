#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int max=0,count;
    string word,big_word;
    
    while(cin>>word)
    {
        if(word=="E-N-D") 
			break;
			
        count=0;
        int size=word.size();
        
        for(int i=0; i<size; i++)
            if(isalpha(word[i]) || word[i]=='-')
                count++;
                
        if(count>max)
        {
            big_word=word;
            max=count;
        }
    }
    
    int size=big_word.size();
    
    for(int i=0;i<size;i++)
        if(isalpha(big_word[i]) || big_word[i]=='-')
        {
            if(big_word[i]>='A' && big_word[i]<='Z') 
				big_word[i]=big_word[i]-'A'+'a';
            cout<<big_word[i];
        }
    cout<<endl;
    return 0;
}




