#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

void getPerm(int M, int N, int *num, bool *visit, vector<int> v){ // 크기가 N인 순열을 구하기 위한 함수
	if(v.size() == N){ // 종료 조건: 선택된 값의 수가 N개일때(크키가 N인 순열을 구해야 함)
		for(int i = 0; i < N; i++){ // v에 있는 값 순서대로 출력
			cout << v[i] << " ";
		}cout << '\n';
		return;
	}
	
	for(int i = 0; i < M; i++){
		if(visit[i] == false){ // 선택되지 않은 수라면(순열에는 중복으로 선택된 수가 없어야 함)
			visit[i] = true; // 방문 표시
			v.push_back(num[i]); // v에 삽입
			
			getPerm(M,N,num,visit,v); // 재귀
			
			v.pop_back(); // v에서 삭제(다음 순열에 또 포함될 가능성 열어둠)
			visit[i] = false; // 방문 표시 취소
		}
	}
}

int main() {
	int M, N;
	cin >> M >> N;
	
	bool *visit = new bool[M];
	memset(visit,false,M);
	
	int *num = new int[M];
	for(int i = 0; i < M; i++){
		cin >> num[i];
	}
	
	sort(num,num+M); // 사전 순으로 출력하기 위해 sorting 진행
	
	vector<int> v;
	getPerm(M,N,num,visit,v);
	
	return 0;
}
