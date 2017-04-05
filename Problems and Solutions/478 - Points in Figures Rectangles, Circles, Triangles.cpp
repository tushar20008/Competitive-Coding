#include <iostream>
#include <math.h>
using namespace std;
 
double area(double x1, double y1, double x2, double y2, double x3, double y3)
{
	double A=(x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0;
   if(A>=0)
   	return A;
   	else
   		return -A;
}

struct point {
	double x;
	double y;
};
point operator-( const point a, const point b) {
	point r;
	r.x = a.x - b.x;
	r.y = a.y - b.y;
	return r;
}
double crossproduct( point a, point b ) {

	// a and b are vectors

	double x1, x2, y1, y2;
	x1 = a.x;
	x2 = b.x;
	y1 = a.y;
	y2 = b.y;

	return x1*y2 - y1*x2;
}


bool sameside(point p1, point p2,  point a, point b) {
	double cp1, cp2;
	
	cp1 = crossproduct(b-a, p1-a);
	cp2 = crossproduct(b-a, p2-a);
	
	// if results have the same sign, they are on the same side
	if ( (cp1 >= 0 && cp2 >= 0) || (cp1 < 0 && cp2 < 0)) {
		//cout << "ok" << endl;
		return true;
	}
	
	return 0;
}

bool point_in_triangle( point p,  point a, point b, point c) {
	return (sameside(p,a ,b,c) && sameside(p,b, a,c) && sameside(p,c, a,b));
}

struct Figure
{
	char type;
	double x1,x2,x3,x4,y1,y2,y3,y4, r;
	void Circle()
	{
		type='c';
		cin>>x1>>y1>>r;
	}
	void Rec()
	{
		type='r';
		cin>>x1>>y1>>x2>>y2;
		/*
		if(x1>x2)
		{
			double tmp=x1;
			x1=x2;
			x2=tmp;
		}
		if(y1>y2)
		{
			double tmp=y1;
			y1=y2;
			y2=tmp;
		}
		*/
	}
	void Tri()
	{
		type='t';
		cin>>x1>>y1>>x2>>y2>>x3>>y3;
	}
	bool Check(int P,double X, double Y)
	{
		if(type=='c')
		{
			if(pow((x1-X),2)+pow((y1-Y),2)<pow(r,2))
				return true;
			return false;
		}
		else if(type=='t')
		{
			point a,b,c,p;
			p.x=X;
			p.y=Y;
			a.x=x1;
			a.y=y1;
			b.x=x2;
			b.y=y2;
			c.x=x3;
			c.y=y3;
				if ( point_in_triangle( p,  a, b, c) == true ) {
				return true;
			}
			/*
			double A = area (x1, y1, x2, y2, x3, y3);
			double A1 = area (X, Y, x2, y2, x3, y3);
 			double A2 = area (x1, y1, X, Y, x3, y3);
 			double A3 = area (x1, y1, x2, y2, X, Y);
  			if (A == A1 + A2 + A3)
			{
				if(A1==0 || A2==0 || A3==0)
					return false;
				return true;
			}*/
			return false;
		}
		else
		{
			if(X>x1 && X<x2 && Y>y2 && Y<y1)
				return true;
			return false;
			/*
			double A=area(x1,y1,x1,y2,x2,y2);
			double A1=area(X,Y,x1,y1,x1,y2);
			double A2=area(x1,y1,X,Y,x2,y2);
			double A3=area(x2,y2,x1,y2,X,Y);
			if (A == A1 + A2 + A3)
			{
				if(A1==0 || A3==0)
					return false;
				return true;
			}
			A=area(x1,y1,x2,y1,x2,y2);
			A1=area(X,Y,x1,y1,x2,y1);
			A2=area(x1,y1,X,Y,x2,y2);
			A3=area(x2,y1,x2,y2,X,Y);
			if (A == A1 + A2 + A3)
			{
				if(A1==0 || A3==0)
					return false;
				return true;
			}
			//cout<<"							Where u looking?"<<endl;
			return false;
			*/
		}
	}
};

int main()
{
	Figure F[100];
	int I=0;
	char c;
	while(cin>>c)
	{
		if(c=='c')
			F[I++].Circle();
		else if(c=='r')
			F[I++].Rec();
		else if(c=='t')
			F[I++].Tri();
		else if(c=='*')
		{
			int P=0;
			double x,y;
			while ( cin >> x >> y && x != 9999.9 && y != 9999.9 )
			{
				P++;
				bool found=false;
				for(int i=0; i<I; i++)
					if(F[i].Check(P,x,y))
					{
						cout<<"Point "<<P<<" is contained in figure "<<i+1<<endl;
						found=true;
					}
				if(!found)
					cout<<"Point "<<P<<" is not contained in any figure"<<endl;
			}
			break;
		}
	}	
}
