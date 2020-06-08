#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	int n_coin = K, r_coin = 0; // n_coin: 현재 필요한 동전의 수(처음 주어지는 동전은 1원이므로 K개의 동전이 필요), r_coin: 더 큰 동전으로 커버되지 않는 동전의 수(남는 동전 저장해 놓는 용도)
	int pre_coin, cur_coin; // 현재 동전과 바로 이전에 동전 값 저장(둘이 몇 배수 차이나는지 확인하기 위해)
	cin >> pre_coin; // 처음에는 1이 입력될 것
	for(int i = 1; i < N; i++){
		cin >> cur_coin;
		
		if(cur_coin > K){ // 현재 동전의 값이 만들고자 하는 가치보다 클 경우
			break; // 만들 수 없기 때문에 break
		}
		
		r_coin += n_coin % (cur_coin/pre_coin); // 남는 동전: 현재 가치로 커버할 수 없음.. 이전 가치 중 커버할 수 있는 금액의 최대값으로 커버했을 것
		n_coin /= cur_coin/pre_coin; // 현재 필요한 동전의 수는 이전에 필요한 동전 수에서 (현재 동전의 가치 / 이전 동전의 가치)(=>몇배인지)를 나눠준 몫이 될 것임
		pre_coin = cur_coin; // 이전 동전의 가치 갱신
	}
	
	cout << n_coin+r_coin; // 필요한 동전은 현재 필요한 동전의 수와 남은 동전의 수의 합
	
	return 0;
}
