#include <iostream>
using namespace std;

bool isPossible(int arr[], long long int mid, int K, int N);

int main() {
	int K, N;
	cin >> K >> N;
	
	int arr[K]; // 랜선들의 길이를 담을 배열
	long long int right = 0, left = 1; // 최대 길이의 랜선을 기준으로 수행할 것 right는 가장 긴 랜선의 길이가 될 것임
	for(long long int i = 0; i < K; i++){
		cin >> arr[i];
		
		if(right < arr[i]){
			right = arr[i];
		}
	}
	
	long long int result = 0; // 최대 길이를 담을 변수
	while(right >= left){ // 이분탐색 진행
		long long int mid = (right+left)/2;
		bool flag = isPossible(arr,mid,K,N); // N개의 랜선이 만들어졌는지
		if(flag == true){ // N개의 랜선이 만들어졌다면
			left = mid+1; // 랜선의 크기를 키워서 탐색(큰쪽 탐색)
			result = mid; // mid 값이 랜선의 길이가 되는데, 만약 N개의 랜선이 만들어졌다면 result에 일단 대입(계속 대입해도 되는 이유: N개의 랜선이 만들어졌다면 이전의 mid값보다 작아질 일 없음)
		}
		else{ // N개의 랜선이 만들어지지 않았다면
			right = mid-1; // 랜선의 크기를 줄여서 탐색(작은쪽 탐색)
		}
	}
	
	cout << result;

	return 0;
}

bool isPossible(int arr[], long long int mid, int K, int N){ // N개의 랜선이 만들어졌는지 확인하는 함수
	int tmp = 0;
	for(int i = 0; i < K; i++){
		tmp += arr[i]/mid; // 랜선이 몇 개 만들어지는지 count
	}
	
	if(tmp >= N){ // N개보다 많이 만들어져도 되기 때문에 현재 만들어진 랜선이 목표하는 랜선의 수보다 크거나 같다면 true를 return
		return true;
	}
	
	return false; // 아니라면 false를 return
}
