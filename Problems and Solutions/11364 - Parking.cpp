#include <iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		int N, min = -1, max = -1;
		cin>>N;
		while(N--)
		{
			int temp;
			cin>>temp;
			if(temp > max || max == -1)
				max = temp;
			if(temp < min || min == -1) 
				min = temp;
		}
		int ans = 2*(max-min);
		cout<<ans<<endl;
	}
	return 0;
}