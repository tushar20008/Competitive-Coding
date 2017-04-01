#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int T;
	cin>>T;
	for(int k=1; k<=T; k++)
	{
		int N;
		cin>>N;
		int A[101][2], index=0;
		memset(A,-1,sizeof(A));
		while(N--)
		{
			int x;
			cin>>x;
			bool found=false;
			for(int i=0; i<index; i++)
				if(A[i][0]==x)
				{
					found=true;
					A[i][1]++;
					break;
				}
			if(!found)
			{
				A[index][0]=x;
				A[index++][1]=1;
			}
		}
		int ans=-1,F=-1;
		for(int i=0; i<index; i++)
			if(A[i][1]>F)
			{
				F=A[i][1];
				ans=A[i][0];
			}
		cout<<"Item #"<<k<<": Most likely price is "<<ans<<" cents."<<endl;
		//if(k!=T)
			cout<<endl;
	}
}
