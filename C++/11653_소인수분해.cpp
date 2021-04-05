#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	while(N > 1){
		bool flag = false;
		for(int i = 2; i <= sqrt(N); i++){
			if(N % i == 0){
				cout << i << '\n';
				N /= i;
				flag = true;
				break;
			}
		}
		if(!flag){
			cout << N << '\n';
			N /= N;
		}
		
	}
	return 0;
}
