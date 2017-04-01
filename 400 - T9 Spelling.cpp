#include <iostream>			
#include <cstring>
using namespace std;
int main()
{	
	int V[30], T[30], value=2, times=1;
	for(int i=1; i<24; i++)
		for(int j=i; j<i+3; j++)	
		{
			V[j]=value;
			T[j]=times++;
			if(times>3)
				times=1;
			if(j==i+2)
			{
				value++;
				if(value==7)
				{
					for(int k=j+1; k<j+5; k++)
					{
						V[k]=value;
						T[k]=times++;
					}	
					value++;
					i=i+4;
					times=1;
				}
				i=i+2;
				break;
			}
		}
	V[26]=9;
	T[26]=4;/*
	for(int i=1; i<27; i++)
		cout<<V[i]<<" "<< T[i] <<endl;	*/
	int N;
	cin>>N;
	char c;
	c=getchar();
	for(int i=1; i<=N; i++)
	{
		char A[1001];
		cin.getline(A,1001);
		int D=-1;
		cout<<"Case #"<<i<<": ";
		for(int i=0; i<strlen(A); i++)
		{
			if(A[i]==' ')
			{
				if(D==0)
					cout<<" ";
				else 
					D=0;
				cout<<0;
				continue;
			}
			if(V[A[i]-96]==D)
				cout<<" ";
				
			D=V[A[i]-96];
			//cout<<endl<<D<<" "<<T[A[i]-96]<<endl;
			for(int j=0; j<T[A[i]-96]; j++)
				cout<<D;
		}
		cout<<endl;
	}
}
