#include <iostream>
#include <deque>
#include <cstring>
#include <cmath>
using namespace std;

int N;
int *population; // 각 구역의 인구수를 담기 위함
deque<int> *nearby; // 해당 구역과 인접한 구역을 담기 위함

void Gerrymandering(int depth, int s, int p_sum, int &s_min, deque<int> dq, bool *visit, bool *area);
int isConnected(int n_area, bool *area); // 구역들이 연결되어있는지 확인

int main() {
	cin >> N;
	
	int p_sum = 0; // 전체 인구 수
	population = new int[N];
	for(int i = 0; i < N; i++){
		cin >> population[i];
		p_sum += population[i];
	}
	
	nearby = new deque<int>[N];
	for(int i = 0; i < N; i++){
		int num;
		cin >> num;
		for(int j = 0; j < num; j++){
			int tmp;
			cin >> tmp;
			nearby[i].push_back(tmp-1);
		}
	}
	
	bool *visit = new bool[N];
	memset(visit,false,N);
	visit[0] = true; // 항상 1구역은 포함(1구역과 1구역이 아닌 것으로 나눌 것)
	
	bool *area = new bool[N];
	memset(area,false,N);
	area[0] = true;
	
	deque<int> dq;
	int s_min = 10000;
	
  	// 1 구역 제외하고 나머지가 한 구역일 때
	int result = isConnected(N-1,area); // 모든 구역들이 연결되어있는가?(연결되어있다면 연결된 구역의 인구수의 합, 아니면 -1)
	if(result != -1){ // 모든 구역들이 연결되어 있을 때
		int tmp_sub = abs(p_sum-2*result); // 인구수의 차를 구함
		if(tmp_sub < s_min){ // 인구수 차의 최솟값 구하는 과정
			s_min = tmp_sub;
		}
	}
	Gerrymandering(1,0,p_sum,s_min,dq,visit,area); // 1구역에 포함시켜가며 인구수 차의 최솟값 구하기 시작
	
	if(s_min == 10000){ //s_min이 초기값과 같다는 것은 적절한 구역으로 나눌 수 없다는 것...
		cout << -1; // -1 출력
		return 0;
	}
	
	cout << s_min;
	
	return 0;
}

void Gerrymandering(int depth, int s, int p_sum, int &s_min, deque<int> dq, bool *visit, bool *area){
	if(depth == N-1){ // 구역 1개 이상은 무조건 남겨야함 (2개의 구역으로 나눠야 하기 때문)
		return;
	}
	
	int n_push = 0; // dq에 삽입된 원소의 개수
	for(int i = 0; i < nearby[s].size(); i++){
		if(visit[nearby[s][i]] == false){ // visit은 dq에 담겨있는지 여부를 표시하는 배열
			n_push++;
			dq.push_back(nearby[s][i]);
			visit[nearby[s][i]] = true;
		}
	}
	
	int dq_len = dq.size(); // dq는 탐색 가능한 노드들의 배열(탐색 후보 노드)
	for(int i = 0; i < dq_len; i++){
		if(area[dq[i]] == false){ // area는 현재 구역에 포함되어있는지 여부를 표시
			area[dq[i]] = true;
			int result = isConnected(N-depth-1,area); // area에 포함된 구역은 모두 연결되어있음, 포함되어있지 않은 구역들이 모두 연결되어있는지 여부 확인
			if(result != -1){ // 연결되어있다면
				int tmp_sub = abs(p_sum-2*result); // 인구수의 차 구하고
				if(tmp_sub < s_min){ // 최솟값 갱신
					s_min = tmp_sub;
				}
			}
			Gerrymandering(depth+1,dq[i],p_sum,s_min,dq,visit,area); // 재귀로 진행
			area[dq[i]] = false;
		}
	}
	
	for(int i = 0; i < n_push; i++){ // 재귀 모두 돌고 나오면 dq에 넣었던 값들도 빼주어야 함 
		int tmp = dq.back(); // 뒤로 삽입했기 때문에 뒤부터 빼면 됨
		visit[tmp] = false; // dq에 담겨있지 않다는 표시로 다시 바꿔줌
		dq.pop_back();
	}
}

int isConnected(int n_area, bool *area){ // area에 포함되지 않은 구역들이 연결되어 있는가?
	int sum = 0; // area에 포함되지 않은 구역의 인구수를 담을 변수
	
	bool visit[N];
	memset(visit,false,N);
	
	deque<int> q;
	for(int i = 0; i < N; i++){
		if(area[i] == false){
			visit[i] = true;
			q.push_back(i);
			break;
		}
	} // area에 포함되지 않은 구역 중 하나를 queue에 삽입(deque이용하였지만 queue로 사용할 것)
	
	while(!q.empty()){ // bfs 시작
		int n = q.front();
		q.pop_front();
		
		n_area--; // n_area는 area에 포함되지 않은 area의 수를 의미
		sum += population[n];
		
		int nearby_len = nearby[n].size();
		for(int i = 0; i < nearby_len; i++){
			int idx = nearby[n][i];
			if(visit[idx] == false && area[idx] == false){ // 해당 노드와 인접하면서 area에 포함되지 않으면
				visit[idx] = true; // 방문표시
				q.push_front(idx); // queue에 추가
			}
		}
	}
	
	if(n_area != 0){ // area에 포함되어있지 않은 것들이 모두 연결되어 있다면 n_area가 0이 될 것(모두 방문 가능하니까) -> 따라서 n_area가 0이 아니면 연결되어 있지 않다는 뜻
		return -1; // -1 return
	}
	
	return sum; // 모두 연결되어있다면 area에 포함되지 않은 구역의 인구수 return
}
