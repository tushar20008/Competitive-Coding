#include <iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		string A;
		cin>>A;
		
		int sum = 0;
		int charValue = (A[0]-64) % 11;
		
		if(charValue)
			sum += charValue * (9-1);
		else
			sum += 11 * (9-1);
		
		
		for(int i=1; i<7; i++)
		{
			sum += (A[i]-48) * (8-i);
		}	
		
		int check = (11 - (sum % 11)) % 11;
		int expectedCheck = A[8] - 48;
		
		if(A[8] == 'X')
			expectedCheck = 10;
	 
		cout<<A<<" ";
		if(check == expectedCheck)
			cout<<"Good"<<endl;
		else if(check == 10)
			cout<<"X"<<endl;
		else
			cout<<check<<endl;	
	}
	return 0;
}
