#include <iostream>		//Check at UVA
#include <cstring>
using namespace std;
int N[1000+1];

void kmp(string R, int len)
{
    int i=1, prev = 0;  
    N[0] = 0; 
 
    while (i < len)
    {
       if (R[i] == R[prev])
       {
         prev++;
         N[i] = prev;
         i++;
       }
       else 
       {
         if (prev != 0)
           	prev = N[prev-1];
         else
         {
           N[i] = 0;
           i++;
         }
       }
    }
}

bool match(string R, string S, int L_R, int L_S)
{  
    int i = 0, j=0;  // index for S,R;
    while (i < L_S)
    {
      if (R[j] == S[i])
      {
        j++;
        i++;
      }
 
      if (j == L_R)
      {
        //printf("Found pattern at index %d \n", i-j);
		j = N[j-1];
		return true;
      }
      else if (i < L_S && R[j] != S[i])
      {
        if (j != 0)
        	j = N[j-1];
        else
        	i = i+1;
      }
    }
    return false;
}

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(NULL); 
	int t,q;
	string A,B;
	cin>>t;
	while(t--)
	{
		cin>>A;
		int len=A.size();
		cin>>q;
		bool F[q];
		memset(F,0,sizeof(F));
		while(q--)
		{
			cin>>B;
			int len2=B.size();
			kmp(B,len2);
			if(match(B,A,len2,len))
				cout<<"y"<<endl;
			else
				cout<<"n"<<endl;
		}
	}
	return 0;
}
