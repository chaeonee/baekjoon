#include <iostream>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		int n;
		cin >> n;
		
		int arr[n+1];
		arr[0] = 1; // arr[0] = 1은 초기값
		
		for(int i = 1; i < 4; i++){ // 1이 들어가는 경우의 수부터 3이 들어가는 경우의 수까지 따지기 위함
			for(int j = i; j < n+1; j++){ // 현재 i보다 작은 값은 i로 만들 수 없기 때문에 i부터 시작해야함
				arr[j] = 0;
				for(int k = 1; k <= i; k++){ // 이전 i개의 배열 값을 더해줌
					arr[j] += arr[j-k];
				}
			}
		}
		
		cout << arr[n] << '\n';
	}
	return 0;
}
