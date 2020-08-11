#include <iostream>
#include <algorithm>
using namespace std;

struct Card{
	int num; // 카드의 값
	bool pick = false; // 카드를 선택했는지 여부
};

void blackJack(int N, int M, Card *card, int depth, int cur_sum, int &max_sum);

int main() {
	int N, M;
	cin >> N >> M;
	
	Card *card = new Card[N];
	for(int i = 0; i < N; i++){
		cin >> card[i].num;
	}
	
	int sum = 0; // M을 넘지 않고 M에 가장 가까운 합
	blackJack(N,M,card,0,0,sum);
	cout << sum;
	
	return 0;
}

void blackJack(int N, int M, Card *card, int depth, int cur_sum, int &max_sum){
	if(depth == 3){ // 3개의 카드 모두 선택했다면
		max_sum = max(cur_sum,max_sum); // 현재의 합과 최대 합과 비교하여 최대합 갱신(합이 M을 넘지 않아야 재귀가 수행되기 때문에 이 단계의 합의 값은 모두 M을 넘지 않음)
		return;
	}
	
	for(int i = 0; i < N; i++){
		cur_sum += card[i].num; // 현재 카드의 값을 더해 합 구하기
		if(cur_sum <= M && !card[i].pick){ // 합이 M을 넘지 않고 현재 카드가 선택된 적 없다면
			card[i].pick = true; // 카드 선택 표시
			blackJack(N,M,card,depth+1,cur_sum,max_sum); // 다음 카드 선택하여 합을 구하기 위한 재귀 수행
			card[i].pick = false; // 연산 완료 후, 카드 선택 취소(백트래킹)
		}
		cur_sum -= card[i].num; // 합 원래 값으로 복원하여 다음 연산할 수 있도록 함(백트래킹)
	}
}
