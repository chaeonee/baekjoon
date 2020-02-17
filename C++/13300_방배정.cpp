#include <iostream>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	int arr[2][6]; // 각 그룹의 학생들의 수를 담을 배열
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 6; j++){
			arr[i][j] = 0;
		}
	} // 배열 초기화
	
	for(int n = 0; n < N; n++){
		int S, Y;
		cin >> S >> Y;
		Y--;
		
		arr[S][Y]++; // 해당 그룹에 속한 학생들이 몇 명인지 count
	}
	
	int room = 0; // 필요한 방의 수
	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 6; j++){
			room += arr[i][j] / K; // 한 방에 K명까지 들어갈 수 있으므로 K로 나눈 값만큼의 방 필요
			if(arr[i][j] % K != 0){ // 만약 K로 나눈 나머지가 0이 아니라면 추가로 1개의 방이 더 필요(각 그룹에서 남는 학생들을 위한 방)
				room++;
			}
		}
	}
	
	cout << room;
	
	
	
	return 0;
}