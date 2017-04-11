#include <iostream>
#include <math.h>
using namespace std;

int getValue(int n)
{
	int largest = 0, sum = 0;
    
    if(n%2 == 0)
    {
    	sum += 2;
    	largest = 2;
	}
	
	while (n%2 == 0)
        n = n/2;
 
    for (int i = 3; i <= sqrt(n); i = i+2)
    {
    	if(n%i == 0)
    	{
    		sum += i;
            if(largest < i)
            	largest = i;
		}
		
        while (n%i == 0)        
            n = n/i;
    }
 
    if (n > 2)
    {
    	sum +=n;
    	if(largest < n)
    		largest = n;
	}
	
	//cout<<largest <<"	"<<sum<<endl;
	return 2*largest - sum;
}

int main()
{
	int a,b;
	while(cin>>a>>b)
	{
		if(a==0 && b==0)
			break;
			
		int A = getValue(a);
		int B = getValue(b);
		
		//cout<< A <<" 	"<<B<<endl;
		if(A>B)
			cout<<"a"<<endl;
		else
			cout<<"b"<<endl;
	}
	return 0;
}
