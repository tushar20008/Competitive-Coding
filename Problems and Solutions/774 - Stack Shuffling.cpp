#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int T;
	cin>>T;
	
	while(T--)
	{
		int N;
		cin>>N;
		
		stack<int> A;
		
		for(int i=0; i<N; i++)
		{
			int temp;
			cin>>temp;
			A.push(temp);
		}
			
		int M;
		cin>>M;
		
		while(M--)
		{
			int out[N];
			stack<int> tempA, S;
			for(int i=0; i<N; i++)
				cin>>out[i];
			
			tempA = A;
			
			bool possible = false;
			
			for(int i=0; i<N; i++)
			{
				if(!S.empty() && S.top() == out[i])
				{
					S.pop();
					possible = true;
					//cout<<"S.pop"<<endl;
				}
				else 
				{
					while(!tempA.empty() && tempA.top() != out[i])
					{
						S.push(tempA.top());
						tempA.pop();
						//cout<<"tempA.pop()"<<endl;
					}
					
					if(tempA.top() == out[i])
					{
						tempA.pop();
						possible = true;
					}	
				}
				
				if(possible && i != N-1)
					possible = false;
				else
					break;
			}
			
			if(possible)
				cout<<"Aye"<<endl;
			else
				cout<<"Impossible"<<endl;
		}
	}
	
	return 0;
}
