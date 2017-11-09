#include <iostream>
#include <queue>
using namespace std;

struct Reverse 
{
  bool operator()(string x, string y) 
  {
    return y < x;
  }
};

int main()
{
	priority_queue<string, vector<string>, Reverse> pq;
	string word;
	while(cin>>word)
		pq.push(word);
	
	int count = 0;
	word = pq.top();	
	while (!pq.empty())
	{
		if(word == pq.top())
			count++;
		else
		{
			cout<<word<<" "<<count<<endl;
			count = 1;
			word = pq.top();
		}
		pq.pop();
	}
	cout<<word<<" "<<count<<endl;
	return 0;
}
