#include <iostream>
#include <vector>
using namespace std;

int fineIndex(vector<int> LIS, int n);

int main() {
	int N;
	cin >> N;
	
	int *A = new int[N];
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	vector<int> LIS;
	LIS.push_back(A[0]); // 길이 1짜리 LIS의 lower bound는 가장 첫 숫자로 초기화
	for(int i = 1; i < N; i++){
		if(LIS.back() < A[i]){ // 벡터의 가장 큰 값이 현재 숫자보다 작다면
			LIS.push_back(A[i]); // LIS 추가
			continue;
		}
		
		// 아니라면
		int j = fineIndex(LIS,A[i]); // 이분 탐색으로 lower bound 갱신 위치 찾기(j를 기준으로 왼쪽은 작고 오른쪽은 크거나 같음)
		LIS[j] = A[i]; // LIS의 lower bound 갱신
	}
	
	cout << LIS.size();
	
	return 0;
}

int fineIndex(vector<int> LIS, int n){ // 이분 탐색
	int l = 0, r = LIS.size()-1, mid;
	while(l < r){ // r이 l보다 클때까지만 탐색(같아지는 순간 탐색 종료될 것)
		mid = (l+r)/2; // 중간 값 계산
		if(LIS[mid] > n){ // 주어진 값보다 만약 중간값이 크다면
			r = mid; // 작은 쪽을 확인해야 하므로 r을 mid 값으로 줄이기
		}
		else if(LIS[mid] < n){ // 주어진 값보다 만약 중간값이 작다면
			l = mid + 1; // 큰 쪽 확인해야 하므로 l을 mid 값으로 늘리기
		}
		else{ // 주어진 값과 중간값이 동일하다면
			return mid; // return mid
		}
	}
	
	return r; // 아니라면 return r(l도 가능, 어차피 같으니까)
}
