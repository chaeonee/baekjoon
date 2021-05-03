#include <iostream>
#include <vector>
using namespace std;

struct CCTV{
	int r, c, num;
};

int monitor(int N, int M, int **map, vector<CCTV>& cctv, int min);
void up(int r, int c, int **map);
void down(int N, int r, int c, int **map);
void left(int r, int c, int **map);
void right(int M, int r, int c, int **map);
void copy(int N, int M, int **a, int **b);

int main() {
	int N, M;
	cin >> N >> M;
	
	int **map = new int*[N];
	for(int i = 0; i < N; i++){
		map[i] = new int[M];
	}
	
	vector<CCTV> cctv;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> map[i][j];
			if(map[i][j] != 0 && map[i][j] != 6){
				CCTV c;
				c.r = i;
				c.c = j;
				c.num = map[i][j];
				cctv.push_back(c);
			}
		}
	}
	
	int result = monitor(N, M, map, cctv, 100000);
	cout << result;
	
	return 0;
}

int monitor(int N, int M, int **map, vector<CCTV>& cctv, int min){
	if(cctv.empty()){
		int tmp = 0;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				//cout << map[i][j] << " ";
				if(map[i][j] == 0){
					tmp++;
				}
			}//cout << endl;
		}//cout << endl;
		if(tmp < min){
			min = tmp;
		}
		return min;
	}
	
	CCTV c = cctv.back();
	cctv.pop_back();
	
	
	int **tmp_map = new int*[N];
	for(int i = 0; i < N; i++){
		tmp_map[i] = new int[M];
	}
	copy(N,M,map,tmp_map);
	
	if(c.num == 1){
		//위
		up(c.r, c.c, map);
		min = monitor(N,M,map,cctv,min);
		copy(N,M,tmp_map,map);
		
		//아래
		down(N, c.r, c.c, map);
		min = monitor(N,M,map,cctv,min);
		copy(N,M,tmp_map,map);
		
		//오른쪽
		right(M, c.r, c.c, map);
		min = monitor(N,M,map,cctv,min);
		copy(N,M,tmp_map,map);
		
		//왼쪽
		left(c.r, c.c, map);
		min = monitor(N,M,map,cctv,min);
		copy(N,M,tmp_map,map);
	}
	else if(c.num == 2){
		//오른쪽, 왼쪽
		right(M, c.r, c.c, map);
		left(c.r, c.c, map);
		min = monitor(N,M,map,cctv,min);
		copy(N,M,tmp_map,map);
		
		//위, 아래
		up(c.r, c.c, map);
		down(N, c.r, c.c, map);
		min = monitor(N,M,map,cctv,min);
		copy(N,M,tmp_map,map);
	}
	else if(c.num == 3){
		//위, 오른쪽
		up(c.r, c.c, map);
		right(M, c.r, c.c, map);
		min = monitor(N,M,map,cctv,min);
		copy(N,M,tmp_map,map);
		
		//오른쪽, 아래
		right(M, c.r, c.c, map);
		down(N, c.r, c.c, map);
		min = monitor(N,M,map,cctv,min);
		copy(N,M,tmp_map,map);
		
		//아래, 왼쪽
		down(N, c.r, c.c, map);
		left(c.r, c.c, map);
		min = monitor(N,M,map,cctv,min);
		copy(N,M,tmp_map,map);
		
		//왼쪽, 위
		left(c.r, c.c, map);
		up(c.r, c.c, map);
		min = monitor(N,M,map,cctv,min);
		copy(N,M,tmp_map,map);
	}
	else if(c.num == 4){
		//오른쪽, 왼쪽, 위
		right(M, c.r, c.c, map);
		left(c.r, c.c, map);
		up(c.r, c.c, map);
		min = monitor(N,M,map,cctv,min);
		copy(N,M,tmp_map,map);
		
		//오른쪽, 왼쪽, 아래
		right(M, c.r, c.c, map);
		left(c.r, c.c, map);
		down(N, c.r, c.c, map);
		min = monitor(N,M,map,cctv,min);
		copy(N,M,tmp_map,map);
		
		//위, 아래, 오른쪽
		up(c.r, c.c, map);
		down(N, c.r, c.c, map);
		right(M, c.r, c.c, map);
		min = monitor(N,M,map,cctv,min);
		copy(N,M,tmp_map,map);
		
		//위, 아래, 왼쪽
		up(c.r, c.c, map);
		down(N, c.r, c.c, map);
		left(c.r, c.c, map);
		min = monitor(N,M,map,cctv,min);
		copy(N,M,tmp_map,map);
	}
	else{
		//사방
		up(c.r, c.c, map);
		down(N, c.r, c.c, map);
		left(c.r, c.c, map);
		right(M, c.r, c.c, map);
		min = monitor(N,M,map,cctv,min);
		copy(N,M,tmp_map,map);
	}
	
	cctv.push_back(c);
	return min;
}

void up(int r, int c, int **map){
	for(int i = r; i >= 0; i--){
		if(map[i][c] == 0){
			map[i][c] = -1;
		}
		else if(map[i][c] == 6){
			return;
		}
	}
}

void down(int N, int r, int c, int **map){
	for(int i = r; i < N; i++){
		if(map[i][c] == 0){
			map[i][c] = -1;
		}
		else if(map[i][c] == 6){
			return;
		}
	}
}

void left(int r, int c, int **map){
	for(int i = c; i >= 0; i--){
		if(map[r][i] == 0){
			map[r][i] = -1;
		}
		else if(map[r][i] == 6){
			return;
		}
	}
}

void right(int M, int r, int c, int **map){
	for(int i = c; i < M; i++){
		if(map[r][i] == 0){
			map[r][i] = -1;
		}
		else if(map[r][i] == 6){
			return;
		}
	}
}

void copy(int N, int M, int **a, int **b){
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			b[i][j] = a[i][j];
		}
	}
}
