#include <iostream>
using namespace std;

int main() {
	int A, B, C, arr[10] = {0,};
	cin >> A >> B >> C;
	
	long long int mul; // 곱은 int의 범위를 초과할 수 있
	mul = A * B * C;
	while(mul != 0){ // 10으로 나눈 몫과 나머지를 이용하여 숫자를 한 자리씩 분리
		int idx; // 맨 뒷자리 숫자
		idx = mul%10; // 맨 뒷자리 숫자를 제거하고 남은 숫자
		mul /= 10;
		
		arr[idx]++; // 맨 뒤에 있는 숫자부터 세
	}
	
	for(int i = 0; i < 10; i++){
		cout << arr[i] << '\n';
	}
	
	return 0;
}