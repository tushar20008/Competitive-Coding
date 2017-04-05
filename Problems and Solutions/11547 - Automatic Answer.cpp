#include <iostream>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
	int T,N;
	cin>>T;
	while(T--)
	{
		cin>>N;
		N=(((((N*567/9)+7492)*235/47)-498)/10)%10;
		if(N>=0)
			cout<<N<<endl;
		else
			cout<<-N<<endl;
	}
}
