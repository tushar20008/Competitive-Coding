#include <iostream>
#include <cstring>
using namespace std;
int *N=new int[100001];

void kmp(int R[], int len)
{
    int i=1, prev = 0;  
    N[0] = 0; 
 
    // the loop calculates lps[i] for i = 1 to M-1
    while (i < len)
    {
       if (R[i] == R[prev])
       {
         prev++;
         N[i] = prev;
         i++;
       }
       else // (pat[i] != pat[len])
       {
         if (prev != 0)
         {
           // This is tricky. Consider the example 
           // AAACAAAA and i = 7.
          	prev = N[prev-1];
 
           // Also, note that we do not increment i here
         }
         else // if (len == 0)
         {
           N[i] = 0;
           i++;
         }
       }
    }
}

void match(int R[], int S[], int L_R, int L_S)
{
	bool found=false;   
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
		found=true;
      }

      // mismatch after j matches
      else if (i < L_S && R[j] != S[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = N[j-1];
        else
         i = i+1;
      }
    }
    for(int k=0; k<L_S; k++)
		cout<<(char)S[k];
	if(!found)
    	for(int k=j; k<L_R; k++)
			cout<<(char)R[k];
	cout<<endl;
    //cout<<i<<"	"<<j<<endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 
	string A;
	while(cin>>A)
	{
		memset(N,0,sizeof(int)*100001);
		int *S=new int[100001],*R=new int[100001];
		int len=A.size();
		//cout<<len<<endl;
		for(int i=0; i<len; i++)
			S[i]=A[i];
		for(int i=0; i<len; i++)
			R[i]=S[len-1-i];
		kmp(R,len);
		match(R,S,len,len);
	}
	return 420;
}
