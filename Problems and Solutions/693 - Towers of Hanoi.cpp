#include <iostream>
using namespace std;

int main()
{
	int n,move;
	while(cin>>n)
	{
		int block=1;
		int A[n],B[n],C[n];
		for(int i=0; i<n; i++)
		{
			A[i]=block*10;
			B[i]=0;
			C[i]=0;
			block++;
		}
		
		move=0;
		
		int a=n-1,b=0,c=0,last=0;
		while(C[n-1]!=n*10)
		{
			if(B[b]>C[c] && last!=4)
			{
				if(C[c]!=0)
					c++;
				C[c]=B[b];
				B[b]=0;
				if(b!=0)
					b--;
				last=1;
				//cout<<"Loop B-C"<<endl;
			}
			
			else if(B[b]>A[a] && last!=3)
			{
				if(A[a]!=0)
					a++;
				A[a]=B[b];
				B[b]=0;
				if(b!=0)
					b--;
				last=2;
				//cout<<"Loop B-A"<<endl;
			}
			
			else if(B[b]<A[a] && last!=2)
			{
				if(B[b]!=0)
					b++;
				B[b]=A[a];
				A[a]=0;
				if(a!=0)
					a--;
				last=3;
				//cout<<"Loop A-B"<<endl;
			}
			
			else if(C[c]>B[b] && last!=1)
			{
				if(B[b]!=0)
					b++;
				B[b]=C[c];
				C[c]=0;
				if(c!=0)
					c--;
				last=4;
				//cout<<"Loop C-B"<<endl;
				
			}
			
			if(last!=0)
				move++;
			//cout<<move<<endl;
		}
		cout<<move<<endl<<endl;
	}
	return 0;
}
