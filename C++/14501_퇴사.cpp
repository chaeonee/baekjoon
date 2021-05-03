#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int profit[N];
	memset(profit, 0, sizeof(int)*N);
	
	profit[0] = 0;
	for(int i = 0; i < N; i++){
		int T, P;
		cin >> T >> P;
		
		if(i != 0){
			if(profit[i-1] > profit[i]){
				profit[i] = profit[i-1];
			}
		}
		
		if(i+T-1 < N){
			if(i != 0){
				if(profit[i+T-1] < P+profit[i-1]){
					profit[i+T-1] = P+profit[i-1];
				}
			}
			else{
				if(profit[i+T-1] < P){
					profit[i+T-1] = P;
				}
			}
		}
	}
	
	/*for(int i = 0; i < N; i++){
		cout << profit[i] << endl;
	}*/
	cout << profit[N-1];
	
	return 0;
}
