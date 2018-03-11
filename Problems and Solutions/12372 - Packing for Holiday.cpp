#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	for(int i=0; i<T; i++)
	{
		int L,W,H;
		cin>>L>>W>>H;
		cout<<"Case "<<i+1<<": ";
		if(L<=20 && W<=20 && H<=20)
			cout<<"good"<<endl;
		else
			cout<<"bad"<<endl;
	}
	return 0;
}