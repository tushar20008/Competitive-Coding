#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	vector<int> arr;
	int n;
	
	while(cin >> n){
		if(n == -1)
			return 0;
		else if(n==0){
			sort(arr.begin(), arr.end());
			int total = 0;
			for(int i=0; i<arr.size()-1; i++){
				for(int j=i+1; j<arr.size(); j++){
					if(arr[j] == 2*arr[i]){
						total++;
						break;
					}
				}
			}
			cout << total << endl;
			arr.clear();
		}
		else {
			arr.push_back(n);
		}
	}	
}
