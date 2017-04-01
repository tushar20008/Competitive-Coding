#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int X[201],Y[201],R[201];

int main()
{
	int N;
	while(cin>>N)
	{
		if(N==0)
			break;
		
		for(int i=0; i<N; i++)
			cin>>X[i]>>Y[i]>>R[i];
		
		double ans=0;
		for(int i=0; i<60*24; i++)
		{
			//double PI=acos(-1.0);
			//double angle=2*PI*i/(60*24), 
			//double x=500*sin(angle), y=500*cos(angle), S=0;
			double S=0, x=500*sin(2*acos(-1)*i/(60*24)), y=500*cos(2*acos(-1)*i/(60*24));
    		for (int j=0; j<N; j++) 
			{
      			double temp = (x*X[j] + y*Y[j])/sqrt(x*x + y*y);
      			
				if (temp<0) 
					continue;
				else
      				temp= X[j]*X[j]+Y[j]*Y[j]-temp*temp;
      			
				if (temp>R[j]*R[j]) 
				  continue;
				else
      				S+=2*sqrt(R[j]*R[j]-temp);
			}
    		ans=max(ans,S);
		}
		cout<<fixed<<setprecision(3)<<ans<<endl;
	}
	return 420;
}
