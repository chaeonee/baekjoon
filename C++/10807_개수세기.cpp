#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int *arr = new int[N];
	for(int i = 0; i < N; i++){ // N개만큼의 숫자 arr에 저장
		cin >> arr[i];
	}
	
	int v;
	cin >> v;
	
	int count = 0; // arr에 저장된 숫자 중 v와 같은 숫자 몇개인지 저장할 변수
	for(int i = 0; i < N; i++){
		if(arr[i] == v){ // arr에 v와 같은 값 존재하면 count 1증가
			count++;
		}
	}
	
	cout << count;
	
	return 0;
}