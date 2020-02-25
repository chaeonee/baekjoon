#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct Node{
	vector<int> n; // 각 node의 다음 node들의 index를 담는 vector
	int time = 0; // 해당 node에 도달하기 위해 걸린 시간을 담은 변수
};

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		int N, K;
		cin >> N >> K;
		
		int *D = new int[N];
		memset(D,0,sizeof(int)*N);
		for(int i = 0; i < N; i++){
			cin >> D[i];
		}
		
		Node node[N]; // node들의 배열
		int *inDegree = new int[N]; // 각 node로 들어오는 간선이 몇 개인지 세기 위한 배열
		memset(inDegree,0,sizeof(int)*N);
		for(int k = 0; k < K; k++){
			int x, y;
			cin >> x >> y;
			node[x-1].n.push_back(y-1);
			inDegree[y-1]++;
		}
		int W;
		cin >> W;
		
		queue<int> q; // bfs로 탐색하기 위한 queue
		for(int i = 0; i < N; i++){
			if(inDegree[i] == 0){
				q.push(i); // 해당 node로 들어오는 간선이 없을 때 queue에 삽입
			}
		}
		
		while(!q.empty()){
			int b = q.front();
			q.pop();
			
			if(b == W-1){ // 목적지에 도달하면 break
				break;
			}
			
			int len = node[b].n.size();
			for(int i = 0; i < len; i++){ // 현재 node 뒤로 연결된 node들 확인
				inDegree[node[b].n[i]]--; // 현재 node를 pop했으므로 연결된 indegree 1 감수
				if(inDegree[node[b].n[i]] == 0){ // 더 이상 연결된 indegree 없다면
					q.push(node[b].n[i]); // queue에 push
				}
				if(node[node[b].n[i]].time < node[b].time+D[b]){ // 저장된 시간이 현재 계산된 시간보다 덜 걸린다면, 더 오래 걸리는 시간으로 바꿔주어야 함
					node[node[b].n[i]].time = node[b].time+D[b];
				}
			}
		}
		
		cout << node[W-1].time+D[W-1] << '\n'; // 현재까지 오는 시간이므로 현재 상태가 완성되려면 현재 상태의 시간을 더해주어야 함
	}
	
	return 0;
}