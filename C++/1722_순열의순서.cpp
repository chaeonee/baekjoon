#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int problem;
	cin >> problem;
	
	int tmp_n = N;
	long long int num = 1;
	for(int i = 2; i <= N; i++){
		num *= i;
	}
	if(problem == 1){ // N 번째 순열 
		long long int k;
		cin >> k;
		
		bool visit[N];
		memset(visit,false,N);
		for(int i = 0; i < N-1; i++){
			num /= tmp_n; // 현재 자리의 수가 고정되어 있고 뒤에 있는 숫자들을 섞는 경우의 수
			tmp_n--;
			
			// 여기서 말하는 세트는 고정된 숫자가 동일한 순열을 의미
			long long int a = k/num; // k의 초기값: 구하고 싶은 순열의 순서(num으로 나누면, 현재 자리 수 고정 됐을 때 한 세트가 몇개로 구성되어있는지 알 수 있음)
			if(k%num == 0){ // 나머지가 0일때까지 한 세트로 봐줘야 함
				a--; // 따라서 몫 하나 줄여주고 방문하지 않은 숫자중에 a번째 숫자가 무엇인지 찾아야 함
				for(int i = 0; i < N; i++){
					if(visit[i] == false){	
						if(a == 0){
							cout << i+1 << " "; // a번째 숫자 무엇인지 찾으면 출력하고
							k -= num*((k/num)-1); // 현재 수 고정하고 남은 숫자가 얼마인지 계산(계산하면 다음 수 고정하고 또 계산 반복)
							visit[i] = true;
							break;
						}
						a--;
					}
				}
			}
			else{ // 방문하지 않은 숫자중에 a번째 숫자가 무엇인지 찾아야 함
				for(int i = 0; i < N; i++){
					if(visit[i] == false){
						if(a == 0){
							cout << i+1 << " "; // a번째 숫자 무엇인지 찾으면 출력하고
							k -= num*((k/num)); // 현재 수 고정하고 남은 숫자가 얼마인지 계산(계산하면 다음 수 고정하고 또 계산 반복)
							visit[i] = true;
							break;
						}
						a--;
					}
				}
			}
		}
		
		for(int i = 0; i < N; i++){ // 모두 출력하고 남은 숫자가 마지막 숫자가 됨
			if(visit[i] == false){
				cout << i+1 << " ";
				break;
			}
		}
	}
	else{ // 입력된 순열이 몇 번째 인지
		long long int result = 1; // 첫 번째 순열로 초기화
		
		// 각 자리의 숫자가 현재 방문하지 않은 숫자들 중 몇 번째로 큰 숫자인지 알아야 함(0부터 시작)
		bool visit[N];
		memset(visit,false,N);
		for(int i = N; i > 0; i--){
			int n;
			cin >> n;
			visit[n-1] = true; // 현재 입력받은 수 방문 표시
			
			int tmp = 0; // 현재 입력 받은 수가 방문하지 않은 숫자들 중 몇 번째로 큰 숫자인지 세기
			for(int j = 0; j < N; j++){
				if(j == n-1){
					break;
				}
				if(visit[j] == false){
					tmp++; // 방문하지 않았고 현재 입력 받은 수보다 작다면(j가 0부터 N까지 돌기 때문에 여기에 들어오는 수는 입력 받은 수보다 작음)
				}
			}
			
			num /= i; // 현재 자리수는 고정이고 나머지 숫자들을 섞는 만큼 내 앞쪽에 존재할 것이기 때문에... 전체 순열의 수(초기값이) num에서 현재 자리수를 나눠 줌
			result += tmp*num; // tmp와 곱해줌으로써 내 앞쪽에 몇 개 있는지 셀 수 있음(이를 가장 큰 자리 수부터 일의 자리 수까지 반복)
		}
		
		cout << result;
	}
	
	return 0;
}
