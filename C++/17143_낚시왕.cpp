#include <iostream>
#include <queue>
using namespace std;

struct Shark{
	bool ex = false;
	int r, c, s, d, z = 0; 
};

struct Pos{
	int r, c;
};

int main() {
	int R, C, M;
	cin >> R >> C >> M;
	
	queue<Shark> shark;
	for(int i = 0; i < M; i++){
		Shark s;
		cin >> s.r >> s.c >> s.s >> s.d >> s.z;
		s.r--;
		s.c--;
		s.d--;
		shark.push(s);
	}
	
	int total = 0;
	int move[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};//위아오왼
	int ch_dir[4] = {1,0,3,2};//위아오왼
	for(int c = 0; c < C; c++){
		Shark area[R][C];
		
		queue<Pos> q;
		while(!shark.empty()){
			Shark s = shark.front();
			shark.pop();
			//넣기
			if(area[s.r][s.c].ex == true){
				if(area[s.r][s.c].z < s.z){
					area[s.r][s.c].s = s.s;
					area[s.r][s.c].z = s.z;
					area[s.r][s.c].d = s.d;
				}
			}
			else{
				Pos p;
				p.r = s.r;
				p.c = s.c;
				q.push(p);
				
				area[s.r][s.c].ex = true;
				area[s.r][s.c].s = s.s;
				area[s.r][s.c].z = s.z;
				area[s.r][s.c].d = s.d;
			}
		}
		
		int r_r;
		int r_c;
		for(int i = 0; i < R; i++){
			if(area[i][c].ex == true){
				total += area[i][c].z;
				area[i][c].ex = false;
				r_r = i;
				r_c = c;
				break;
			}
		}
		
		while(!q.empty()){
			Pos p = q.front();
			q.pop();
			
			if(p.r != r_r || p.c != r_c){
				Shark tmp;
				tmp.r = p.r;
				tmp.c = p.c;
				tmp.s = area[p.r][p.c].s;
				tmp.z = area[p.r][p.c].z;
				tmp.d = area[p.r][p.c].d;
				shark.push(tmp);
			}
		}
		
		int q_size = shark.size();
		for(int i = 0; i < q_size; i++){
			Shark s = shark.front();
			shark.pop();//cout << s.r+1 << " " << s.c+1;
			if(s.d == 0){
				int tmp = s.r - s.s;
				
				if(tmp < 0){
					tmp *= -1;
					
					int a = tmp / (R-1); // 몫
					int b = tmp % (R-1); //나머지
					
					if(a%2 == 0){
						tmp = b;
						s.d = ch_dir[s.d];
					}
					else{
						tmp = R-1-b;;
					}
				}
				s.r = tmp;
			}
			else if(s.d == 1){
				int tmp = s.r + s.s;
				
				if(tmp >= R){
					tmp -= R-1;
					
					int a = tmp / (R-1); // 몫
					int b = tmp % (R-1); //나머지
					
					if(a%2 == 0){
						tmp = R-1-b;
						s.d = ch_dir[s.d];
					}
					else{
						tmp = b;
					}
				}
				s.r = tmp;
			}
			else if(s.d == 2){
					int tmp = s.c + s.s;
				
				if(tmp >= C){
					tmp -= C-1;
					
					int a = tmp / (C-1); // 몫
					int b = tmp % (C-1); //나머지
					
					if(a%2 == 0){
						tmp = C-1-b;
						s.d = ch_dir[s.d];
					}
					else{
						tmp = b;
					}
				}
				s.c = tmp;
			}
			else if(s.d == 3){
				int tmp = s.c - s.s;
				
				if(tmp < 0){
					tmp *= -1;
					
					int a = tmp / (C-1); // 몫
					int b = tmp % (C-1); //나머지
					
					if(a%2 == 0){
						tmp = b;
						s.d = ch_dir[s.d];
					}
					else{
						tmp = C-1-b;;
					}
				}
				s.c = tmp;
			}
			shark.push(s);
		}
	}
	
	cout << total;
	
	return 0;
}
