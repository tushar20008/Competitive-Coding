#include <iostream>
using namespace std;
int main()
{
		ios_base::sync_with_stdio(false);
    cin.tie(NULL); 

	int N;
	cin>>N;
	for(int j=0; j<N; j++)
	{
		int L,h=0,l=0;
		cin>>L;
		int x,prev;
		for(int i=0; i<L; i++)
		{
			if(i==0)
				cin>>prev;
			else
			{
				cin>>x;
				if(x>prev)
					h++;
				else if(x<prev)
					l++;
				prev=x;
			}
		}
		cout<<"Case "<<j+1<<": "<<h<<" "<<l<<endl;
	}
	return 0;
}
