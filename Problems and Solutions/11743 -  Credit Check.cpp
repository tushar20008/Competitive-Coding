#include <iostream>
using namespace std;

int addDigit(int x)
{
	int returnValue = 0;
	
	while(x>0)
	{
		returnValue += x % 10;
		x /= 10;  
	}
	
	return returnValue;
}

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int ans = 0;
		int A;
		
		for(int i=0; i<4; i++)
		{
			cin>>A;
			
			bool isLast = true;
			while(A>0)
			{
				int digit = A % 10;
				A /= 10;
				
				if(isLast)
				{
					ans += digit;
					isLast = false;
				}
				else			
				{
					ans += addDigit(2*digit);
					isLast = true;	
				}
			}
		}	
		
		if(ans % 10)
			cout<<	"Invalid"	<<	endl;
		else
			cout<<	"Valid"	<<	endl;
	}
}
