#include <iostream>
#include <set>
#include <queue>
#include <cstring>
using namespace std;

struct Pos{
	int x, y;
};

int main() {
   int N;
   cin >> N;
   
   int **area = new int*[N];
   for(int i = 0; i < N; i++){
      area[i] = new int[N];
   }
   
   set<int> H; // 높이에 관한 set
   for(int i = 0; i < N; i++){
      for(int j = 0; j < N; j++){
         int n;
         cin >> n;
         H.insert(n);
         area[i][j] = n;
      }
   }
   
   int num = 1; // 구역의 수 초기화(침수된 곳 없으면 1임)
   
   set<int>::iterator iter;
   for(iter = H.begin(); iter != H.end(); iter++){
   	bool **visit = new bool*[N]; //방문 여부 표시할 배열
   	for(int i = 0; i < N; i++){
      visit[i] = new bool[N];
      memset(visit[i],false,sizeof(bool)*N);
   }
   
   int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; //상하좌우
   int tmp_num = 0; // 현재 높이까지 잠겼을 때의 구역 수
   	for(int i = 0; i < N; i++){
   		for(int j = 0; j < N; j++){
   			if(area[i][j] > *iter && visit[i][j] == false){ // 높이가 현재 침수 높이보다 높아야하며 방문한 적 없어야 함
   				tmp_num++;
   				visit[i][j] = true;
   				
   				queue<Pos> q;
   				q.push({i,j});
   				
   				while(!q.empty()){ // 현재 i,j를 시작으로 bfs(bfs로 연결되어 있으면 구역 하나)
   					Pos p = q.front();
   					q.pop();
   					
   					for(int d = 0; d < 4; d++){
   						int x = p.x + dir[d][0];
   						int y = p.y + dir[d][1];
   						if(x >= 0 && x < N && y >= 0 && y < N && visit[x][y] == false && area[x][y] > *iter){
   							visit[x][y] = true;
   							q.push({x,y});
   						}
   					}
   				}
   			}
   			else if(area[i][j] <= *iter && visit[i][j] == false){ // 침수지역이므로 false여도 방문한 셈 치기
   				visit[i][j] = true;
   			}
   		}
   	}
   	
   	if(num < tmp_num){ // 최댓값 구하는 과
   		num = tmp_num;
   	}
   }
   
   cout << num;
   
   return 0;
}