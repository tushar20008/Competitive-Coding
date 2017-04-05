#include <iostream>
#include <cstring>
#include <math.h>
#include <time.h>
using namespace	std;
#define MAXDIGITS 10000
#define PLUS 1
#define MINUS -1
typedef struct
{
	char digits[MAXDIGITS];
	int signbit,lastdigit;	
} bignum;

void sub_bignum(bignum a, bignum b, bignum &c);
void initialize_bignum(bignum &n)
{
	memset(n.digits,0,sizeof(n.digits));
	/*
	for(int i=0; i<MAXDIGITS; i++)
		n.digits[i]=(char)0;
	*/
	n.lastdigit=0;
	n.signbit=PLUS;
}

void zero_justify(bignum &n)
{
	while(n.lastdigit > 0 && n.digits[n.lastdigit]==0)
		n.lastdigit--;
	if(n.lastdigit==0 && n.digits[0]==0)
		n.signbit=PLUS;
}

void add_bignum(bignum a, bignum b, bignum &c)
{
	initialize_bignum(c);
	
	if(a.signbit==b.signbit)
		c.signbit=a.signbit;
	else
	{
		if(a.signbit==MINUS)
		{
			a.signbit=PLUS;
			sub_bignum(b,a,c);
			a.signbit=PLUS;
		}
		else
		{
			b.signbit=PLUS;
			sub_bignum(a,b,c);
			b.signbit=PLUS;
		}
		return;
	}
	c.lastdigit=max(a.lastdigit,b.lastdigit)+1;
	int carry=0;
	
	for(int i=0; i<=c.lastdigit; i++)
	{
		c.digits[i]=(char)((carry+a.digits[i]+b.digits[i])%10);
		carry=(carry+a.digits[i]+b.digits[i])/10;
	}
	zero_justify(c);
	
}

void digit_shift(bignum &n, int d)
{
	if(n.lastdigit==0 && n.digits[0]==0)
		return;
	
	for(int i=n.lastdigit; i>=0; i--)
		n.digits[i+d]=n.digits[i];
	
	for(int i=0; i<d; i++)
		n.digits[i]=0;
	
	n.lastdigit=n.lastdigit+d;
}

void mult_bignum(bignum a, bignum b, bignum &c)
{
	bignum tmp[11];
	initialize_bignum(c);
	initialize_bignum(tmp[0]);
	for(int i=1; i<10; i++)
		add_bignum(tmp[i-1],a,tmp[i]);

	for(int i=b.lastdigit; i>=0; i--)
	{
		
		add_bignum(c,tmp[(int)b.digits[i]],tmp[10]);
		c=tmp[10];
		if(i!=0)
			digit_shift(c,1);
	}
	c.signbit=a.signbit * b.signbit;
	zero_justify(c);
}

int compare_bignum(bignum a, bignum b)
{
	if(a.signbit==MINUS && b.signbit==PLUS)
		return PLUS;
	if(a.signbit==PLUS && b.signbit==MINUS)
		return MINUS;
	if(b.lastdigit>a.lastdigit)
		return PLUS*a.signbit;
	if(a.lastdigit>b.lastdigit)
		return MINUS*a.signbit;
	
	for(int i=a.lastdigit; i>=0; i--)
	{
		if(a.digits[i]>b.digits[i])
			return MINUS*a.signbit;
		if(b.digits[i]>a.digits[i])
			return PLUS*a.signbit;	
	}	
	return 0;
}
void sub_bignum(bignum a, bignum b, bignum &c)
{
	//cout<<"SIGN		"<<a.signbit<<" "<<b.signbit<<endl;
	int borrow, v, i;
	if(a.signbit==MINUS || b.signbit==MINUS)
	{
		b.signbit*=-1;
		add_bignum(a,b,c);
		b.signbit*=-1;
		return;
	}
	if(compare_bignum(a,b)==PLUS)
	{
		sub_bignum(b,a,c);
		c.signbit=MINUS;
		return;
	}
	c.lastdigit=max(a.lastdigit,b.lastdigit);
	borrow=0;
	
	for(int i=0; i<=c.lastdigit; i++)
	{
		v=a.digits[i]-b.digits[i]-borrow;
		if(a.digits[i]>0)
			borrow=0;
		if(v<0)
		{
			v=v+10;
			borrow=1;
		}
		c.digits[i]=(char)v%10;
	}
	zero_justify(c);
}

void div_bignum(bignum a, bignum b, bignum &c)
{
	bignum row, tmp;
	//int a_sign, b_sign;
	
	initialize_bignum(c);
	initialize_bignum(row);
	initialize_bignum(tmp);

	c.signbit=a.signbit*b.signbit;
	c.lastdigit=a.lastdigit;
	a.signbit=PLUS;
	b.signbit=PLUS;
	
	for(int i=a.lastdigit; i>=0; i--)
	{
		digit_shift(row,1);
		row.digits[0]=a.digits[i];
		c.digits[i]=0;
		while(compare_bignum(row,b)!=PLUS)
		{
			c.digits[i]++;
			sub_bignum(row,b,tmp);
			row=tmp;
		}
	}	
	zero_justify(c);
}

void int_to_bignum(int s, bignum &n)
{
	int i,t;
	
	if(s>=0) n.signbit=PLUS;
	else n.signbit=MINUS;

	n.lastdigit=0;
	
	/*
	for(i=0; i<MAXDIGITS; i++)
		n.digits[i]=(char)0;
	*/
	memset(n.digits,0,sizeof(n.digits));
	n.lastdigit=-1;
	t=abs(s);
	
	while(t>0)
	{
		n.lastdigit++;
		n.digits[n.lastdigit]=t%10;
		t=t/10;
	}	
	//cout<<n.lastdigit<<endl;
}

int main()			// Exponentiation
{
	ios_base::sync_with_stdio(false);					// These 2 Lines to increase I/O Speed
    cin.tie(NULL); 
    int N;
    while(cin>>N)
    {
    	long u=clock();
    	bignum X,temp;
    	int_to_bignum(1,X);
    	for(int i=2; i<=N; i++)
    	{
    		int_to_bignum(i,temp);
    		mult_bignum(X,temp,X);
		}
    	cout<<N<<"!"<<endl;
    	for(int i=X.lastdigit; i>=0; i--)
				cout<<(int)X.digits[i];
		cout<<endl;
		long v=clock();
		cout<<(float) (v-u)/CLOCKS_PER_SEC<<endl;
	}
	return 0;
}
