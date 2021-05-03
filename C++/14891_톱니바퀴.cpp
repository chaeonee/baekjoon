#include <iostream>
#include <deque>
#include <queue>
#include <stdio.h>
using namespace std;

struct Move{
	int no, dir;
};

int main() {
	deque<int> gear[4];
	
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 8; j++){
			int tmp;
			scanf("%1d",&tmp);
			gear[i].push_back(tmp);
		}
	}
	
	int K;
	cin >> K;
	
	for(int i = 0; i < K; i++){
		int no_gear, dir;//1 시계, -1 반시계
		cin >> no_gear >> dir;
		
		int visit[4] = {0,};
		queue<Move> q;
		Move m;
		m.no = no_gear-1;
		m.dir = dir;
		q.push(m);
		
		while(!q.empty()){
			m = q.front();
			q.pop();
			visit[m.no] = 1;
			
			if(m.no == 0){
				if(gear[m.no][2] != gear[m.no+1][6] && visit[m.no+1] == 0){
					Move mov;
					mov.no = m.no+1;
					if(m.dir == 1){
						mov.dir = -1;
					}
					else{
						mov.dir = 1;
					}
					q.push(mov);
				}
			}
			else if(m.no == 1 || m.no == 2){
				if(gear[m.no][2] != gear[m.no+1][6] && visit[m.no+1] == 0){
					Move mov;
					mov.no = m.no+1;
					if(m.dir == 1){
						mov.dir = -1;
					}
					else{
						mov.dir = 1;
					}
					q.push(mov);
				}
				if(gear[m.no][6] != gear[m.no-1][2] && visit[m.no-1] == 0){
					Move mov;
					mov.no = m.no-1;
					if(m.dir == 1){
						mov.dir = -1;
					}
					else{
						mov.dir = 1;
					}
					q.push(mov);
				}
				
			}
			else{
				if(gear[m.no][6] != gear[m.no-1][2] && visit[m.no-1] == 0){
					Move mov;
					mov.no = m.no-1;
					if(m.dir == 1){
						mov.dir = -1;
					}
					else{
						mov.dir = 1;
					}
					q.push(mov);
				}
			}
			
			if(m.dir == 1){//시계
				int back = gear[m.no].back();
				gear[m.no].pop_back();
				gear[m.no].push_front(back);
			}
			else{//반시계
				int front = gear[m.no].front();
				gear[m.no].pop_front();
				gear[m.no].push_back(front);
			}
		}
	}
	
	int score = 0;
	if(gear[0][0] == 1){
		score += 1;
	}
	if(gear[1][0] == 1){
		score += 2;
	}
	if(gear[2][0] == 1){
		score += 4;
	}
	if(gear[3][0] == 1){
		score += 8;
	}
	
	cout << score;
	
	return 0;
}
