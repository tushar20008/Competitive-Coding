#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int A[101][5];
	memset(A,0,sizeof(A));
	A[1][0]=1;
	A[2][0]=2;
	A[3][0]=3;
	A[4][0]=1;
	A[4][1]=1;
	A[5][1]=1;
	A[6][0]=1;
	A[6][1]=1;
	A[7][0]=2;
	A[7][1]=1;
	A[8][0]=3;
	A[8][1]=1;
	A[9][0]=1;
	A[9][2]=1;
	A[10][2]=1;
	for(int i=11; i<=40; i++)
	{
		for(int j=0; j<5; j++)
			A[i][j]=A[i-10][j];
		if(i!=40)
			A[i][2]++;
		else
		{
			A[i][3]=1;
			A[i][2]=1;
		}
	}
	for(int i=41; i<=50; i++)
	{
		for(int j=0; j<5; j++)
			A[i][j]=A[i-30][j];
		if(i==50)
		{
			A[i][3]=1;
			A[i][2]=0;
		}
		else
			A[i][3]++;
	}
	for(int i=51; i<=90; i++)
	{
		for(int j=0; j<5; j++)
			A[i][j]=A[i-50][j];
		if(i!=90)
			A[i][3]++;
		else 
		{
			A[i][4]=1;
			A[i][3]=0;
		}
	}
	for(int i=91; i<=100; i++)
	{
		for(int j=0; j<5; j++)
			A[i][j]=A[i-80][j];
		A[i][4]++;
		if(i==100)
			A[i][2]=0;
	}
	int N;
	while(cin>>N)
	{
		if(N==0)
			break;
		int i=0,v=0, x=0, l=0, c=0;
		for(int j=1; j<=N; j++)
		{
			i+=A[j][0];
			v+=A[j][1];
			x+=A[j][2];
			l+=A[j][3];
			c+=A[j][4];
		}
		cout<<N<<": "<<i<<" i, "<<v<<" v, "<<x<<" x, "<<l<<" l, "<<c<<" c"<<endl;
	}
}
