#include <iostream>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	int visit[100001]; // 방문 및 경로 표시를 위한 visit 배열
	memset(visit,-1,sizeof(int)*100001);
	visit[N] = true;
	
	queue<int> q; // 최단 경로를 구하기 위해 queue를 이용한 bfs 진행
	q.push(N);
	
	int d = -1; // 소요 시간을 나타내는 변
	bool flag = false; // 반복문 탈출을 위한 flag
	while(!q.empty()){
		int S = q.size(); // bfs 진행 시 같은 시간에 갈 수 있는 경우 모두 queue에 넣을 것임 따라서 시간이 매번 증가하면 안됨(본인의 자식들에 대한 연산 수행하기 전에 한 번만 증가)
		
		d++;
		for(int s = 0; s < S; s++){
			int n = q.front();
			q.pop();
			
			if(n == K){ // K와 동일하면 동생에게 도착했다는 의미 -> 탈출
				flag = true;
				break;
			}
			
			//방문한 적 없고 범위를 벗어나지 않는다면 현재 위치를 visit에 저장하여 나중에 트래킹이 가능하게
			if(n-1 >= 0 && visit[n-1] == -1){
				q.push(n-1);
				visit[n-1] = n;
			}
			if(n+1 <= 100000 && visit[n+1] == -1){
				q.push(n+1);
				visit[n+1] = n;
			}
			if(2*n <= 100000 && visit[2*n] == -1){
				q.push(2*n);
				visit[2*n] = n;
			}
		}
		
		if(flag == true){
			break;
		}
	}
	
	cout << d << '\n';
	
	stack<int> s;
	s.push(K);
	int idx = K; // K(도착지점)부터 거꾸로 확인하면서 배열에 삽입
	for(int i = 0; i < d; i++){
		idx = visit[idx];
		s.push(idx);
	}
	
	while(!s.empty()){ // 출력은 삽입의 반대방향으로 진행(따라서 stack 이용하여 삽입 반대로 출력하도록 )
		cout << s.top() << ' ';
		s.pop();
	}
	
	return 0;
}