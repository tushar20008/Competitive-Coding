#include <iostream>
#include <cstring>    
using namespace std; //abcxdefxghix abcyydefyyghiyy yyyyww hhqkkkj ab b b ab b cd abcde bcfge
int DP[22][22];

void Print(char A[], char B[], int a, int b)
{
	char s[100];
	int index=1;
	//memset(s,' ',sizeof(s));
	s[0]='E';
	while(true)
	{
		//cout<<b<<" "<<a<<endl;
		if(a==0 || b==0)
		{
			//cout<<b<<" "<<a<<endl;
			if(b==0)	// delete remaining
			{
				while(a)
				{
					if(a-1<9)
    				{
    					s[index++]=a+48;
    					s[index++]='0';
					}
					else
					{
						s[index++]=a%10+48;
    					s[index++]=a/10+48;
					}
					s[index++]=A[a-1];
    				s[index++]='D';
    				a--;
				}	
			}
			else if(a==0)  // insert remaining
			{
				while(b)
				{
						s[index++]='0';   
    					s[index++]='0';
					
						s[index++]=B[b-1];
    					s[index++]='I';
    					b--;
				}
			} 
			break;
		}
		else if (A[a-1] == B[b-1]) 
		{
           a--;
           b--;
    	}
    	else if(DP[b][a] == DP[b-1][a-1]+1)
    	{
    		if(a-1<9)
    		{
    			s[index++]=a+48;
    			s[index++]='0';
			}
			else
			{
				s[index++]=a%10+48;
    			s[index++]=a/10+48;
			}
    		s[index++]=B[b-1];
    		s[index++]='C';
    		a--;
    		b--;
		}
    	else if(DP[b][a] == DP[b-1][a]+1)
    	{
    		if(a-1<9)
    		{
    			s[index++]=a+48;   
    			s[index++]='0';
			}
			else
			{
				s[index++]=a%10+48;   
    			s[index++]=a/10+48;
			}
			s[index++]=B[b-1];
    		s[index++]='I';
    		b--;
		}
		else if(DP[b][a] == DP[b][a-1]+1)
    	{
    		if(a-1<9)
    		{
    			s[index++]=a+48;
    			s[index++]='0';
			}
			else
			{
				s[index++]=a%10+48;
    			s[index++]=a/10+48;
			}
			s[index++]=A[a-1];
    		s[index++]='D';
    		a--;
		}
	}
	int insert=0,del=0;
	for(int i=index-3; i>=0;)
	{
		if(s[i+2]=='I')
			insert++;
		int temp=((int)s[i]-48)*10 + ((int)s[i-1]-48) + insert + del;
		s[i-1]=temp%10 + 48;
		s[i]=temp/10 + 48;
		
		if(s[i+2]=='D')
			del--;
		i-=4;	
	}
	for(int i=index-1; i>=0; i--)
		cout<<s[i];
	cout<<endl;
}

void Edit(char A[], char B[], int a, int b)
{
	for(int i=0; i<a+1; i++)
		DP[0][i]=i;
	for(int i=0; i<b+1; i++)
		DP[i][0]=i;
	
	for(int i=1; i<b+1; i++)
	{
		for(int j=1; j<a+1; j++)
		{
			if(A[j-1]==B[i-1])
				DP[i][j]=DP[i-1][j-1];
			else
			{
				DP[i][j]=min(DP[i-1][j],DP[i][j-1]);
				DP[i][j]=min(DP[i][j],DP[i-1][j-1]);
				DP[i][j]++;	
			}
		}
	}
	/*
	for(int i=0; i<b+1; i++)
	{
		for(int j=0; j<a+1; j++)
		{
			cout<<DP[i][j]<< " ";
		}
		cout<<endl;
	}*/
	Print(A,B,a,b);	
}

int main()
{
	char A[21],B[21];
	while(cin>>A)
	{
		if(A[0]=='#')        
			break;
		cin>>B;
		int a=strlen(A);
		int b=strlen(B);
		//cout<<a<<" "<<b<<endl; 
		Edit(A,B,a,b);
	}
	return 0;
}
