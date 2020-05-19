#include <iostream>
#include <queue>
using namespace std;

struct Pos{
	int x, time;
};

int main() {
	int N, K;
	cin >> N >> K;
	
	bool visit[100001] = {0,}; // 수빈이가 현재 위치에 방문했는지의 여부를 담을 배열
	visit[N] = true;
	
	queue<Pos> q;
	q.push({N,0}); // bfs 위한 queue, 수빈이의 초기 위치로 초기화(시간은 0초)  *** priority queue를 이용해야 할 것 같음..
	
	int result = 0; // 동생을 찾는데 걸리는 최종 시간
	while(!q.empty()){
		Pos p = q.front();
		q.pop();
		
		if(p.x == K){ // 동생 위치에 도달(동생을 찾았다면)
			result = p.time; // 시간 저장 후 while문 탈출
			break;
		}
		
		if(2*p.x <= 100001 && visit[2*p.x] == false){ // 순간이동할 경우(시간이 증가하지 않기 때문에 가장 먼저 확인하여 넣어 주어야 함)
			q.push({2*p.x,p.time});
			visit[2*p.x] = true;
		}
		if(p.x-1 >= 0 && visit[p.x-1] == false){ // 뒤로 한 칸 이동
			q.push({p.x-1,p.time+1});
			visit[p.x-1] = true;
		}
		if(p.x+1 <= 100001 && visit[p.x+1] == false){ // 앞으로 한 칸 이동
			q.push({p.x+1,p.time+1});
			visit[p.x+1] = true;
		}
	}
	
	cout << result;
	
	return 0;
}
