#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

struct Pos{
	int r, c, n = 0;
};

void spread(int R, int C, int**room);
void pure(int R, int C, int**room, vector<Pos> &puri);

int main() {
	int R, C, T;
	cin >> R >> C >> T;
	
	int **room = new int*[R];
	for(int i = 0; i < R; i++){
		room[i] = new int[C];
	}
	
	vector<Pos> puri;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			cin >> room[i][j];
			if(room[i][j] == -1){
				Pos p;
				p.r = i;
				p.c = j;
				puri.push_back(p);
			}
		}
	}
	
	for(int i = 0; i < T; i++){
		spread(R, C, room);
		pure(R, C, room, puri);
	}//for(int i=0; i < R; i++){for(int j=0; j < C; j++){cout<<room[i][j]<<" ";}cout<<endl;}
	
	int result = 0;
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(room[i][j] > 0){
				result += room[i][j];
			}
		}
	}
	
	cout << result;
	
	return 0;
}

void spread(int R, int C, int**room){
	vector<Pos> d;
	
	for(int i = 0; i < R; i++){
		for(int j = 0; j < C; j++){
			if(room[i][j] > 0){
				int num_spread = 0;
				
				if(i-1 >= 0){
					if(room[i-1][j] != -1){
						num_spread++;
						
						Pos p;
						p.r = i-1;
						p.c = j;
						p.n = room[i][j]/5;
						d.push_back(p);
					}
				}
				if(i+1 < R){
					if(room[i+1][j] != -1){
						num_spread++;
						
						Pos p;
						p.r = i+1;
						p.c = j;
						p.n = room[i][j]/5;
						d.push_back(p);
					}
				}
				if(j-1 >= 0){
					if(room[i][j-1] != -1){
						num_spread++;

						Pos p;
						p.r = i;
						p.c = j-1;
						p.n = room[i][j]/5;
						d.push_back(p);
					}
				}
				if(j+1 < C){
					if(room[i][j+1] != -1){
						num_spread++;
						
						Pos p;
						p.r = i;
						p.c = j+1;
						p.n = room[i][j]/5;
						d.push_back(p);
					}
				}
				
				Pos p;
				p.r = i;
				p.c = j;
				p.n = -1*num_spread*(room[i][j]/5);
				d.push_back(p);
			}
		}
	}
	
	while(!d.empty()){
		Pos p = d.back();
		d.pop_back();
		
		room[p.r][p.c] += p.n;
	}
	
}
void pure(int R, int C, int**room, vector<Pos> &puri){
	//위쪽 공기청정기
	int purifier = puri[0].r;
	for(int i = purifier-2; i >= 0; i--){
		room[i+1][0] = room[i][0];
	}
	for(int i = 1; i < C; i++){
		if(room[0][i-1] != -1){
			room[0][i-1] = room[0][i];
		}
	}
	for(int i = 1; i < purifier+1; i++){
		room[i-1][C-1] = room[i][C-1];
	}
	for(int i = C-2; i >= 1; i--){
		room[purifier][i+1] = room[purifier][i];
	}
	room[purifier][1] = 0;
	
	//아래쪽 공기청정기
	purifier = puri[1].r;
	for(int i = purifier+2; i < R; i++){
		room[i-1][0] = room[i][0];
	}
	for(int i = 1; i < C; i++){
		if(room[R-1][i-1] != -1){
			room[R-1][i-1] = room[R-1][i];
		}
	}
	for(int i = R-2; i > purifier-1; i--){
		room[i+1][C-1] = room[i][C-1];
	}
	for(int i = C-2; i >= 1; i--){
		room[purifier][i+1] = room[purifier][i];
	}
	room[purifier][1] = 0;
}
