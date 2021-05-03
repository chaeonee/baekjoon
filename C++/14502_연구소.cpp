#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

struct Pos{
	int r, c;
};

int Selectwall(int M, int N, int **lab, vector<Pos> &virus, int s, int r, int c, int max, int safe_area);
int Danger(int M, int N, int **lab, vector<Pos> &virus, int safe_area);

int main() {
	int N, M;
	cin >> N >> M; //N이 행
	
	int **lab = new int*[N];
	for(int i = 0; i < N; i++){
		lab[i] = new int[M];
	}
	
	int safe_area = N*M;
	vector<Pos> virus;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> lab[i][j];
			
			if(lab[i][j] == 1){
				safe_area--;
			}
			else if(lab[i][j] == 2){
				Pos p;
				p.r = i;
				p.c = j;
				virus.push_back(p);
			}
			
		}
	}

	cout << Selectwall(M, N, lab, virus, 0, 0, 0, 0,safe_area);
	//cout << Danger(M, N, lab, virus, safe_area);
 
	return 0;
}

int Selectwall(int M, int N, int **lab, vector<Pos> &virus, int s, int r, int c, int max, int safe_area){
	if(s == 3){
		int tmp = Danger(M, N, lab, virus, safe_area);
		if(max < tmp){
			max = tmp;
		}
		
		return max;
	}
	
	for(int i = r; i < N; i++){
		for(int j = 0; j < M; j++){
			if(i == r){
				if(j >= c){
					if(lab[i][j] == 0){
						int tmp = lab[i][j];
						lab[i][j] = 1;
						safe_area--;
						max = Selectwall(M, N, lab, virus, s+1, i, j, max,safe_area);
						lab[i][j] = 0;
						safe_area++;
					}
				}
			}
			else{
				if(lab[i][j] == 0){
					int tmp = lab[i][j];
					lab[i][j] = 1;
					safe_area--;
					max = Selectwall(M, N, lab, virus, s+1, i, j, max,safe_area);
					lab[i][j] = 0;
					safe_area++;
				}
			}
		}
	}
	
	return max;
}


int Danger(int M, int N, int **lab, vector<Pos> &virus, int safe_area){
	int **visit = new int*[N];
	for(int i = 0; i < N; i++){
		visit[i] = new int[M];
		memset(visit[i],0,sizeof(int)*M);
	}
	
	int safe = safe_area;
	queue<Pos> q;
	for(int i = 0; i < virus.size(); i++){
		q.push(virus[i]);
	}
	
	while(!q.empty()){
		Pos v = q.front();
		q.pop();
		
		if(visit[v.r][v.c] == 0){
			visit[v.r][v.c] = 1;
			safe--;
		
			if(v.r+1 < N){
				if(visit[v.r+1][v.c] == 0 && lab[v.r+1][v.c] == 0){
					Pos p;
					p.r = v.r+1;
					p.c = v.c;
					q.push(p);
				}
			}
			if(v.r-1 >= 0){
				if(visit[v.r-1][v.c] == 0 && lab[v.r-1][v.c] == 0){
					Pos p;
					p.r = v.r-1;
					p.c = v.c;
					q.push(p);
				}
			}
			if(v.c+1 < M){
				if(visit[v.r][v.c+1] == 0 && lab[v.r][v.c+1] == 0){
					Pos p;
					p.r = v.r;
					p.c = v.c+1;
					q.push(p);
				}
			}
			if(v.c-1 >=0){
				if(visit[v.r][v.c-1] == 0 && lab[v.r][v.c-1] == 0){
					Pos p;
					p.r = v.r;
					p.c = v.c-1;
					q.push(p);
				}
			}
		}
	}
	//cout << safe <<endl;
	return safe;
}
