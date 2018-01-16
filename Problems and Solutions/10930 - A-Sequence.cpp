#include <iostream>
using namespace std;
bool Check(int set[], int n, int sum)
{
	bool subset[sum+1][n+1];
 
    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++)
      subset[0][i] = true;
 
    // If sum is not 0 and set is empty, then answer is false
    for (int i = 1; i <= sum; i++)
      subset[i][0] = false;
 
     // Fill the subset table in botton up manner
     for (int i = 1; i <= sum; i++)
     {
       for (int j = 1; j <= n; j++)
       {
         subset[i][j] = subset[i][j-1];
         if (i >= set[j-1])
           subset[i][j] = subset[i][j] || subset[i - set[j-1]][j-1];
       }
     }
 
    /* // uncomment this code to print table
     for (int i = 0; i <= sum; i++)
     {
       for (int j = 0; j <= n; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     } */
 
     return subset[sum][n];
}

int main()
{
	int N,T=1;
	while(cin>>N)
	{
		int A[N], prev=-1;
		bool found=false;
		for(int i=0; i<N; i++)
		{
			cin>>A[i];
			if(prev==-1)
				prev=A[i];
			else if(prev>=A[i])
				found=true;
			else
				prev=A[i];
			if(!found && Check(A,i,A[i]))
				found=true;
		}	
		cout<<"Case #"<<T++<<": ";
		for(int i=0; i<N; i++)
			if(i!=N-1)
				cout<<A[i]<<" ";
			else 
				cout<<A[i]<<endl;
		if(!found)
			cout<<"This is an A-sequence."<<endl;
		else
			cout<<"This is not an A-sequence."<<endl;
	}
	return 0;
}
