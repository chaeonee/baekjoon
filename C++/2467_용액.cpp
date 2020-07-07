#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int sol[N];
	for(int i = 0; i < N; i++){
		cin >> sol[i];
	}
	
	int p1 = 0, p2 = N-1;	// 두 개의 포인터(양 끝 값 갖도록)
	int result[2] = {0,}, val = 2000000000; // result: 용액의 특성 값의 합이 가장 0에 가까운 조합을 담을 배열, val: 두 용액의 특성값의 합이 0에 가까운 조합을 구하기 위한 기준 값(용액 특성값의 절대값이 최소인 조합을 구해야 하므로 매우 큰 값으로 초기화)
	while(p1 < p2){ // 두 개의 포인터의 위치(p1이 더 왼쪽, p2가 더 오른쪽에 있어야 함)가 바뀌기 전까지
		if(abs(sol[p1]+sol[p2]) < val){ // 기존 값보다 새로운 용액의 조합이 0에 가까운 특성값을 가지고 있다면
			val = abs(sol[p1]+sol[p2]); // 기준 값 갱신
			result[0] = sol[p1];
			result[1] = sol[p2]; // 용액 조합 갱신
		}
		
		if(sol[p1]+sol[p2] > 0){ // 두 용액의 특성값의 합이 양수 -> 0에 가까워지기 위해서는 더 작아져야 함
			p2--; // 오른쪽 포인터를 1 줄여서 더 작은 값을 가리키도록 함
		}
		else if(sol[p1]+sol[p2] < 0){ // 두 용액의 특성값의 합이 음수 -> 0에 가까워지기 위해서는 더 커져야 함
			p1++; // 왼쪽 포인터를 1 증가시켜서 더 큰 값을 가리키도록 함
		}
		else{ // 0일 경우 -> 목적 달성
			break; // 더 이상 볼 필요 없음
		}
	}
	
	cout << result[0] << " " << result[1];
	
	return 0;
}
