#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;     // 10 - 8 1 17 5 9 6 8 12 11 13 

int Length(int A[], int n)
{
	int temp[n],len=1;
	memset(temp,0,sizeof(temp));
	temp[0]=A[0];
	for(int i=1; i<n; i++)
	{
		if(A[i]<temp[0])
			temp[0]=A[i];
		else if(A[i]>=temp[len-1])
			temp[len++]=A[i];
		else
		{
			int start=-1, end=len-1,mid; 
			while(end-start>1)
			{
				mid=start+(end-start)/2;
				if(A[i]==temp[mid])
				{
					while(true)
					{
						mid++;
						if(temp[mid]!=A[i])
							break;
					}
					break;
				}
				else if(A[i]<temp[mid+1] && A[i]>temp[mid])
				{
					mid++;
					break;
				}
				else if(A[i]<temp[mid])
					end=mid;	
				else if(A[i]>temp[mid])
					start=mid;
			}
			temp[mid]=A[i];
		}
		/*for(int j=0; j<n; j++)
			cout<<temp[j]<<" ";
			cout<<endl;*/
	}
	return len;
}

int main()
{
	long n;
	while(cin>>n)
	{
		int A[n];
		
		for(int i=0; i<n; i++)
			cin>>A[i];
	
		cout<<Length(A,n)<<endl;	

	/*  O(n2)	
		for(int i=1; i<n; i++)
		{
			for(int j=0; j<i; j++)
			{
				if(A[j]<=A[i])
					temp[i]=max(temp[i],temp[j]+1);
			}
		}
		
		int length=temp[0];
		for(int i=1; i<n; i++)
			if(temp[i]>length)
				length=temp[i];
				
		cout<<length<<endl;*/
	}
	return 0;
}
