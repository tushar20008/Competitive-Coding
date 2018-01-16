#include <iostream>		
#include <cstring>
using namespace std;
int O[65][20];
struct Var
{
	string name;
	int bytes,size, ind;
	char B[500];
	Var()
	{
		ind=0;
	}
	void Store()
	{
		string A;
		cin>>A;
		for(int i=0; i<A.size(); i++)
			B[ind++]=A[i];
	}
	void Output()
	{
		int Ans[20];
		memset(Ans,0,sizeof(Ans));
		int p=0;
		for(int i=ind-1; i>=0; i--)
		{
			if(B[i]=='1')
			{
				for(int j=0; j<20; j++)
					Ans[j]+=O[p][j];
			}
			for(int j=0; j<20; j++)
				if(Ans[j]>9)
				{
					Ans[j+1]=Ans[j+1]+(Ans[j]/10);
					Ans[j]=Ans[j]%10;
				}
			p++;
		}	
		bool zero=true;
		for(int i=19; i>=0; i--)
		{
			if(Ans[i]==0 && zero)
				continue;
			else
			{
				zero=false;
				cout<<Ans[i];
			}
		}	
		if(zero)
			cout<<0;	
	}
};

int main()
{
	memset(O,0,sizeof(O));
	O[0][0]=1;
	O[1][0]=2;
	for(int i=2; i<65; i++)
	{
		for(int j=0; j<20; j++)
			O[i][j]=2*O[i-1][j];
		for(int j=0; j<20; j++)
			if(O[i][j]>9)
			{
				O[i][j+1]=O[i][j+1]+(O[i][j]/10);
				O[i][j]=O[i][j]%10;
			}
	}/*
	for(int i=0; i<65; i++)
	{
		for(int j=19; j>=0; j--)
			cout<<O[i][j];
		cout<<endl;	
	}*/	
	int b,v;
	while(cin>>b>>v)
	{
		
		Var V[v];
		for(int i=0; i<v; i++)
			cin>>V[i].name>>V[i].size;
		for(int i=0; i<v; i++)
			for(int j=0; j<V[i].size; j++)
				V[i].Store();
		int T;
		cin>>T;
		for(int i=0; i<T; i++)
		{
			string A;
			cin>>A;
			cout<<A<<"=";
			for(int j=0; j<v; j++)
				if(V[j].name.compare(A)==0)
				{
					V[j].Output();
					break;
				}
			cout<<endl;	
		}
	}
	return 0;
}
