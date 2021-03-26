#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Pos{
	int x, y;
};

Pos check(int N, int M, vector<vector<int> >laptop, int R, int C, vector<vector<int> > sticker){
	Pos start = {-1,-1};
	
	for(int i = 0; i <= N-R; i++){
		bool flag = true;
		for(int j = 0; j <= M-C; j++){
			flag = true;
			for(int r = 0; r < R; r++){
				for(int c = 0; c < C; c++){
					if(sticker[r][c] == 1 && laptop[i+r][j+c] == 1){
						flag = false;
						break;
					}
				}
				if(!flag){
					break;
				}
			}
			
			if(flag){
				start = {i,j};
				break;
			}
		}
		if(flag){
			break;
		}
	}
	
	return start;
}

vector<vector<int> > rotate(int R, int C, vector<vector<int> > sticker){
	vector<vector<int> > r_sticker(C,vector<int>(R));
	for(int r = 0; r < R; r++){
		for(int c = 0; c < C; c++){
			r_sticker[c][R-r-1] = sticker[r][c];
		}
	}
	
	return r_sticker;
}

int main() {
	int N, M, K;
	cin >> N >> M >> K;
	vector<vector<int> >laptop(N,vector<int>(M,0));
	
	int cnt = 0;
	while(K--){
		int R, C;
		cin >> R >> C;
		
		int s_size = 0;
		vector<vector<int> > sticker(R, vector<int>(C));
		for(int r = 0; r < R; r++){
			for(int c = 0; c < C; c++){
				cin >> sticker[r][c];
				if(sticker[r][c] == 1){
					s_size++;
				}
			}
		}
		
		for(int i = 0; i < 4; i++){
			Pos start = check(N,M,laptop,R,C,sticker);
			if(start.x == -1 && start.y == -1){
				sticker = rotate(R,C,sticker);
				swap(R,C);
				continue;
			}
			
			for(int r = 0; r < R; r++){
				for(int c = 0; c < C; c++){
					if(sticker[r][c] == 1){
						laptop[start.x+r][start.y+c] = sticker[r][c];
					}
				}
			}
			cnt += s_size;
			break;
		}
	}
	
	cout << cnt;
	
	return 0;
}
