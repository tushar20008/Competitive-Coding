#include <iostream>
#include <cstring>
#include <climits>
using namespace std;
int D[201][201];
int minDis(int Dist[], bool visited[],int N)
{
	int dis=INT_MAX, index;
	for(int i=0; i<N; i++)
	{
		if(!visited[i] && Dist[i]<=dis)
		{
			index=i;
			dis=Dist[i];
		}
	}
	return index;
}

void ShowPath(int i,int Track[],string name[],int Dest)
{
	if(i==Dest)
		cout<<name[Dest];
	else
	{
		ShowPath(Track[i],Track,name,Dest);
		cout<<" -> "<<name[i];
	}
		
}

int Find(string name[], int n, char place[], int j)  // fix this
{
	char temp[j];
	memset(temp,' ',sizeof(temp));
	for(int i=0; i<j; i++)
	{
		temp[i]=place[i];
	}
		
	string check(temp, j);
	for(int i=0; i<n; i++)
	{
		if(name[i].compare(check)==0)
			return i;  					// check n matching
	}
	return 1111;
}
int main()
{
	int n;
	while(cin>>n)
	{
		memset(D,0,sizeof(D));
		cin.get();
		string name[n];
		for(int i=0; i<n; i++)
		{
			char temp[20];
			gets(temp);
			name[i]=temp;
		}
		
		int m;
		cin>>m;
		cin.get();
		
		while(m--)
		{
			char Line[50],p1[20],p2[20];
			memset(p2,' ',sizeof(p2));
			gets(Line);
			int size=strlen(Line);
	
			int index1=0,index2=0,i=0;
			while(Line[i]!=':')
			{
				p1[i]=Line[i];
				i++;
				index1++;
			}
			i++;
			for(int j=0; j<size; j++)			// abc abd and abc c
			{
				p2[j]=Line[i];
				i++;				
				index2=Find(name,n,p2,j+1);
				if(index2!=1111)
					break;
			}
			index1=Find(name,n,p1,index1);
			//cout<<index1<<" "<<index2<<endl;
			i++;
			int d1=0;
			while(Line[i]!=' ' && i<size)
			{
				if(d1!=0)
				{
					d1*=10;
					d1+=(int)Line[i]-48;
				}
				else
					d1=(int)Line[i]-48;
				
				i++;
			}
			i++;
			int d2=0;
			while(Line[i]!=' ' && i<size)
			{
				if(d2!=0)
				{
					d2*=10;
					d2+=(int)Line[i]-48;
				}
				else
					d2=(int)Line[i]-48;
				i++;
			}
			D[index1][index2]=d1;
			if(d2!=0)
				D[index2][index1]=d2;
		}
		/*
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
				cout<<D[i][j]<<" ";
			cout<<endl;
		}
		*/
		char hall[]="hall", office[]="office";
		int H=Find(name,n,hall,4);
		int O=Find(name,n,office,6);
		int Dist[n],Track1[n];
		bool visited[n];
		memset(visited,0,sizeof(visited));
		for(int i=0; i<n; i++)
			Dist[i]=INT_MAX;
		Dist[O]=0;
		for(int i=0; i<n-1; i++)
		{
			int u=minDis(Dist,visited,n);
			visited[u]=true;
			for(int v=0; v<n;v++)
			{
				if (!visited[v] && D[u][v] && Dist[u] != INT_MAX && Dist[u]+D[u][v] < Dist[v])
            	{
            		Dist[v] = Dist[u] + D[u][v];
            		Track1[v]=u;
				}	
			}
		}	
		
	
		int Dist2[n],Track2[n];
		memset(visited,0,sizeof(visited));
		for(int i=0; i<n; i++)
			Dist2[i]=INT_MAX;
		Dist2[H]=0;
		for(int i=0; i<n-1; i++)
		{
			int u=minDis(Dist2,visited,n);
			visited[u]=true;
			for(int v=0; v<n;v++)
			{
				if (!visited[v] && D[u][v] && Dist2[u] != INT_MAX && Dist2[u]+D[u][v] < Dist2[v])
            	{
            		Dist2[v] = Dist2[u] + D[u][v];
            		Track2[v]=u;
				}	
			}
		}		
		cout<<Dist[H]+Dist2[O]<<endl;
		ShowPath(Track1[H],Track1,name,O);
		cout<<" -> ";
		ShowPath(O,Track2,name,H);
		cout<<endl<<endl;
	}				
	return 0;
}
