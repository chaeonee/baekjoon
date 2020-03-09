#include <iostream>
#include <algorithm>
using namespace std;

bool desc(int a, int b){ // 내림차순 정렬을 위한 함수
	return a > b;
}

int main() {
	int N;
	cin >> N;
	
	int A[N], B[N];
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	for(int i = 0; i < N; i++){
		cin >> B[i];
	}
	
  // 곱의 합이 최소가 되기 위해서는 (작은 수 * 큰 수)의 조합이 이루어져야 하기 때문에 정렬 진행
	sort(A,A+N); // 오름차순 정렬
	sort(B,B+N,desc); // 내림차순 정렬
	
	int S = 0;
	for(int i = 0; i < N; i++){
		S += A[i]*B[i];
	}
	
	cout << S;
	
	return 0;
}
