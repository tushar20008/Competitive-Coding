#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int A[5][2];
struct Point
{
    int x;
    int y;
};
bool NotTriangle(Point P[])
{
	float s1=sqrt((P[1].x-P[2].x)*(P[1].x-P[2].x)+(P[1].y-P[2].y)*(P[1].y-P[2].y));
	float s2=sqrt((P[3].x-P[2].x)*(P[3].x-P[2].x)+(P[3].y-P[2].y)*(P[3].y-P[2].y));
	float s3=sqrt((P[1].x-P[3].x)*(P[1].x-P[3].x)+(P[1].y-P[3].y)*(P[1].y-P[3].y));
	if(s1+s2<=s3)
		return true;
	if(s2+s3<=s1)
		return true;
	if(s3+s1<=s2)
		return true;
	return false;
}

float area(int x1, int y1, int x2, int y2, int x3, int y3)
{
	float A=(x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0;
	if(A>=0)
		return A;
	else
		return -A;
}

bool Inside(Point P[])
{
   float A  = area (P[1].x, P[1].y, P[2].x, P[2].y, P[3].x, P[3].y);
   float A1 = area (P[0].x, P[0].y, P[2].x, P[2].y, P[3].x, P[3].y);
   float A2 = area (P[1].x, P[1].y, P[0].x, P[0].y, P[3].x, P[3].y);
   float A3 = area (P[1].x, P[1].y, P[2].x, P[2].y, P[0].x, P[0].y);
   return (A == A1 + A2 + A3);
}

int main()
{
	int s1;
	while(cin>>s1)
	{
		int Set1[100001][2];
		for(int i=0; i<s1; i++)
			cin>>Set1[i][0]>>Set1[i][1];
		int s2;
		cin>>s2;
		while(s2--)
		{
			Point P[4];
			bool found=false;
			cin>>P[0].x>>P[0].y;
			for(int i=0; i<s1; i++)
			{
				for(int j=0; j<s1; j++)
				{
					if(i==j)
						continue;
					for(int k=0; k<s1; k++)
					{
						if(k==i || k==j)
							continue;
						
						P[1].x=Set1[i][0];
						P[1].y=Set1[i][1];
						P[2].x=Set1[j][0];
						P[2].y=Set1[j][1];
						P[3].x=Set1[k][0];
						P[3].y=Set1[k][1];
						
						if(NotTriangle(P))
							continue;
						if(Inside(P))
						{
							found=true;
							break;
						}
					}
					if(found)
						break;
				}
				if(found)
					break;
			}
			if(found)
				cout<<"inside"<<endl;
			else
				cout<<"outside"<<endl;
		}
		return 420;
	}
}
