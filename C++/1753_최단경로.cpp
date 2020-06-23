#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Edge{
	int des, w;
}; // 정점 및 가중치

struct cmp{
	bool operator()(Edge e1, Edge e2){
		if(e1.w == e2.w){
			return e1.des > e2.des;
		}
		
		return e1.w > e2.w;
	}
}; // priority queue 정렬을 위한 struct 가중치의 크기가 작은 것에 더 높은 우선순위(같을 때는 정점 번호 순서대로)

int main() {
	int V, E;
	cin >> V >> E;
	
	int K;
	cin >> K;
	
	vector<Edge> weight[V]; // 해당 정점과 연결된 정점&가중치를 저장하기 위한 벡터 배열
	for(int i = 0; i < E; i++){
		int u, v, w;
		cin >> u >> v >> w;
		weight[u-1].push_back({v-1,w});
	}
	
	vector<int> cost(V,5000000); // 시작 점으로부터의 최단경로를 저장하기 위한 벡터(매우 큰 값으로 초기화)
	cost[K-1] = 0; // 시작점은 0으로 초기화
	priority_queue<Edge,vector<Edge>,cmp> pq; // priority queue 생성
	pq.push({K-1,0}); // priority queue에 시작점 넣기
	while(!pq.empty()){
		Edge e = pq.top(); // 현재 삽입된 정점 중 경로가 가장 작은 정점이 return될 것
		pq.pop();
		
		int w_size = weight[e.des].size();
		for(int i = 0; i < w_size; i++){ // 현재 정점과 연결된 정점들 탐색
			int v = weight[e.des][i].des, w = weight[e.des][i].w;
			if(cost[v] > w + e.w){ // 기존에 저장된 최단경로와 새로운 경로의 길이 비교 -> 새로운 경로의 길이가 더 짧으면
				cost[v] = w + e.w; // 최단 경로 갱신
				pq.push({v, w+e.w}); // priority queue에 삽입
			}
		}
	}
	
	for(int i = 0; i < V; i++){
		if(cost[i] == 5000000){ // 매우 큰 값 -> 시작점에서 해당 정점으로 이동할 수 없음
			cout << "INF\n"; // "INF" 출력
			continue;
		}
		
		// 이동할 수 있는 경우 최단 경로 출력
		cout << cost[i] << '\n'; 
	}
	
	return 0;
}
