#include <iostream>
using namespace std;

int main() {
	int N;
	
	cin >> N;
	
	int *A = new int[N];
	for(int i = 0 ; i < N; i++){
		cin >> A[i];
	}
	
	int *f_result = new int[N];
	f_result[0] = 1;
	for(int i = 1; i < N; i++){
		int tmp = 0;
		for(int j = 0; j < i; j++){
			if(A[i] > A[j] && tmp < f_result[j]){
				tmp = f_result[j];
			}
		}
		f_result[i] = tmp + 1;
	}
	
	int *b_result = new int[N];
	b_result[N-1] = 1;
	for(int i = N-2; i >= 0; i--){
		int tmp = 0;
		for(int j = i+1; j < N; j++){
			if(A[i] > A[j] && tmp < b_result[j]){
				tmp = b_result[j];
			}
		}
		b_result[i] = tmp + 1;
	}
	
	int max = 0;
	for(int i = 0; i < N; i++){
		if(max < f_result[i] + b_result[i]){
			max = f_result[i] + b_result[i];
		}
	}
	
	cout << max - 1;
	//for(int i = 0; i <N; i++){cout << f_result[i] <<" "<< b_result[i]<<endl;}
	return 0;
}
