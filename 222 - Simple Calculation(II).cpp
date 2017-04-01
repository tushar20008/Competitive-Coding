#include <iostream>
#include <iomanip> // presentation
using namespace std;
int main()
{	
	long double sum=0.0,n;
	bool count =false;
	while(cin>>n)
	{
		sum+=n;
		
		if (cin.get() =='\n')
		{
			if(count)
				cout<<endl;
			cout << setprecision(4) << fixed <<  sum << endl;
			sum=0.0;
			count=true;
		}	
	}
	return 0;
}
