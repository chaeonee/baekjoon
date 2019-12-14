#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define INF 17000000 // INF 값 미리 설정
int dp[1 << 16][16]; //비트마스크 앞은 방문 표시 뒤는 현재 위치

int TSP(int N, int **W, int cur, int visited);

int main() {
	int N;
	cin >> N;

	int **W = new int*[N];
	for(int i = 0; i < N; i++){
		W[i] = new int[N];
	}

	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> W[i][j];
		}
	}

	memset(dp,-1,sizeof(dp)); //dp -1로 초기화(아직 계산하지 않은 것을 표현하기 위해)
	cout << TSP(N,W,0,1); // 0부터 시작해도 됨, 어차피 순회이기 때문에 순서가 어쨋든 최소 합은 같아짐

	return 0;
}

int TSP(int N, int **W, int cur, int visited){ //cur: 현재 위치, visited: 어떤 노드 방문했는지 방문 표시
	int& min_cost = dp[visited][cur]; // 주솟값을 저장하는 이유는 dp 값을 최솟 값으로 계속 갱신해주기 위해
	if(min_cost != -1){ // -1이 아니라는 이야기는 이미 최솟값으로 계산되었다는 이야기
		return min_cost; // 중복 계산 하지 않고 min_cost 값 return
	}

	if(visited == (1<<N)-1){ // 모두 방문한 경우 ex) N = 3인 경우 111일때 모두 방문한 경우가 되는데 1 << 3은 1000으로 8이 됨 111이 되려면 7이 되어야 하기 때문에 -1 (즉, 1<<N에서 1을 빼면 자릿수는 하나 줄어들고 모든 값이 1인 이진수가 됨)
		if(W[cur][0] != 0){ // 가는 길이 존재한다면 return, 시작을 0부터 했기 때문에 0으로 도착하는지 확인해야 함
			return W[cur][0];
		}
		else{ // 가는 길이 없다면 INF로 설정
			return INF;
		}
	}

	min_cost = INF; // 최솟값을 구하기 위해 min_cost INF 값으로 설정
	for(int i = 0; i < N; i++){
		if(W[cur][i] != 0 && !(visited&(1<<i))){ // W[cur][i] != 0: 연결되어 있음, !(visited&(1<<i)): 방문한 적 없는지 방문한 적 없다면 0이 될 것
			min_cost = min(min_cost, TSP(N,W,i,(visited|(1<<i)))+W[cur][i]); // 현재 cost W를 재귀적으로 더한 것과 저장되어있는 min_cost 비교하여 더 작은 것 저장
		}
	}

	return min_cost; // 이것이 최솟값이 될 것
}
