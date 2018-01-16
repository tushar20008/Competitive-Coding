#include <iostream>  // wrong ans
#include <cstring>
using namespace std;

int Length (char* A, char* B, int a, int b)
{
	int temp[a+1][b+1];
	
	for(int i=0; i<a+1; i++)
	{
		for(int j=0; j<b+1; j++)
		{
			if(i==0 || j==0)
				temp[i][j]=0;
			
			else if(A[i-1]==B[j-1])
				temp[i][j]=temp[i-1][j-1] + 1;
			
			else
				temp[i][j]=max(temp[i-1][j],temp[i][j-1]);
				
		}
	}
	return temp[a][b];
}

int main()
{
	char A[1001], B[1001];
	int T=1;
	while(cin.getline(A,1001))
	{
		if(A[0]=='#')
			break;
		cin.getline(B,1001);
		int a=strlen(A);
		int b=strlen(B);
		cout<<"Case #"<<T++<<": you can visit at most "<<Length(A,B,a,b)<<" cities."<<endl;
	}
	return 0;
}
