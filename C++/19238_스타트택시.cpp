#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Pos{
	int x, y;
};

struct Passenger{
	Pos start, end;
	int dist = 0;
	
};

int getDist(int N, int **road, Pos start, Pos end);

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	
	int N, M, fuel;
	cin >> N >> M >> fuel;
	
	int **road = new int*[N];
	for(int i = 0; i < N; i++){
		road[i] = new int[N];
		for(int j = 0; j < N; j++){
			cin >> road[i][j];
		}
	}
	
	Pos taxi;
	cin >> taxi.x >> taxi.y;
	taxi.x--;
	taxi.y--;
	
	Passenger *passenger = new Passenger[M+2];
	for(int i = 2; i < M+2; i++){
		int x, y;
		
		cin >> x >> y;
		passenger[i].start.x = x-1;
		passenger[i].start.y = y-1;
        
        if(road[x-1][y-1] == 1){
            cout << -1;
			return 0;
        }
		road[x-1][y-1] = i;
		
		cin >> x >> y;
		passenger[i].end.x = x-1;
		passenger[i].end.y = y-1;
        if(road[x-1][y-1] == 1){
            cout << -1;
			return 0;
        }
		
		passenger[i].dist = getDist(N,road,passenger[i].start,passenger[i].end);
		
		if(passenger[i].dist < 0){
			cout << -1;
			return 0;
		}
	}
	
	int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
	while(M--){
		bool **visit = new bool*[N];
		for(int i = 0; i < N; i++){
			visit[i] = new bool[N];
			memset(visit[i],false,N);
		}
		
		queue<Pos> q;
		q.push(taxi);
		visit[taxi.x][taxi.y] = true;
		
		bool flag = false;
		int dist = 0;
		while(!q.empty()){
			int min_x = N, min_y = N;
			
			int q_size = q.size();
			for(int s = 0; s < q_size; s++){
				int x = q.front().x;
				int y = q.front().y;
				q.pop();
				
				if(road[x][y] > 1){
					if(x < min_x){
						min_x = x;
						min_y = y;
					}
					else if(x == min_x){
						if(y < min_y){
							min_y = y;
						}
					}
					continue;
				}
				
				for(int d = 0; d < 4; d++){
					int dx = x+dir[d][0], dy = y+dir[d][1];
					if(dx >= 0 && dx < N && dy >= 0 && dy < N){
						if(!visit[dx][dy] && road[dx][dy] != 1){
							q.push({dx,dy});
							visit[dx][dy] = true;
						}
					}
				}
			}
			
			if(min_x != N && min_y != N){
				flag = true;
				int num = road[min_x][min_y];
				road[min_x][min_y] = 0;
				taxi.x = passenger[num].end.x;
				taxi.y = passenger[num].end.y;
				fuel -= dist;
				fuel -= passenger[num].dist;
				
				if(fuel < 0){
					fuel = -1;
				}
				else{
					fuel += 2*passenger[num].dist;
                    if(fuel == 0){
                        fuel = -1;
                    }
				}
				break;
			}
			
			dist++;
		}
		
		if(fuel < 0 || !flag){
			break;
		}
	}
	
	if(M != -1){
		fuel = -1;
	}
	
	cout << fuel;
	
	return 0;
}

int getDist(int N, int **road, Pos start, Pos end){
	bool **visit = new bool*[N];
	for(int i = 0; i < N; i++){
		visit[i] = new bool[N];
		memset(visit[i],false,N);
	}
	
	queue<Pos> q;
	q.push(start);
	
	int dist = 0;
	int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
	while(!q.empty()){
		int q_size = q.size();
		for(int s = 0; s < q_size; s++){
			int x = q.front().x;
			int y = q.front().y;
			
			if(x == end.x && y == end.y){
				return dist;
			}
			
			q.pop();
			
			for(int d = 0; d < 4; d++){
				int dx = x+dir[d][0], dy = y+dir[d][1];
				if(dx >= 0 && dx < N && dy >= 0 && dy < N){
					if(!visit[dx][dy] && road[dx][dy] != 1){
						q.push({dx,dy});
						visit[dx][dy] = true;
					}
				}
			}
		}
		dist++;
	}
	
	return -1;
}
