#include<iostream>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	
    int N;
    while(cin>>N)
	{
        if(N%3 == 0 && N>2)
            cout<<1<<endl;
        else
        	cout<<0<<endl;
    }
    return 0;
}
