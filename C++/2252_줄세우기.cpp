#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	int indegree[N] = {0,}; // 본인 이전에 세워야 하는 사람의 수
	vector<int> v[N]; // 본인 이후에 서 있는 사람 목록
	
	for(int i = 0; i < M; i++){
		int A, B;
		cin >> A >> B;
    
    		// index 0부터 시작하므로 1빼준 값 넣기
		v[A-1].push_back(B-1); // A뒤에 B가 서 있음을 저장
		indegree[B-1]++; // B 전에 와야할 사람의 수 1증가
	}
	
	if(N == 1){ // N = 1이면, 1만 출력하면 끝남 while문 들어가면 무한루프 돌기 때문에 미리 빼줌...
		cout << 1;
	}
	
	int num = 0; // 모든 사람 출력하기 위함
	while(N != 1 && num < N){ // num과 N이 같아지면 모든 사람 출력한 것이므로 while문에서 빠져나오기
		for(int i = 0; i < N; i++){
			if(indegree[i] == 0){ // indegree가 0이면 내 앞에 올 사람 없기 때문에 출력해줘도 됨
				num++; // 출력한 사람 수 증가
				indegree[i]--; // indegree가 -1이 되므로 더 이상 접근하지 않을 것(visit의 역할 해준다고 보면 됨)
				cout << i+1 << " "; // 출력(index는 0부터 사람 번호는 1부터 시작이므로 index에 1더해서 출력해주기
				
				for(int j = 0; j < v[i].size(); j++){ // 현재 출력된 노드를 제거하는 과정
					indegree[v[i][j]]--; // 현재 출력된 노드와 연결된 다음 노드들의 indegree 1씩 줄여줌(현재 노드가 사라지기 때문)
				}
				break;
			}
		}
	}
	
	return 0;
}
