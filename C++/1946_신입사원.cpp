#include <iostream>
#include <algorithm>
using namespace std;

struct Test{
	int written, interview;
};

bool cmp(Test &a, Test &b){
	return a.written < b.written;
}

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		int N;
		cin >> N;
		Test test[N];
		for(int n = 0; n < N; n++){
			int step1, step2;
			cin >> step1 >> step2;
			test[n] = {step1,step2};
		}
		
		sort(test,test+N,cmp); // 입력받은 등수 필기시험 등수를 기준으로 정렬
		
		int pick = N;
		int i_min = test[0].interview; 
		for(int i = 1; i < N; i++){
			if(test[i].interview > i_min){ // 면접 등수가 필기 지금까지의 필기시험 등수의 최소값보다 크다면
				pick--; // 합격하지 못함
			}
			else{ // 아니라면 합격 그리고 등수 최소값 갱신
				i_min = test[i].interview;
			}
		}
		cout << pick << '\n';
	}
	
	return 0;
}
