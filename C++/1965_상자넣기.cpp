#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int box[N]; // 박스 크기 담은 배열
	for(int n = 0; n < N; n++){
		cin >> box[n];
	}
	
	int arr[N], max_box = 0; // arr은 현재 위치에서 담긴 박스의 최대 개수, max_box는 담을 수 있는 박스의 최대값
	arr[0] = 1;
	for(int i = 1; i < N; i++){
		int tmp = 0; // 현재 박스의 앞 쪽에 있는 박스들 중 담겨 있는 박스 수의 최대값 구하기 위함
		for(int j = 0; j < i; j++){ // 현재 박스의 앞 쪽에 있는 박스들 확인
			if(box[j] < box[i] && arr[j] > tmp){ // 앞 쪽 박스가 현재 박스보다 작고 비교했던 박스들보다 더 많은 박스 품고 있을 때
				tmp = arr[j];
			}
		}
		arr[i] = tmp + 1; // 현재 박스까지 포함해야하기 때문에 +1
		if(arr[i] > max_box){
			max_box = arr[i]; // 그 중 가장 큰 값을 max_box에 저장
		}
	}
	
	cout << max_box;
	
	return 0;
}
