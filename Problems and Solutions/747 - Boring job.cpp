#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int T;
	cin>>T;
	
	while(T--)
	{
		int N, K;
		cin>>N>>K;
		
		vector<int> V, I;
		for(int i=1; i<=N; i++)
		{
			int temp;
			cin>>temp;
			V.push_back(temp);
			I.push_back(i);
		}
		
		while(true)
		{
			if(V.size() < K)
				K = V.size();
			
			if(K == 0)
				break;
			
			int max = *max_element(V.begin(),V.begin()+K);
			bool found = false;
			
			for(int i=0; i<K; i++)
			{
				if(V.at(0) == max && !found)
				{
					found = true;
					cout<<I.at(0);
					
					N--;
					if(N)
						cout<<" ";
					
					V.erase(V.begin());
					I.erase(I.begin());
				}	
				else 
				{
					V.at(0) -= 1;
			
					V.push_back(V.at(0));
					V.erase(V.begin());
					
					I.push_back(I.at(0));
					I.erase(I.begin());	
				}	
			}	
		}
		cout<<endl;		
	}
	return 0;
}
