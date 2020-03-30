#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Pos{
	int x, y;
};

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		int I;
		cin >> I;
		
		bool **visit = new bool*[I]; // 나이트의 방문을 확인할 배열
		for(int i = 0; i < I; i++){
			visit[i] = new bool[I];
			memset(visit[i],false,sizeof(bool)*I);
		}
		
		Pos cur, goal; // 현재 위치와 최종 위치
		cin >> cur.x >> cur.y;
		cin >> goal.x >> goal.y;
		
		int dir[8][2] = {{-2,-1},{-2,1},{-1,-2},{-1,2},{2,-1},{2,1},{1,-2},{1,2}}; // 나이트의 이동 방향
		
		queue<Pos> q; // BFS로 탐색
		q.push(cur);
		visit[cur.x][cur.y] = true;
		
		int move = 0; // 이동 횟수
		bool flag = false; // goal을 만나면 true가 됨
		if(cur.x == goal.x && cur.y == goal.y){
			flag = true; // 입력받은 현재 위치와 최종 위치가 동일할 때는 이동할 필요 없음
		}
		while(!q.empty() && flag == false){
			move++;
			
			int q_len = q.size(); // move 단위로 이동할 것 따라서 queue의 크기만큼 돌면 move 1씩 증가
			for(int i = 0; i < q_len; i++){  // BFS
				cur = q.front();
				q.pop();
				
				for(int d = 0; d < 8; d++){
					int x = cur.x+dir[d][0], y = cur.y+dir[d][1];
					if(x >= 0 && x < I && y >= 0 && y < I && visit[x][y] == false){
						if(x == goal.x && y == goal.y){
							flag = true; // 최종 위치에 도착하면 true로 flag 바꾸고 break
							break;
						}
						visit[x][y] = true;
						q.push({x,y}); // 최종 위치가 아니라면 방문 표시 후 queue에 값 추가
					}
				}
			}
		}
		
		cout << move << '\n';
	}
	
	return 0;
}
