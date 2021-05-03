#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct T{
	int r, c, num;
};

struct cmp{
	bool operator()(T &a, T &b){
		return a.num <= b.num;
	}
};

int main() {
	int N, M;
	cin >> N >> M;
	
	int **paper = new int*[N];
	bool **visit = new bool*[N];
	for(int i = 0; i < N; i++){
		paper[i] = new int[M];
		visit[i] = new bool[M];
		memset(visit[i],false,sizeof(bool)*M);
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			cin >> paper[i][j];
		}
	}
	
	int max = -1;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < M; j++){
			queue<T> q;//초기화 위해
			priority_queue<T, vector<T>, cmp> pq;
			T t;
			t.r = i;
			t.c = j;
			t.num = paper[i][j];
			pq.push(t);
			q.push(t);
			visit[i][j] = true;
			
			int tmp_num = 0;
			for(int k = 0; k < 4; k++){
				T tt = pq.top();
				pq.pop();
				tmp_num += tt.num;
				//cout << tt.num<<endl;
				if(k == 3){
					break;
				}
				
				if(tt.r-1 >= 0){
					if(visit[tt.r-1][tt.c] == false){
						visit[tt.r-1][tt.c] = true;
						
						t.r = tt.r-1;
						t.c = tt.c;
						t.num = paper[tt.r-1][tt.c];
						pq.push(t);
						q.push(t);
					}
				}
				if(tt.c-1 >= 0){
					if(visit[tt.r][tt.c-1] == false){
						visit[tt.r][tt.c-1] = true;
						
						t.r = tt.r;
						t.c = tt.c-1;
						t.num = paper[tt.r][tt.c-1];
						pq.push(t);
						q.push(t);
					}
				}
				if(tt.r+1 < N){
					if(visit[tt.r+1][tt.c] == false){
						visit[tt.r+1][tt.c] = true;
						
						t.r = tt.r+1;
						t.c = tt.c;
						t.num = paper[tt.r+1][tt.c];
                        pq.push(t);
                        q.push(t);
					}
				}
				if(tt.c+1 < M){
					if(visit[tt.r][tt.c+1] == false){
						visit[tt.r][tt.c+1] = true;
						
						t.r = tt.r;
						t.c = tt.c+1;
						t.num = paper[tt.r][tt.c+1];
						pq.push(t);
						q.push(t);
					}
				}
			}
			//cout << "@@" << tmp_num << endl;
			if(max < tmp_num){
				max = tmp_num;
			}
			
			while(!q.empty()){
				t = q.front();
				q.pop();
				visit[t.r][t.c] = false;
			}
		}
	}
	
	cout << max;
	
	return 0;
}
