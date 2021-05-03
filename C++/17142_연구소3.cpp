#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

struct Pos{
	int r, c;
};

int choice(int N, int M, int total, int num, int **lab, vector<Pos> &virus, int start, vector<Pos> &q);
int spread(int N, int total, int **lab, vector<Pos> v);

int main() {
	int N, M;
	cin >> N >> M;
	
	int **lab = new int*[N];
	for(int i = 0; i < N; i++){
		lab[i] = new int[N];
	}
	
	vector<Pos> v;
	int total = N*N;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> lab[i][j];
			if(lab[i][j] == 2){
				Pos p;
				p.r = i;
				p.c = j;
				v.push_back(p);
			}
			else if(lab[i][j] == 1){
				total--;
			}
		}
	}
	
	total -= v.size()-M;
	vector<Pos> q;
	int num = choice(N, M, total, -1, lab, v, 0, q);
	
	cout << num;
	
	return 0;
}

int choice(int N, int M, int total, int num, int **lab, vector<Pos> &virus, int start, vector<Pos> &q){
	if(q.size() == M){
		int tmp = spread(N, total, lab, q);
		if(num == -1){
			num = tmp;
		}
		else{
			if(tmp != -1 && num > tmp){
				num = tmp;
			}
		}
		return num;
	}
	
	int s = virus.size();
	for(int i = start; i < s; i++){
		q.push_back(virus[i]);
		num = choice(N, M, total, num, lab, virus, i+1, q);
		q.pop_back();
	}
	
	return num;
}

int spread(int N, int total, int **lab, vector<Pos> v){
	bool **visit = new bool*[N];
	for(int i = 0; i < N; i++){
		visit[i] = new bool[N];
		memset(visit[i],false,sizeof(bool)*N);
	}
	
	int s = v.size();
	queue<Pos> q;
	for(int i = 0; i < s; i++){
		Pos p = v[i];
		v.pop_back();
		visit[p.r][p.c] = true;
		q.push(p);
		total--;
	}
	
	int num = 0;
	int set = 0;
	while(!q.empty() && total > 0){
		if(set == 0){
			set = q.size();
			num++;
		}
		Pos p = q.front();
		q.pop();//cout << p.r << " " << p.c << endl;
		set--;
		
		if(p.r+1 < N){
			if(visit[p.r+1][p.c] == false && lab[p.r+1][p.c] != 1){
				visit[p.r+1][p.c] = true;
				Pos tmp;
				tmp.r = p.r+1;
				tmp.c = p.c;
				
				q.push(tmp);
				
				if(lab[p.r+1][p.c] == 0){
					total--;
				}
			}
		}
		
		if(p.c+1 < N){
			if(visit[p.r][p.c+1] == false && lab[p.r][p.c+1] != 1){
				visit[p.r][p.c+1] = true;
				Pos tmp;
				tmp.r = p.r;
				tmp.c = p.c+1;
				
				q.push(tmp);
				
				if(lab[p.r][p.c+1] == 0){
					total--;
				}
			}
		}
		
		if(p.r-1 >= 0){
			if(visit[p.r-1][p.c] == false && lab[p.r-1][p.c] != 1){
				visit[p.r-1][p.c] = true;
				Pos tmp;
				tmp.r = p.r-1;
				tmp.c = p.c;
				
				q.push(tmp);
				
				if(lab[p.r-1][p.c] == 0){
					total--;
				}
			}
		}
		
		if(p.c-1 >= 0){
			if(visit[p.r][p.c-1] == false && lab[p.r][p.c-1] != 1){
				visit[p.r][p.c-1] = true;
				Pos tmp;
				tmp.r = p.r;
				tmp.c = p.c-1;
				
				q.push(tmp);
				
				if(lab[p.r][p.c-1] == 0){
					total--;
				}
			}
		}
	}
	
	if(total != 0){
		return -1;
	}
	
	return num;
}
