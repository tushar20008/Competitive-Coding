#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
struct Point
{
	double x,y;	
};
int main()
{
	int N;
	while(cin>>N)
	{
		if(N==0)
			break;
		Point P[N];
		for(int i=0; i<N; i++)
			cin>>P[i].x>>P[i].y;
		double ans= 10000;
		for(int i=0; i<N; i++)
			for(int j=i+1; j<N; j++)
				if(sqrt(pow((P[i].x-P[j].x),2)+pow((P[i].y-P[j].y),2))<ans)
					ans=sqrt(pow((P[i].x-P[j].x),2)+pow((P[i].y-P[j].y),2));
		if(ans==10000)
			cout<<"INFINITY"<<endl;
		else
			cout<<fixed<<setprecision(4)<<ans<<endl;
	}
}
