#include <iostream>
#include <deque>
using namespace std;

int main() {
	int N, M, x, y, K;
	cin >> N >> M >> x >> y >> K;
	
	int **map = new int*[N];
	for(int i = 0; i < N; i++){
		map[i] = new int[M];
	}
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> map[i][j];
		}
	}
	
	deque<int> ew(4); //동서(1,4,6,3)
	deque<int> sn(4); //남북(1,5,6,2)
	for(int k = 0; k < K; k++){
		int dir;
		cin >> dir;
		
		int flag = 0;
		if(dir == 1 && y+1 < M){//동
			flag = 1;
			y += 1;
			
			int tmp = ew.front();
			ew.pop_front();
			ew.push_back(tmp);
			
			sn[0] = ew[0];
			sn[2] = ew[2];
		}
		else if(dir == 2 && y-1 >= 0){//서
			flag = 1;
			y -= 1;

			int tmp = ew.back();
			ew.pop_back();
			ew.push_front(tmp);
			
			sn[0] = ew[0];
			sn[2] = ew[2];
		}
		else if(dir == 3 && x-1 >= 0){//북
			flag = 1;
			x -= 1;
			
			int tmp = sn.front();
			sn.pop_front();
			sn.push_back(tmp);
			
			ew[0] = sn[0];
			ew[2] = sn[2];
		}
		else if(dir == 4 && x+1 < N){//남
			flag = 1;
			x += 1;

			int tmp = sn.back();
			sn.pop_back();
			sn.push_front(tmp);
			
			ew[0] = sn[0];
			ew[2] = sn[2];
		}
		
		if(flag == 1){
			if(map[x][y] == 0){
				map[x][y] = ew[2];
			}
			else{
				ew[2] = map[x][y];
				sn[2] = ew[2];
				map[x][y] = 0;
			}
			
			cout << ew[0] << "\n";
		}
	}
	
	return 0;
}
