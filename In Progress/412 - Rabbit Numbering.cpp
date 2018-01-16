#include <iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	
	for(int i=1; i<=T; i++)
	{
		int A[50], index = 0;
		
		while(true)
		{
			if (cin.get() == '\n')
				break;
			else
				cin>>A[index++];
		}
		
		for(int j=0; j<index; j++)
			for(int k=index-1; k>=1; k--)
				if(A[k-1]>A[k])
				{
					int temp = A[k];
					A[k] = A[k-1];
					A[k-1] = temp;
				}
		
		for(int j=0; j<index; j++)
			cout<<A[j]<<"	";
		cout<<endl;
	}
	
	return 0;
}
