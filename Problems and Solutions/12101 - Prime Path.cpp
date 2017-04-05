#include <iostream>
#include <cstring>		
#include <queue>
using namespace std;
int P[1062][2],pos=0;
int counter=1;
int isprime(int n)
{
	if(n%2==0 || n%3==0 || n%5==0 || n%7==0 || n%11==0 || n%13==0)
		return false;
		
	for(int i=17; i<n; i++)
		if(n%i==0)
			return false;
	
	return true;
}

bool Search(int n)
{
	for(int i=0; i<pos+1; i++)
	{
		if(P[i][0]==n)
			return false;
		if(P[i][0]==0)
			return true;
	}
	return true;
}

void BFS(int start, int &finish)
{
	int n[4], temp;
	P[pos][0]=start;
	P[pos][1]=0;
	
	int change[] = {0,1,2,3,4,5,6,7,8,9};
    
    queue<int>Q;
    Q.push(start);
    Q.push(11);
    while(!Q.empty())
    {
        int u=Q.front();
        if(u==11)
        {
        	counter++;
        	Q.pop();
        	Q.push(11);
        	u=Q.front();
		}
        start=u;
        Q.pop();
        for(int k=0; k<4; k++)
        {
        	temp=start;
        	for(int i=3; i>=0; i--)
			{		
				n[i]=temp%10;
				temp=temp/10;
			}
        	for(int m=0;m<10;m++)
        	{
        
        		n[k]=change[m];
        		u=n[0]*1000+n[1]*100+n[2]*10+n[3];
        		if(isprime(u) && Search(u) && u>999)
				{
					pos++;
					P[pos][0]=u;
					P[pos][1]=counter;
					Q.push(u);
					
					if(u==finish)
					{
						cout<<counter<<endl;
						return;
					}	
				}
            }
        }
	}
	cout<<"Impossible"<<endl;	
}

int main()
{
	int n;
	cin>>n;
	for(int t=0; t<n; t++)
	{
		int start,finish;
		cin>>start>>finish;
		if(start==finish)
			cout<<0<<endl;	
		else
		{
			pos=0;
			counter=1;
			memset(P,0,sizeof(P));
			BFS(start,finish);	
		}
	}
	return 0;
}

