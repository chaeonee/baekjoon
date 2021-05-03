#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Pos{
	int r, c;
};

bool cmp(Pos a, Pos b){
	return a.c < b.c;
}

void choice(int N, int M, int D, int**map, int start, vector<Pos> &num, vector<Pos> &e, int &max);
int defense(int N, int M, int D, int**map, vector<Pos> &num, vector<Pos> e);

int main() {
   int N, M, D;
   cin >> N >> M >> D; //M이 성의 수
   
   int **map = new int*[N];
   for(int i = 0; i < N; i++){
	map[i] = new int[M];
   }
   
   vector<Pos> e;
   for(int i = 0; i < N; i++){
   	for(int j = 0; j < M; j++){
   		cin >> map[i][j];
   		
   		if(map[i][j] == 1){
   			e.push_back({i,j});
   		}
   	}
   }
   
   vector<Pos> num;
   int max = 0;
   choice(N, M, D, map, 0, num , e, max);
   
   cout << max;
   return 0;
}

void choice(int N, int M, int D, int**map, int start, vector<Pos> &num, vector<Pos> &e, int &max){
	if(num.size() == 3){
		int **copy = new int*[N];
		for(int i = 0; i < N; i++){
			copy[i] = new int[M];
		}
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				copy[i][j] = map[i][j];
			}
		}
		int tmp = defense(N, M, D, copy, num, e);
		if(tmp > max){
			max = tmp;
		}
		return;
	}
	
	for(int i = start; i < M; i++){
		num.push_back({N,i});
		choice(N,M,D,map,i+1,num,e,max);
		num.pop_back();
	}
}

int defense(int N, int M, int D, int**map, vector<Pos> &num, vector<Pos> e){
	int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
	
	int r = 0;
	while(!e.empty()){
		queue<Pos> remove;
		for(int i = 0; i < 3; i++){
			queue<Pos> q;
			
			q.push(num[i]);
			int d = D;
			while(d > 0 && !q.empty()){
				vector<Pos> tmp_remove;
				bool flag = false;
				int S = q.size();
				d--;
				
				for(int s = 0;  s < S; s++){
					Pos p = q.front();
					q.pop();
				
					for(int d = 0; d < 4; d++){
						int new_r = p.r + dir[d][0];
						int new_c = p.c + dir[d][1];
					
						if(new_r >= 0 && new_r < N && new_c >= 0 && new_c < M){
							if(map[new_r][new_c] == 1){
								flag = true;
								tmp_remove.push_back({new_r,new_c});
							}
							else{
								q.push({new_r,new_c});
							}
						}
					}
				}
			
				if(flag == true){
					sort(tmp_remove.begin(),tmp_remove.end(),cmp);
					remove.push(tmp_remove[0]);
					break;
				}
			}
		}
		
		while(!remove.empty()){
			Pos p = remove.front();
			remove.pop();
			
			int s = e.size();
			for(int i = 0; i < s; i++){
				if(p.r == e[i].r && p.c == e[i].c){
					r++;
					map[p.r][p.c] = 0;
					e.erase(e.begin()+i);
					break;
				}
			}
		}
		
		int s = e.size();
		int er = 0;
		for(int i = s-1; i >= 0; i--){//cout << e[i-er].r << " " << e[i-er].c << "/";
			map[e[i].r][e[i].c] = 0;
			e[i].r++;
			
			if(e[i].r >= N){
				e.erase(e.begin()+i);
				er++;
			}
			else{//cout << e[i].r << " " << e[i].c << endl;
				map[e[i].r][e[i].c] = 1;
			}
		}
	}
	
	return r;
}
