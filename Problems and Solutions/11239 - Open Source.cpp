#include <iostream>
#include <cstring>
using namespace std;

struct Project
{
	string *A;
	bool C[10000];
	int index;
	string Name;
	int count;
	Project()
	{
		A= new string[10000];
		memset(C,0,sizeof(C));
		index=0;
	}
	void Count()
	{
		count=0;
		for(int i=0; i<index; i++)
			if(!C[i])
				count++;
	}
};

int main()
{
	Project P[100];
	int I=-1;
	string W;
	while(getline(cin, W))
	{
		if(W[0]=='0')
			break;
		else if(W[0]=='1')
		{
			int M[I+1][2];
			for(int i=0; i<=I; i++)
			{
				P[i].Count();
				M[i][0]=P[i].count;
				M[i][1]=i;
				//cout<<P[M[i][1]].Name<<" "<<M[i][0]<<endl;
			}
			for(int i=0; i<=I; i++)
				for(int j=0; j<=I-1; j++)
					if((M[j][0]<M[j+1][0]) || (M[j][0]==M[j+1][0] && P[M[j][1]].Name.compare(P[M[j+1][1]].Name)>0))
					{
						int t1=M[j][0];
						int t2=M[j][1];
						M[j][0]=M[j+1][0];
						M[j][1]=M[j+1][1];
						M[j+1][0]=t1;
						M[j+1][1]=t2;
					}
			for(int i=0; i<=I; i++)
			{
				cout<<P[M[i][1]].Name<<" "<<M[i][0]<<endl;
				P[i].index=0;
				memset(P[i].C,0,sizeof(P[i].C));
			}
			I=-1;
		}
		else if(W[0]>='A' && W[0]<='Z')
		{
			P[++I].Name=W;
		}
		else
		{
			bool found =false;
			for(int i=0; i<I; i++)
				for(int j=0; j<P[i].index; j++)
					if(P[i].A[j].compare(W)==0)
					{
						//cout<<"Repeat		"<<i<<"		"<<j<<endl;
						P[i].C[j]=true;
						found=true;
					}	
			if(found)
				continue;
			found=false;
			for(int i=0; i<P[I].index; i++)
				if(P[I].A[i].compare(W)==0)
				{
					//cout<<"SAME"<<endl;
					found=true;
				}	
			if(!found)
			{
				P[I].A[P[I].index]=W;
				P[I].index++;	
			}
		}
	}
	return 0;
}
	
	
