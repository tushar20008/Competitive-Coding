#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
int main()
{
	char A[25], B[25];
	while(cin.getline(A,25))
	{
		cin.getline(B,25);
		int a=0,b=0;
		for(int i=0; i<strlen(A); i++)
			if(A[i]>='a' && A[i]<='z')
				a+=A[i]-'a'+1;
			else if(A[i]>='A' && A[i]<='Z')
				a+=A[i]-'A'+1;
		for(int i=0; i<strlen(B); i++)
			if(B[i]>='a' && B[i]<='z')
				b+=B[i]-'a'+1;
			else if(B[i]>='A' && B[i]<='Z')
				b+=B[i]-'A'+1;
		while(a>9)
		{
			int tmp=0;
			while(a!=0)
			{
				tmp+=a%10;
				a=a/10;
			}
			a=tmp;
		}
		while(b>9)
		{
			float tmp=0;
			while(b!=0)
			{
				tmp+=b%10;
				b=b/10;
			}
			b=tmp;
		}
		if(a>=b)
			cout<<fixed<<setprecision(2)<<(b*1.0/a)*100<<" %"<<endl;
		else 
			cout<<fixed<<setprecision(2)<<(a*1.0/b)*100<<" %"<<endl;
	}
}
