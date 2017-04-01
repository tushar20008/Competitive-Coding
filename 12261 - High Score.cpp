#include <iostream>
#include <cstring> 
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		char s[1001];
		cin>>s;
		int len=strlen(s);
		int move=0;
		for(int j=0; j<len; j++)
			move+=min(s[j]-'A', 26-(s[j]-'A'));
		//cout<<move<<endl;
		int forw=-1,back=0,count=0;
	
		if(move==0)
			cout<<move<<endl;
		else
		{
			for(int j=0; j<len; j++)
			{
				if(s[j]!='A')
				{
					count++;
					if(forw==-1)
					{
						forw=j;
						back=len-j;
					}
					else
					{
						if(back==0)
							back=0xfffffff;
						else
						{
							back=min(back,forw+forw+len-j);
							back=min(back,forw+len-j+len-j);
							forw=j;
							//cout<<back<<endl;
						}
					}
				}
			}
			if(count==1)
				back=min(forw,len-forw);
			back=min(back,forw);
			//cout<<forw<<" "<<back<<endl;
			move+=back;
			cout<<move<<endl; 
		}
	}
	return 0;
}//AABAAAAAB - 6  back then front 
