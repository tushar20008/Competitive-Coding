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
		Point Start,End;
		Point Sides[4];
		cin>>Start.x>>Start.y>>End.x>>End.y;
		int xleft ,ytop, xright, ybottom;
		cin>>xleft>>ytop>>xright>>ybottom;
		if(xleft>xright)
		{
			int temp=xleft;
			xleft=xright;
			xright=temp;
		}
		if(ybottom>ytop)
		{
			int temp=ytop;
			ytop=ybottom;
			ybottom=temp;
		}
		Sides[0].x=xleft;
		Sides[0].y=ytop;
		Sides[1].x=xleft;
		Sides[1].y=ybottom;
		Sides[2].x=xright;
		Sides[2].y=ytop;
		Sides[3].x=xright;
		Sides[3].y=ybottom;
		
		if(Start.x>=xleft && Start.x<=xright && Start.y>=ybottom && Start.y<=ytop)
		{
			cout<<"T"<<endl;
			continue;
		}
		if(End.x>=xleft && End.x<=xright && End.y>=ybottom && End.y<=ytop)
		{
			cout<<"T"<<endl;
			continue;
		}
		if(Intersect(Start,End,Sides[0],Sides[1]))
		{
			cout<<"T"<<endl;
			continue;
		}
		if(Intersect(Start,End,Sides[0],Sides[2]))
		{
			cout<<"T"<<endl;
			continue;
		}
		if(Intersect(Start,End,Sides[1],Sides[3]))
		{
			cout<<"T"<<endl;
			continue;
		}
		if(Intersect(Start,End,Sides[2],Sides[3]))
		{
			cout<<"T"<<endl;
			continue;
		}
		cout<<"F"<<endl;
	}
}
