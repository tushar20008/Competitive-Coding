#include <iostream>
using namespace std;

int phi (int n)
{
    if ( n == 1 )
        return 1;
 
    int output = n;
 
    if ( n % 2 == 0 ) {
        output -= (output / 2);
        while ( n % 2 == 0 )
            n /= 2;
    }
 
    for ( int i = 3; i * i <= n; i += 2 ) {
        if ( n % i == 0 ) {
            output -= (output / i);
            while ( n % i == 0 )
                n /= i;
        }
    }
 
    if ( n > 1 )
        output -= (output / n);
 
    return output;
}

int main()
{
	int N;
	while(cin>>N)
	{
		if(N==0)
			break;
		cout<<phi(N)<<endl;
	}
}
