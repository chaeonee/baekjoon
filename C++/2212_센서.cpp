#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	int sensor[N];
	for(int i = 0; i < N; i++){
		cin >> sensor[i];
	}
	sort(sensor,sensor+N); // 입력 받은 센서의 위치 오름차순으로 정렬
	
	int gap[N-1];
	for(int i = 1; i < N; i++){
		gap[i-1] = sensor[i]-sensor[i-1];
	} // 앞 뒤 센서들 간의 거리 구하기
	sort(gap,gap+(N-1),greater<int>()); // 내림차순으로 정렬
	
	int area = sensor[N-1]-sensor[0]; // 초기 값: 전체 범위의 길이(맨 앞 센서와 맨 뒤 센서의 차)
	for(int i = 0; i < K-1; i++){ // 센서 간의 거리가 가장 큰 센서들 사이를 나눠야 함
		if(i >= N-1){ // 집중국의 수가 센서의 수보다 더 많은 경우 센서의 수 만큼만 집중국 세우고 그만 두기
			break;
		}
		area -= gap[i]; // 센서 사이를 나누면 센서 간의 거리만큼 수신 가능 영역의 길이 감소
	}
	
	cout << area;
	
	return 0;
}
