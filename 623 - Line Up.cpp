#include <iostream> // Lumberjacks 11942
using namespace std;
int main()
{
	int T;
	cin>>T;
	int A[10];
	cout<<"Lumberjacks:"<<endl;
	while(T--)
	{
		bool order=true;
		for(int i=0; i<10; i++)
			cin>>A[i];
		
		if(A[1]>A[0])
		{
			for(int i=1; i<10; i++)
				if(A[i-1]<A[i])
					continue;
				else
				{
					order=false;
					break;
				}
		}
		else if(A[1]<A[0])
		{
			for(int i=1; i<10; i++)
				if(A[i-1]>A[i])
					continue;
				else
				{
					order=false;
					break;
				}
		}
		else
			cout<<"EROR"<<endl;
		if(order)
			cout<<"Ordered"<<endl;
		else
			cout<<"Unordered"<<endl;
	}
}
