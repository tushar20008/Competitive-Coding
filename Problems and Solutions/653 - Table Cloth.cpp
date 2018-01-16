#include <iostream>
using namespace std;

int A[51][51];
int best=0,Si,Sj,counter;

void PutCloth(int r, int c)
{
	if(counter==1)
	{
		for(int k=0; k<Si+1; k++)
			for(int m=0; m<Sj+1; m++)
				if(A[k][m]==0)
					A[k][m]=2;	
	}
	else if(counter==2)
	{
		for(int k=Si; k<r; k++)
			for(int m=0; m<Sj+1; m++)
				if(A[k][m]==0)
					A[k][m]=2;	
	}
	else if(counter==3)
	{
		for(int k=0; k<Si+1; k++)
			for(int m=Sj; m<c; m++)
				if(A[k][m]==0)
					A[k][m]=2;	
	}
	else if(counter==4)
	{
		for(int k=Si; k<r; k++)
			for(int m=Sj; m<c; m++)
				if(A[k][m]==0)
					A[k][m]=2;	
	}
	best=0;
}

void TryCloth(int i, int j, int r, int c)
{
	int c1=0,c2=0,c3=0,c4=0;
	
	for(int k=0; k<i+1; k++)
		for(int m=0; m<j+1; m++)
			if(A[k][m]==0)
				c1++;
	
	for(int k=i; k<r; k++)
		for(int m=0; m<j+1; m++)
			if(A[k][m]==0)
				c2++;
			
	for(int k=0; k<i+1; k++)
		for(int m=j; m<c; m++)
			if(A[k][m]==0)
				c3++;
	
	for(int k=i; k<r; k++)
		for(int m=j; m<c; m++)
			if(A[k][m]==0)
				c4++;
	
	int localbest=max(c1,c2);
		localbest=max(localbest,c3);
		localbest=max(localbest,c4);
			
	if(localbest>best)
	{
		Si=i;
		Sj=j;
		best=localbest;
		
		if(best==c1)
			counter=1;
		else if(best==c2)
			counter=2;
		else if(best==c3)
			counter=3;
		else if(best==c4)
			counter=4;
	}		
	//cout<<c1<<c2<<c3<<c4<<best<<counter<<endl;
}

void FindSticker(int r, int c)
{
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			if(A[i][j]==1)
				TryCloth(i,j,r,c);
	PutCloth(r,c);
}

bool Check(int r, int c)
{
	FindSticker(r,c);
	for(int i=0; i<r; i++)
		for(int j=0; j<c; j++)
			if(!A[i][j])
				return false;
	return true;
}

int main()
{
	int r,c;
	while(cin>>r>>c)
	{
		int cloth=0;
		if(r==0 && c==0)
			break;
		
		for(int i=0; i<r; i++)
			for(int j=0; j<c; j++)
				cin>>A[i][j];
		
		bool covered = false;
		
		while(!covered)
		{
			cloth++;
			covered=Check(r,c);
		}
		cout<<cloth<<endl;
	}
	return 0;
}
