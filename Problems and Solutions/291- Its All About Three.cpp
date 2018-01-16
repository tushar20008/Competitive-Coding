#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

bool Factor(int n)
{
	if(n%2==0)
		return false;
	for (int i = 3; i <=sqrt(n); i = i+2)
    {
        // While i divides n, print i and divide n
        while (n%i == 0)
        {
            n = n/i;
            if(i%10!=3)
            	return false;
        }
    }
    if(n%10==3 || n==1)
    	return true;
    else
    	return false;
}
int main()
{	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	while(cin>>n)
	{
		if(n==-1)
			break;
	
		if( n>2 && Factor(n))
			cout<<n<<" YES"<<endl;
		else
			cout<<n<<" NO"<<endl;
	}
}
