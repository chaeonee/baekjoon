#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N;
	cin >> N;
	
	int arr[2][N+1];
	arr[0][1] = 0;
	arr[1][1] = -1;
	for(int i = 2; i <= N; i++){
		int tmp = 87654321, idx = 0;
		if(i % 2 == 0 && tmp > arr[0][i/2]){
			tmp = arr[0][i/2];
			idx = i/2;
		}
		if(i % 3 == 0 && tmp > arr[0][i/3]){
			tmp = arr[0][i/3];
			idx = i/3;
		}
		if(tmp > arr[0][i-1]){
			tmp = arr[0][i-1];
			idx = i-1;
		}
		
		arr[0][i] = tmp+1;
		arr[1][i] = idx;
		
	}
	
	cout << arr[0][N] << '\n';
	
	int num = N;
	while(num != -1){
		cout << num << " ";
		num = arr[1][num];
	}
	
	return 0;
}
