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

void initialize_bignum(bignum &n)
{
	memset(n.digits,0,sizeof(n.digits));
	/*
	for(int i=0; i<MAXDIGITS; i++)
		n.digits[i]=(char)0;
	*/
	n.lastdigit=0;
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
	
	c.signbit=a.signbit;
	c.lastdigit=max(a.lastdigit,b.lastdigit)+1;
	//cout<<a.lastdigit<<" "<<b.lastdigit<<endl;
	int carry=0;
	
	for(int i=0; i<=c.lastdigit; i++)
	{
		//cout<<carry<<" "<<a.digits[i]<<" "<<b.digits[i]<<endl;
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
	//cout<<a.lastdigit<<"	"<<b.lastdigit<<endl;
	bignum tmp[11];
	initialize_bignum(c);
	initialize_bignum(tmp[0]);
	for(int i=1; i<10; i++)
	{
		add_bignum(tmp[i-1],a,tmp[i]);
		/*
		for(int j=tmp[i].lastdigit; j>=0; j--)
			cout<<(int)tmp[i].digits[j];
		cout<<endl;
		*/
	}
	for(int i=b.lastdigit; i>=0; i--)
	{
		//cout<<(int)b.digits[i]<<endl;
		add_bignum(c,tmp[(int)b.digits[i]],tmp[10]);
		c=tmp[10];
		/*
		for(int j=1; j<=b.digits[i]; j++)
		{
			add_bignum(c,a,tmp);
			c=tmp;
		}
		*/
		if(i!=0)
			digit_shift(c,1);
	}
	c.signbit=a.signbit * b.signbit;
	zero_justify(c);
}

void int_to_bignum(int s, bignum &n)
{
	int i,t;
	
	/*
	if(s>=0) n.signbit=PLUS;
	else n.signbit=MINUS;
	*/
	
	n.signbit=PLUS;
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
/*
bignum Exp2(bignum *temp, int x, int y)
{
	//cout<<x<<" "<<y<<endl;
   	if (y%2 == 0)
    {
    	mult_bignum(*temp,*temp,*temp);
    	return *temp;
	}
    else
    {
    	bignum x_big;
        int_to_bignum(x,x_big);
        mult_bignum(*temp,*temp,*temp);
        mult_bignum(*temp,x_big,*temp);
        return *temp;
	}
}
*/
/*
bignum Exp(bignum *temp, int x, int y)
{
	cout<<x<<" "<<y<<endl;
	if( y == 0)
    {
    	int_to_bignum(1,*temp);
		return *temp;
	}
    else
		*temp = Exp(temp,x, y/2);
	cout<<x<<" "<<y<<endl;
	if (y%2 == 0)
    {
    	long u=clock();
    	mult_bignum(*temp,*temp,*temp);
    	long v=clock();
		cout<<"MulT		"<<(float) (v-u)/CLOCKS_PER_SEC<<endl;	
    	return *temp;
	}
    else
    {
    	bignum x_big;
        int_to_bignum(x,x_big);
        mult_bignum(*temp,*temp,*temp);
        mult_bignum(*temp,x_big,*temp);
        return *temp;
	}	
	//return Exp2(temp, x, y);
}
*/
bignum FastExp(bignum *temp, int x, int y)
{
	if( y == 0)
    {
    	int_to_bignum(1,*temp);
		return *temp;
	}
	if( y == 1)
    {
    	int_to_bignum(x,*temp);
		return *temp;
	}
	*temp=FastExp(temp,x,y>>1);
  	mult_bignum(*temp,*temp,*temp);
  	if (y&1)
	{
		bignum x_big;
		int_to_bignum(x,x_big);
		mult_bignum(*temp,x_big,*temp);
	}
  	return *temp;
}
int main()			// Exponentiation
{
	ios_base::sync_with_stdio(false);					// These 2 Lines to increase I/O Speed
    cin.tie(NULL); 
	int n;
	string R;
	while(cin>>R>>n)
	{
		long u=clock();
		int required_number=0;
		int decimal_place=0;
		bool found=false;
		for(int i=0; i<R.size(); i++)
			if(R[i]!='.')
			{
				required_number=required_number*10+ (int)R[i] - 48;
				if(found)
					decimal_place++;	
			}
			else
				found=true;
				
		//cout<<decimal_place<<" 			"<<required_number<<endl;
		bignum ans;
		FastExp(&ans,required_number,n);
		decimal_place*=n;
		if(decimal_place-1 > ans.lastdigit)		// Maybe decimal_place -1
		{
			cout<<".";
			for(int i=0; i<decimal_place-ans.lastdigit-1; i++)
				cout<<0;
		}
		
		bool erase = false;
		/*
		for(int i=ans.lastdigit; i>decimal_place-1; i--)
			cout<<(int)ans.digits[i];
		
		int no_zero=0;
		if(decimal_place!=0)
		{
			for(int i=decimal_place-1; i>=0; i--)
				if(ans.digits[i]==char(0))
					no_zero++;
				else
					no_zero=0;
		}
		for(int i=decimal_place-1; i>=no_zero; i--)
			cout<<(int)ans.digits[i];
		*/	
		for(int i=ans.lastdigit; i>=0; i--)
		{
			if(i<=decimal_place-1 && ans.digits[i]==char(0) && decimal_place!=0)
			{
				erase=true;
				for(int j=i; j>=0; j--)
					if(ans.digits[j]!=char(0))
					{
						erase=false;
						break;	
					}	
			}
			if(erase)
				break;
			if(i==decimal_place-1)
				cout<<".";
			cout<<(int)ans.digits[i];
		}
	
		cout<<endl;
		long v=clock();
		//cout<<(float) (v-u)/CLOCKS_PER_SEC<<endl;
	}
	return 420;
}
