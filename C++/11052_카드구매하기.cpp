#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int cost[N+1] = {0, }; // N개의 카드를 구매하기 위해 지불해야 하는 금액의 최댓값 저장
	for(int i = 1; i <= N; i++){ // i: 카드 팩에 들어있는 카드의 수
		int c;
		cin >> c; // i개의 카드가 들어있는 카드 팩을 구매하기 위해 지불해야 하는 금액
		
		for(int j = i; j <= N; j++){ // j: i개가 들어있는 카드 팩을 이용하여 j개의 카드를 구매하기 위한 비용 구하기(카드 팩에 i개가 들어가 있으므로, i개 이상의 카드만 구매할 수 있음)
			if(cost[j] < c+cost[j-i]){ // j개의 카드를 구매하기 위한 금액의 기존 최댓값과 i개가 들어있는 카드 팩을 이용하여 j개의 카드를 구매하기 위한 금액의 최댓값을 비교하여
				cost[j] = c+cost[j-i]; // 기존의 값보다 크다면 큰 값으로 갱신
			}
		}
	}
	
	cout << cost[N];
	
	return 0;
}
