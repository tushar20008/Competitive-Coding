#include <iostream>
#include <cstring>
using namespace std;
int main()
{
	int T;
	cin>>T;
	char garb=getchar();
	while(T--)
	{
		char A[101];
		cin.getline(A,101);
		int C=0;
		char c;
		string F="for", a="and", t="the";
		for(int i=0; i<strlen(A); i++)
		{
			if(C==0)
				c=A[i];
			if(A[i]==' ' || i==strlen(A)-1)
			{
				if(i==strlen(A)-1)
					C++;
				if(C>2)
				{	
					if(C==3)
					{
						C=0;
						int ind=0, x=0,y=0,z=0;
						for(int j=i-3; j<i; j++)
						{
							if(A[j]==F[ind] || A[j]==toupper(F[ind]))
								x++;
							if(A[j]==a[ind] || A[j]==toupper(a[ind]))
								y++;
							if(A[j]==t[ind] || A[j]==toupper(t[ind]))
								z++;
							ind++;
						}
						if(x==3 || y==3 || z==3)
							continue;
					}
					cout<<(char)toupper(c);
				}
				C=0;
			}
			else
				C++;
		}
		cout<<endl;
	}
}
