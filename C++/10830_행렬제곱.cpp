#include <iostream>
using namespace std;

int** matSquared(int N, long long int B, int** mat);
int** matMul(int N, int **A, int **B);

int main() {
	int N;
	long long int B;
	cin >> N >> B;
	
	int **mat = new int*[N];
	for(int i = 0; i < N; i++){
		mat[i] = new int[N];
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> mat[i][j];
		}
	}
	
	
	mat = matSquared(N,B,mat);
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cout << mat[i][j] % 1000 << " "; // 1000으로 나눈 나머지 출력
		}
		cout << '\n';
	}
	return 0;
}

int** matSquared(int N, long long int B, int** mat){
	if(B == 1){ // 1제곱은 자기 자신
		return mat;
	}
	
	if(B % 2 == 0){ // 짝수 제곱일 때
		int **result = matSquared(N,B/2,mat); // 제곱으로 구할 수 있으므로 제곱 수 한 번만 계산해서
		return matMul(N,result,result); // 제곱 진행
	}
	else{ // 홀수 제곱일 때
		return matMul(N,matSquared(N,B-1,mat),matSquared(N,1,mat)); // 짝수 제곱*1승 나눠서 다음 함수에서 짝수 제곱 돌 수 있게
	}
}

int** matMul(int N, int **A, int **B){ // 행렬 곱 구하는 함수
	int **result = new int*[N];
	for(int i = 0; i < N; i++){
		result[i] = new int[N];
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int tmp = 0;
			for(int k = 0; k < N; k++){ 
				tmp += (A[i][k] * B[k][j])%1000; // 1000으로 나눈 나머지 구해야 하므로 1000으로 나눠주어야 함(안 나누면 초과 날수도)
			}
			result[i][j] = tmp%1000; // 1000으로 나눈 나머지 구해야 하므로 1000으로 나눠주어야 함
		}
	}
	
	return result;
}
