#include <iostream>		// Memory Limit Exceed
#include <cstring>
using namespace std;
int main()
{
	int A[30];
	for(int i=1; i<4; i++)
		A[i]=i;
	for(int i=1; i<4; i++)
		A[3+i]=i;
	for(int i=1; i<4; i++)
		A[6+i]=i;	
	for(int i=1; i<4; i++)
		A[9+i]=i;	
	for(int i=1; i<4; i++)
		A[12+i]=i;	
	for(int i=1; i<5; i++)
		A[15+i]=i;	
	for(int i=1; i<4; i++)
		A[19+i]=i;	
	for(int i=1; i<5; i++)
		A[22+i]=i;		
	/*
	for(int i=1; i<27; i++)
		cout<<A[i]<<endl;*/
	int T;
	cin>>T;
	char C[101];
	char garbage=getchar();
	for(int t=1; t<=T; t++)
	{
		cin.getline(C,101);
		int ans=0;
		for(int i=0; i<strlen(C); i++)
			if(C[i]==' ')
				ans++;
			else
			{
				ans+=A[C[i]-96];
				//cout<<C[i]<<" "<<C[i]-96<<" "<<A[C[i]-96]<<endl;
			}	
		cout<<"Case #"<<t<<": "<<ans<<endl;
	}
}
