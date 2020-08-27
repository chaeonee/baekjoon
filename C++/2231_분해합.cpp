#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int getDigit(int N);

int main() {
	int N;
	cin >> N;
	
	int digit = getDigit(N); // 주어진 수의 자릿수
	
	
	int con = 0; // 주어진 수가 분해합인 수 중 가장 작은 수
	int s = max(1,(int)pow(10,digit-2)); // 시작 수(주어진 수가 1자리 수라면 한자리 작은 수부터 볼 수 없음)
	for(int i = s; i < N; i++){
		int num = 0, tmp = i;
		while(tmp > 0){ // 해당 수의 각 자리 수를 잘라서 해당 숫자에 하나씩 더해 줌(분해합 구하는 방법)
			num += tmp % 10;
			tmp /= 10;
		}
		if(i+num == N){ // 해당 수의 분해합이 주어진 수와 같으면
			con = i; // 해당 수를 저장한 후
			break; // 루프 종료
		}
	}
	
	cout << con;
	
	return 0;
}

int getDigit(int N){ // 해당 수가 몇 자리 수인지 구하는 함수
	int digit = 1;
	
	N /= 10;
	while(N > 0){ // 한자리씩 줄이면서 해당 수가 몇 자리 수인지 알아내는 것
		digit++;
		N /= 10;
	}
	
	return digit;
}
