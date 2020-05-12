#include <iostream>
using namespace std;

int getSum(int N, int S, int *arr, int s, int cur, int result);

int main() {
	int N, S;
	cin >> N >> S;
	
	int *arr = new int[N];
	for(int i = 0; i < N; i++){
		cin >> arr[i];
	}
	
	int result = 0;
	result = getSum(N,S,arr,0,0,result);
  cout << result;
	
	return 0;
}

int getSum(int N, int S, int *arr, int s, int cur, int result){
	for(int i = s; i < N; i++){
		cur += arr[i]; // 해당 위치의 값 더하고
		if(cur == S){ // S와 동일한지 확인
			result++; // 동일하면 reesult 1증가
		}
		
		result = getSum(N,S,arr,i+1,cur,result); // 다음 인덱스부터 확인하도록 하므로써 방문 확인 필요 없게 함
		cur -= arr[i]; // 백트래킹
	}
	
	return result;
}
