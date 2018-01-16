#include <iostream>
#include <math.h>
using namespace	std;

unsigned Mod(unsigned B, unsigned P, unsigned M)
{
	unsigned Result;
	if(B==0)
		return 0;
	B%=M;
	
	if(P==0)
		return 1;
	if(P==1)
		return B;
	
	Result = Mod(B, P>>1, M);
  	Result = (	Result	*	Result	)	%	M;

  	if (P&1) 
		Result = (Result*B)%M;

 	return Result;
}

int main()
{
	long int B,P,M;
	while(cin>>B>>P>>M)
	{
		cout<<Mod(B,P,M)<<endl;
	}
}
