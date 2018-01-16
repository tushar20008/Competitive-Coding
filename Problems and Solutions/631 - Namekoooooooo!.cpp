#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin>>N;
	
	while(N--)
	{
		int r,g,b;
		cin>>r>>g>>b;
		
		int soups1 = 0, soups2 = 0, soups3 = 0;
		
		soups1 += r/3 + g/3 + b/3;
		soups1 += min(min(r%3,g%3),b%3);
		
		if(min(min(r,g),b) > 0)
		{
			r--;
			g--;
			b--;
			soups2 += 1 + r/3 + g/3 + b/3;
			soups2 += min(min(r%3,g%3),b%3);		
		}
		
		if(min(min(r,g),b) > 0)
		{
			r--;
			g--;
			b--;
			soups3 += 2 + r/3 + g/3 + b/3;
			soups3 += min(min(r%3,g%3),b%3);		
		}
		
		cout<<max(max(soups1,soups2),soups3)<<endl; 
	}
	return 0;
}
