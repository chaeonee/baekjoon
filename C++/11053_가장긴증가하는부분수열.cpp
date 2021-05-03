#include <iostream>
using namespace std;

int main() {
	int N, max = 0;
	
	cin >> N;
	
	int *A = new int[N];
	int *result = new int[N];
	
	result[0] = 1;
	for(int i = 0; i < N; i++){
		cin >> A[i];
		
		int tmp = 0;
		for(int j = 0; j < i; j++){
			if(A[j] < A[i] && tmp < result[j]){
				tmp = result[j];
			}
		}
		
		result[i] = tmp + 1;
		
		if(max < result[i]){
			max = result[i];
		}
	}
	
	cout << max;
	return 0;
}
