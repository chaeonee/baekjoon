#include <iostream>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

struct Pos{
	int r, c;
};

int movement(int N, int L, int R, queue<Pos> &q, int **A, bool **visit);
void update(int **A, queue<Pos> &q, int avg);

int main() {
	int N, L, R;
	cin >> N >> L >> R;
	
	int **A = new int*[N];
	bool **visit = new bool*[N];
	for(int i = 0; i < N; i++){
		A[i] = new int[N];
		visit[i] = new bool[N];
		memset(visit[i],false,sizeof(bool)*N);
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> A[i][j];
		}
	}
	
	int num = 0;
	while(1){
		int max_group = 1;
		queue<Pos> q;
		for(int i = 0; i < N; i++){
			for(int j = 0; j < N; j++){
				if(visit[i][j] == false){
					Pos p;
					p.r = i;
					p.c = j;
					q.push(p);
					
					int tmp;
					visit[p.r][p.c] = true;
					tmp = movement(N, L, R, q, A, visit);
					if(max_group < tmp){
						max_group = tmp;
					}
				}
			}
		}
		
		if(max_group == 1){
			break;
		}
		
		num++;
		for(int i = 0; i < N; i++){
			memset(visit[i],false,sizeof(bool)*N);
		}
	}
	
	cout << num;
	
	return 0;
}

int movement(int N, int L, int R, queue<Pos> &q, int **A, bool **visit){
	int num = 0;
	int total = 0;
	queue<Pos> result;
	while(!q.empty()){
		Pos p = q.front();
		q.pop();
		result.push(p);
		num++;
		total += A[p.r][p.c];
		
		if(p.r-1 >= 0){
			int sub = abs(A[p.r-1][p.c]-A[p.r][p.c]);
			if(sub >= L && sub <= R && visit[p.r-1][p.c] == false){
				visit[p.r-1][p.c] = true;
				
				Pos tmp;
				tmp.r = p.r-1;
				tmp.c = p.c;
				q.push(tmp);
			}
		}
		
		if(p.c-1 >= 0){
			int sub = abs(A[p.r][p.c-1]-A[p.r][p.c]);
			if(sub >= L && sub <= R && visit[p.r][p.c-1] == false){
				visit[p.r][p.c-1] = true;
				
				Pos tmp;
				tmp.r = p.r;
				tmp.c = p.c-1;
				q.push(tmp);
			}
		}
		
		if(p.r+1 < N){
			int sub = abs(A[p.r+1][p.c]-A[p.r][p.c]);
			if(sub >= L && sub <= R && visit[p.r+1][p.c] == false){
				visit[p.r+1][p.c] = true;
				
				Pos tmp;
				tmp.r = p.r+1;
				tmp.c = p.c;
				q.push(tmp);
			}
		}
		
		if(p.c+1 < N){
			int sub = abs(A[p.r][p.c+1]-A[p.r][p.c]);
			if(sub >= L && sub <= R && visit[p.r][p.c+1] == false){
				visit[p.r][p.c+1] = true;
				
				Pos tmp;
				tmp.r = p.r;
				tmp.c = p.c+1;
				q.push(tmp);
			}
		}
	}
	
	total /= num;
	update(A, result, total);
	
	return num;
}

void update(int **A, queue<Pos> &q, int avg){
	while(!q.empty()){
		Pos p = q.front();
		q.pop();
		
		A[p.r][p.c] = avg;
	}
}
