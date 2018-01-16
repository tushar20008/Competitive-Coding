#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int N[1001];
struct suffix
{
    int index; // To store original index
    int rank[2]; // To store ranks and next rank pair
};

int cmp(struct suffix a, struct suffix b)
{
    return (a.rank[0] == b.rank[0])? (a.rank[1] < b.rank[1] ?1: 0):
               (a.rank[0] < b.rank[0] ?1: 0);
}

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
	int count=0;   
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
		count++;
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
    for(int k=0; k<L_R; k++)
		cout<<(char)R[k];
	cout<<" "<<count<<endl;
    //cout<<i<<"	"<<j<<endl;
}

void LCP(string A, int S_A[], int n)
{
	int LCP[n], Reverse_SA[n], prev=0;
	memset(LCP,0,sizeof(LCP));
	for (int i=0; i < n; i++)
        Reverse_SA[S_A[i]] = i;
    for (int i=0; i<n; i++)
    {
        if (Reverse_SA[i] == n-1)
        {
            prev=0;
            continue;
        }
        int j = S_A[Reverse_SA[i]+1];
 		while (i+prev<n && j+prev<n && A[i+prev]==A[j+prev])
            prev++;
 
        LCP[Reverse_SA[i]] = prev;
		//cout<<Reverse_SA[i]<<" "<<prev<<endl; 
        if (prev>0)
            prev--;
    }
	/*
    for(int j=0; j<n; j++)
    	cout<<LCP[j]<<" ";
    cout<<endl;
    for(int j=0; j<n; j++)
    	cout<<S_A[j]<<" ";
    cout<<endl;
    */
    int index=-1,len=0;
	for(int i=0; i<n; i++)
		if(LCP[i]==0)
			continue;
    	else if(LCP[i]>len)
    	{
    		len=LCP[i];
    		index=S_A[i];
    		//cout<<S_A[i]<<" "<<LCP[i]<<endl;
		}
		else if(LCP[i]==len)
		{
			for(int j=0; j<len; j++)
				if(A[S_A[i]+j]>A[index+j])
					break;
				else if(A[S_A[i]+j]<A[index+j])
				{
					len=LCP[i];
    				index=i;
				}
			//cout<<"2 -> "<<index<<" "<<len<<endl;
		}
	//cout<<index<<" "<<len<<endl;
	if(index==-1)
		cout<<"No repetitions found!"<<endl;
	else
	{
		memset(N,0,sizeof(N));
		int R[len],S[n];
		for(int i=0; i<n; i++)
			S[i]=A[i];
		for(int i=0; i<len; i++)
			R[i]=A[index+i];
		kmp(R,len);
		match(R,S,len,n);
	}
}

int main()
{
	int T;
	cin>>T;
	string A;
	for(int test=0; test<T; test++)
	{
		cin>>A; 
		int len=A.size(), Suffix_Array[len];
		suffix S[len];
		for(int i=0; i<len; i++)
		{
			S[i].index=i;
			S[i].rank[0]=A[i]-'A'; // Its 'a' but A in this case
			S[i].rank[1]=((i+1) < len)? (A[i + 1] - 'A'): -1;
			//cout<<S[i].rank[0]<<" "<<S[i].rank[1]<<endl;
		}
		sort(S, S+len, cmp);
		for(int i=4; i<len*2; i*=2)
		{
			int rank = 0, prev= S[0].rank[0];
        	S[0].rank[0] = rank;
        	Suffix_Array[S[0].index] = 0;
        	
        	for(int j=1; j<len; j++)
        	{
        		if(S[j].rank[0] == prev && S[j].rank[1] == S[j-1].rank[1])
            	{
                	prev= S[j].rank[0];
                	S[j].rank[0] = rank;
            	}
            	else // Otherwise increment rank and assign
            	{
                	prev=S[j].rank[0];
                	S[j].rank[0] = ++rank;
            	}
            	Suffix_Array[S[j].index] = j;
        	}
        	for (int j=0; j<len; j++)
        	{
            	int next=S[j].index + i/2;
            	S[j].rank[1] = (next < len)?S[Suffix_Array[next]].rank[0]: -1;
        	}
        	sort(S,S+len,cmp);
		}
		for(int i=0; i<len; i++)
			 Suffix_Array[i] = S[i].index;
		LCP(A,Suffix_Array,len);
	}
	return 0;
}
