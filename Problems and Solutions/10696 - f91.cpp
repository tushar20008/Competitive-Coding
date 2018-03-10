#include <iostream>
#include <math.h>
using namespace std;

int cal(int n)
{
	if(n<=100)
		return cal(cal(n+11));
	else
		return n-10;
}

int main()
{
	long n;
	while(cin>>n)
		if(n!=0)
			cout<<"f91("<<n<<") = "<<cal(n)<<endl;
		else
			break;
	return 0;
}
