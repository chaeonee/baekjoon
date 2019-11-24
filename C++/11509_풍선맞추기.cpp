#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int *H = new int[N];
	for(int i = 0; i < N; i++){
		cin >> H[i];
	}

	int h[1000001] = {0,}; // 특정 높이 풍선 개수 저장할 배열
	int arrow = 0;
	for(int i = 0; i < N; i++){
		int idx = H[i];

		h[idx]++; //현재 높이의 풍선 추가
		if(h[idx+1] == 0){ // 만약 나보다 한 칸 높은 화살이 없으면
			arrow++; // 화살 하나 추가
		}
		else{ // 있으면
			h[idx+1]--; //화살 추가할 필요 없이 사용하고 사용한 화살 없애기
		}
	}

	cout << arrow;


	return 0;
}
