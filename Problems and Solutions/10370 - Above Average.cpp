#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	int T;
	cin>>T;
	for(int i=0; i<T; i++){
		int N;
		cin>>N;
		
		int A[N], avg=0;
		
		for(int j=0; j<N; j++){
			cin>>A[j];
			avg+= A[j];
		}
		avg= avg/N;
		int C=0;
		
		for(int j=0; j<N; j++)
			if(A[j]>avg)
				C++;
		
		cout<<fixed<<setprecision(3)<<(C*100.0)/N<<"%"<<endl;	
	}
	return 0;
}
