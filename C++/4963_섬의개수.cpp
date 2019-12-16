#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Pos{
	int h, w;
};

int main() {
	int dir[8][2] = {{1,0},{-1,0},{0,1},{0,-1},{1,1},{-1,1},{1,-1},{-1,-1}}; // 방향(상,하,좌,우,대각선 4방향)
	while(1){
		int w, h;
		cin >> w >> h;
		
		if(w == 0 && h == 0){ // while 탈출(종료) 조건
			break;
		}
		
		int **map = new int*[h];
		for(int i = 0; i < h; i++){
			map[i] = new int[w];
		}
		
		vector<Pos> v; // 육지인 좌표를 담을 배열
		for(int i = 0; i < h; i++){
			for(int j = 0; j < w; j++){
				cin >> map[i][j];
				
				if(map[i][j] == 1){
					v.push_back({i,j});
				}
			}
		}
		
		int num = 0; // 영역의 수를 세기 위한 변수
		int v_len = v.size();
		for(int l = 0; l < v_len; l++){ // 육지인 좌표를 root로 하여 bfs 진행
			if(map[v[l].h][v[l].w] == 0){ // 원래는 육지였지만 탐색을 통해 이미 방문한 경우
				continue; // pass하기
			}
			
			num++;
			
			queue<Pos> q; // bfs를 진행하기 위한 queue
			q.push(v[l]);
			map[v[l].h][v[l].w] = 0; // 방문한 경우 중복 이동하지 못하게 0으로 바꾸기
			while(!q.empty()){
				Pos p = q.front();
				q.pop();
				
				for(int i = 0; i < 8; i++){
					int tmp_h, tmp_w;
					tmp_h = p.h + dir[i][0];
					tmp_w = p.w + dir[i][1];
					
					if(tmp_h >= 0 && tmp_h < h && tmp_w >= 0 && tmp_w < w){ // 범위 넘어가지 않게 예외처리
						if(map[tmp_h][tmp_w] != 0){ // 방문한 적 없는 육지일 때
							map[tmp_h][tmp_w] = 0; // 이제 방문했으니 0으로 바꿔주고
							q.push({tmp_h,tmp_w}); // 다음 탐색을 위해 queue에 추가
						}
					}
				}
			}
		}
		
		cout << num << '\n';
	}
	
	return 0;
}