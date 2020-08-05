#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int neg = 0;
	int *num = new int[N];
	for(int i = 0; i < N; i++){
		cin >> num[i];
		
		if(num[i] <= 0){
			neg++;
		} // 음수의 개수(0 포함), 양수의 개수는 N에서 음수의 개수 빼면 됨
	}
	sort(num,num+N); // 오름차순으로 정렬
	
	long long int sum = 0; // 합의 최대값 담을 변수
	if(neg % 2 != 0){ // 음수의 개수가 홀수 개라면 묶어도 1개가 남을 것
		sum += num[neg-1]; // 절대값이 가장 작은(실제로는 음수 중 가장 큰) 수는 묶이지 않음 
	}
	for(int i = 0; i < neg-1; i++){ // 절대값 큰 수부터 묶어서 곱한 후 합에 더해주기(작은 수부터)
		sum += num[i] * num[i+1];
		i++;
	}
	
	// 양수의 경우, 1에 대한 처리 필요
	while(num[neg] == 1){
		sum += 1; // 1은 곱하지 않고 모두 더해주어야 함
		neg++;
	}
	if((N-neg) % 2 != 0){ // 1을 제외한 양수들의 개수가 홀수 개라면 묶어도 1개가 남을 것
		sum += num[neg]; // 절대값이 가장 작은(실제로는 양수 중 가장 작은) 수는 묶이지 않음
	}
	for(int i = N-1; i > neg; i--){ // 절대값 큰 수부터 묶어서 곱한 후 합에 더해주기(큰 수부터)
		sum += num[i] * num[i-1];
		i--;
	}
	
	cout << sum; // 계산 결과 출력
	
	return 0;
}
