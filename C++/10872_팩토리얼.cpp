#include <iostream>
using namespace std;

int factorial(int N);

int main() {
	int N;
	cin >> N;
	
	if(N == 0){
		cout << 1;
		return 0;
	}
	
	cout << factorial(N);
	
	return 0;
}

int factorial(int N){
	if(N == 1){
		return 1;
	}
	
	return N * factorial(N-1);
}
