#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getPermutation(int M, vector<int> arr, int s, int depth, vector<int> v);

int main() {
	int N, M;
	cin >> N >> M;
	
	bool visit[10001] = {0,}; // 수의 중복을 막기 위한 배열
	vector<int> arr;
	for(int i = 0; i < N; i++){
		int tmp;
		cin >> tmp;
		
		if(visit[tmp] == false){ // 이미 존재하는 수는 vector에 넣지 않고 새로운 수만 push
			visit[tmp] = true;
			arr.push_back(tmp);
		}
	}
	
	sort(arr.begin(),arr.end()); // 오름차순 정렬
	
	vector<int> v;
	getPermutation(M,arr,0,0,v);
	
	return 0;
}

void getPermutation(int M, vector<int> arr, int s, int depth, vector<int> v){
	if(depth == M){ // 길이 M인 순열이 만들어지면
		for(int i = 0; i < M; i++){ // 출력
			cout << v[i] << " ";
		}
		cout << '\n';
		
		return;
	}
	
	int arr_len = arr.size();
	for(int i = s; i < arr_len; i++){ // 중복 존재할 수도 있기 때문에 s부터 시작할 수 있으며 중복 체크 안해도 됨
		v.push_back(arr[i]);
		getPermutation(M,arr,i,depth+1,v); // 재귀
		v.pop_back();
	}
}
