#include <iostream>
#include <vector>
using namespace std;

struct Singer{
	int indegree = 0;
	vector<int> next_singer;
}; // 가수들의 정보 담을 struct / indegree: 현재 가수 바로 이전에 출연해야 하는 가수들의 수, next_singer: 현재 가수 바로 다음에 올 수 있는 가수

int main() {
	int N, M;
	cin >> N >> M;
	
	Singer singer[N];
	for(int m = 0; m < M; m++){
		int num;
		cin >> num;
		
		int prev;
		cin >> prev;
		prev--;
		for(int n = 1; n < num; n++){
			int tmp;
			cin >> tmp;
			singer[tmp-1].indegree++;
			singer[prev].next_singer.push_back(tmp-1);
			prev = tmp-1;
		}
	}
	
	vector<int> v; // 출연 순서대로 저장할 vector
	while(true){ // 위상 정렬 시작
		int idx = -1;
		for(int i = 0; i < N; i++){
			if(singer[i].indegree == 0){ // indegree가 0이면 현재 출연해도 됨
				singer[i].indegree--; // indegree를 1줄여서 -1을 만듦으로써 visit 역할 수행
				idx = i;
				v.push_back(i+1);
				break;
			}
		}
		
		if(idx == -1){ // 더 이상 출연할 수 있는 가수 없음
			break;
		}
		
		for(int i = 0; i < singer[idx].next_singer.size(); i++){
			int tmp = singer[idx].next_singer[i];
			singer[tmp].indegree--; // 현재 가수는 이미 출연했으므로, 현재 가수 다음으로 출연할 수 있는 가수들의 indegree 1 감소
		}
	}
	
	if(v.size() != N){ // 모두 출연못하는 경우를 의미
		cout << 0;
	}
	else{
		for(int i = 0; i < N; i++){
			cout << v[i] << '\n';
		}
	}
	
	return 0;
}
