#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int N, S, M;
	cin >> N >> S >> M;
	
	int V[N];
	bool arr[N][M+1]; // 해당 곡에서 가능한 볼륨의 크기를 true로 담을 배열
	for(int i = 0; i < N; i++){
		cin >> V[i];
		memset(arr[i],false,M+1);
	}
	
  // 초기화 (시작볼륨과 첫번째 곡이 V[0]만큼 차이나도록)
	if(S+V[0] <= M){
		arr[0][S+V[0]] = true;
	}
	if(S-V[0] >= 0){
		arr[0][S-V[0]] = true;
	}
	
	for(int i = 0; i < N-1; i++){
			for(int j = 0; j <= M; j++){
				if(arr[i][j] == true){ // 현재 볼륨으로 곡 연주 가능하다면 다음 곡 볼륨 계산
					if(j+V[i+1] <= M){ // 다음 곡이 더 크고 범위 내에 존재하는 경우
						arr[i+1][j+V[i+1]] = true;
					}
					if(j-V[i+1] >= 0){ // 다음 곡이 더 작고 범위 내에 존재하는 경우
						arr[i+1][j-V[i+1]] = true;
					}
				}
			}
	}
	
	for(int i = M; i >= 0; i--){ // 큰 볼륨부터 확인(가장 먼저 만나는 true값의 열이 최대 볼륨이 됨)
		if(arr[N-1][i] == true){
			cout << i; // 최대 볼륨 출력 후
			return 0; // 종료
		}
	}
	
	cout << -1; // 마지막 곡 연구 불가능하면 -1 출력

	return 0;
}
