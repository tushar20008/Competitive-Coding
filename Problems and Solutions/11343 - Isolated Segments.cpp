#include <iostream>
#include <cstring>
using namespace std;

struct Point
{
    int x,y;
};

bool onSegment(Point A, Point B, Point C)
{
    if (B.y <= max(A.y, C.y) && B.y >= min(A.y, C.y) &&
		B.x <= max(A.x, C.x) && B.x >= min(A.x, C.x) )
       return true;
   
  	 return false;
}

int orientation(Point A, Point B, Point C)
{
    int val = ((B.y-A.y)*(C.x-B.x))-((B.x-A.x)*(C.y-B.y));
 
    if (val == 0) 
		return 0; 
 	else if(val > 0)
 		return 1;
 	else
 		return 2;
    //return (val > 0)? 1: 2; 
}
 
bool Intersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2), o2 = orientation(p1, q1, q2),
		o3 = orientation(p2, q2, p1), o4 = orientation(p2, q2, q1);
 
    if (o1 != o2 && o3 != o4)
        return true;
 
    if (o1 == 0 && onSegment(p1, p2, q1))
		return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) 
		return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) 
		return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) 
		return true;
    return false; 
}

int main()
{
	int N;
	cin>>N;
	while(N--)
	{
		int M;
		cin>>M;
		Point P[M], Q[M];
		bool I[M];
		memset(I,0,sizeof(I));
		for(int i=0; i<M; i++)
			cin>>P[i].x>>P[i].y>>Q[i].x>>Q[i].y;
		int isolated=0;
		for(int i=0; i<M-1; i++)
			for(int j=i+1; j<M; j++)
				if(Intersect(P[i],Q[i],P[j],Q[j]))
				{
					I[i]=true;
					I[j]=true;
				}
		for(int i=0; i<M; i++)
			if(!I[i])
				isolated++;
		cout<<isolated<<endl;
	}
	return 420;
}
