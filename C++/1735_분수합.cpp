#include <iostream>
using namespace std;

int gcd(int a, int b);

int main() {
	int A[2]; // 분자
	int B[2]; // 분모
	
	for(int i = 0; i < 2; i++){
		int a, b;
		cin >> a >> b;
		A[i] = a;
		B[i] = b;
	}
	
	int g = gcd(B[0],B[1]); // 분모의 최대공약수 구하기
	
	int result[2]; // 결과 분자 분모 담는 배열, index 0: 분자, 1: 분모
	int a1, a2; // 최소 공배수 구하기 위해 각 분모를 최대 공약수로 일단 나눔
	a1 = B[0]/g;
	a2 = B[1]/g;
	
	result[1] = g*a1*a2; // 분모(최소공배수)
	result[0] = a2*A[0] + a1*A[1]; // 분자(교차해서 곱한 것의 합)
	
	g = gcd(result[0],result[1]); // 약분을 위한 최대공약수 구하기
	if(g != 1){ // 최대공약수가 1이면 약분할 필요 없음, 아니라면 약분 진행
		result[0] /= g;
		result[1] /= g;
	}
	
	cout << result[0] << ' ' << result[1];
	
	return 0;
}

int gcd(int a, int b){ // 최대공약수 구하는 함
	while(b != 0){
		int tmp = a%b;
		a = b;
		b = tmp;
	}
	
	return a;
}