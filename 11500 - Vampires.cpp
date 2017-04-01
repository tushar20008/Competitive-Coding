#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
int main()
{
	float EV1, EV2, AT, D;
	while(cin>>EV1>>EV2>>AT>>D)
	{
		if(EV1==0 && EV2==0 && AT==0 && D==0)
			break;
		float p=AT/6;
		float q=1-p;
		float n1 = ceil(EV1/D), n2 = ceil(EV2/D);
		if(p==0.5)
			cout<<fixed<<setprecision(1)<<(n1 / (n1 + n2))*100<<endl;
		else
			cout<<fixed<<setprecision(1)<<100*(1 - pow((q/p),n1)) / (1 - pow((q/p),(n1 + n2)))<<endl;
	}
}
