#include <iostream>	// Wrong Answer
using namespace std;
int main()
{
	int r;
	int pizza=1;
	while(cin>>r)
	{
		if(r==0)
			break;
		double w,h;
		cin>>w>>h;
		w=w/2;
		h=h/2;
		//cout<<w<<" "<<h<<endl;
		if((w*w)+(h*h)>(r*r))
			cout<<"Pizza "<<pizza++<<" does not fit on the table."<<endl;
		else
			cout<<"Pizza "<<pizza++<<" fits on the table."<<endl;
	}
}
