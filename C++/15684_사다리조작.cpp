#include <iostream>
#include <cstring>
using namespace std;

struct Pos{
	int x, y;
};

void putLadder(int N, int H, bool **ladder, int s, int depth, int &cnt);
bool check(int N, int H, bool **ladder);

int main() {
	int N, M, H;
	cin >> N >> M >> H;
	
	bool **ladder = new bool*[H];
	for(int i = 0; i < H; i++){
		ladder[i] = new bool[N-1];
		memset(ladder[i],false,N-1);
	}
	
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		ladder[a-1][b-1] = true;
	}
	
	if(check(N,H,ladder)){
		cout << 0;
		return 0;
	}
	
	int cnt = 7654321;
	putLadder(N,H,ladder,0,1,cnt);
	
	if(cnt == 7654321){
		cnt = -1;
	}
	
	cout << cnt;
	
	return 0;
}

void putLadder(int N, int H, bool **ladder, int s, int depth, int &cnt){
	if(depth > 3 | depth >= cnt){
		return;
	}
	
	for(int i = s; i < H; i++){
		for(int j = 0; j < N-1; j++){
			if(ladder[i][j] || (j-1 >= 0 && ladder[i][j-1]) || (j+1 < N-1 && ladder[i][j+1])){
				continue;
			}
			
			ladder[i][j] = true;
			if(!check(N,H,ladder)){
				putLadder(N,H,ladder,i,depth+1,cnt);
			}
			else{
				cnt = depth;
			}
			ladder[i][j] = false;
		}
	}
}

bool check(int N, int H, bool **ladder){
	for(int i = 0; i < N; i++){
		int x = 0, y = i;
		
		while(x < H){
			bool flag = false;
			if(y-1 >= 0 && ladder[x][y-1]){
				flag = true;
				x += 1;
				y -= 1;
			}
			else if(y < N-1 && ladder[x][y]){
				flag = true;
				x += 1;
				y += 1;
			}
			
			if(!flag){
				x+= 1;
			}
		}
		
		if(y != i){
			return false;
		}
	}
	
	return true;
}
