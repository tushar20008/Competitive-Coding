#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	cin>>n;
	char s[15],date[3],month[2],year[5];
	char name[n][15];
	int d[n],m[n],y[n];
	for(int i=0; i<n; i++)
	{
		cin.getline(s,15,' ');
		cin.getline(date,3,' ');  
		cin.getline(month,3,' ');
		cin.getline(year,5);
		
		int j=0;
		while(s[j]!='\0')
		{
			name[i][j]=s[j];
			j++;
		}
		
		d[i]=atoi(date);
		m[i]=atoi (month);
		y[i]=atoi(year);
	}
	
	int old=0,young=0;
	
	for(int i=1; i<n; i++)
	{
		
		
		if(y[old]>y[i])
		{
			old=i;
		}
		else if(y[old]==y[i])
		{
			if(m[old]>m[i])
				old=i;
			else if(m[old]==m[i])
			{
				if(d[old]>d[i])
					old=i;
			}
		}
		
		if(y[young]<y[i])
		{
			young=i;
		}
		else if(y[young]==y[i])
		{
			if(m[young]<m[i])
				young=i;
			else if(m[young]==m[i])
			{
				if(d[young]<d[i])
					young=i;
			}
		}
	}

	
	for(int k=0;name[young][k]!='\0';k++)
	{
		if(isalpha(name[young][k]))
		cout<<name[young][k];
	}
	
	cout<<endl;
	
	for(int j=0;name[old][j]!='\0';j++)
	{
		if(isalpha(name[old][j]))
		cout<<name[old][j];
	}
	
	cout<<endl;
	return 0;	
}
