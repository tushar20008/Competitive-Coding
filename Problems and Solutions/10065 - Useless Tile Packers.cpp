#include <iostream>
#include <cstring>
#include <iomanip>
#include <math.h>
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
 
double Area(int A[][2], int n)
{
	double area = 0.0;
 
    // Calculate value of shoelace formula
    int j = n - 1;
    for (int i=0; i<n; i++)
    {
        area += (A[j][0]+A[i][0])*(A[j][1]-A[i][1]);
        j=i;  // j is previous vertex to i
    }
 
    // Return absolute value
    area/=2;
    if(area >=0)
    	return area;
    else 
    	return -area;
}
double convexHull(Point P[], int n)
{
    //if (n < 3) return;
 	int A[1000][2];
    int L=0;
    for (int i = 1; i < n; i++)
        if (P[i].x < P[L].x)
            L = i;
 
 	int index=0;
    int p = L, q;
    do
    {
		A[index][0]=P[p].x;    
        A[index++][1]=P[p].y;
 
        q = (p+1)%n;
        for (int i = 0; i < n; i++)
        	if (orientation(P[p], P[i], P[q]) == 2)
               q = i;
 
        p = q;
 
    } while (p != L);  // While we don't come to first point
	return Area(A,index);
}

int main()
{
	int N, Tile=1;
	while(cin>>N)
	{
		if(N==0)
			break;
		
		Point P[500];
		int B[500][2];
		for(int i=0; i<N; i++)
		{
			cin>>P[i].x>>P[i].y;
			B[i][0]=P[i].x;
			B[i][1]=P[i].y;	
		}
		double total_area=convexHull(P,N);
		double Tile_area=Area(B,N);
		double ans=(total_area-Tile_area)*100/total_area;
		cout<<"Tile #"<<Tile++<<endl<<"Wasted Space = "<<fixed<<setprecision(2)<<ans<<" %"<<endl;
		cout<<endl;
	}
	return 0;
}

