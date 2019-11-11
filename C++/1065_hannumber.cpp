#include <iostream>
using namespace std;

bool isHan(int N);

int main() {
	int N;
	cin >> N;
	
	int num;
	if(N < 100){
		num = N; // 99이하의 수는 모두 한수
	}
	else{
		num = 99; // 99이하의 수는 모두 한수
		for(int i = 100; i <= N; i++){ // 100부터 한수인지 확인
			bool result = isHan(i);
			if (result == true){ // isHan의 return 값이 true면 한수
				num++;
			}
		}
	}
	
	cout <<  num;
	
	return 0;
}

bool isHan(int N){ //각 자리수의 차를 구하여 한수인지 확인하는 함수
	bool han = true;
	
	int a = (N/10) % 10;
	int diff = (N % 10) - ((N/10) % 10); // 차이 값(이것을 기준으로 함)
	N /= 100;
	while(N != 0){
		int b = N % 10;
		if(diff != a-b){ // 만약 diff와 다르면 한수가 아님(모든 차가 diff와 동일해야 한수)
			han = false;
			break;
		}
		
		a = b;
		N /= 10;
	}
	return han; //한수이면 true return 아니면 false return
}