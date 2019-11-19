#include <iostream>
#include <stdio.h>
using namespace std;

int dp[1<<15][15][10];
int sellPic(int N, int** cost, int state, int artist, int c, int depth);

int main() {
	int N;
	cin >> N;
	
	int **cost = new int*[N];
	for(int i = 0; i < N; i++){
		cost[i] = new int[N];
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			scanf("%1d",&cost[i][j]);
		}
	}
	
	cout << sellPic(N,cost,1,0,0,1);
	
	return 0;
}

// state는 방문 상태, artist는 예술가 번호, c는 현재 예술가가 산 cost, depth는 소유했던 사람들의 수(깊이)
int sellPic(int N, int** cost, int state, int artist, int c, int depth){
	if(dp[state][artist][c] != 0){ //이미 계산이 완료되었다는 뜻
		return dp[state][artist][c];
	}
	
	dp[state][artist][c] = depth; // 현재 깊이를 대입
	for(int i = 0; i < N; i++){
		if(state&(1<<i) || cost[artist][i] < c){ //이미 방문했거나, 산 가격보다 팔 가격이 낮을 때
			continue;
		}
		
		int tmp = sellPic(N,cost,(state|(1<<i)),i,cost[artist][i],depth+1); //재귀적으로 실행하여
		if(dp[state][artist][c] < tmp){//더 큰 값을 가지면 max값을 바꿔주고 return
			dp[state][artist][c] = tmp;
		}
	}
	
	return dp[state][artist][c];
}