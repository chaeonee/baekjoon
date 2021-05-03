#include <iostream>
#include <queue>
using namespace std;

struct Pos{
	int a, b, sec;
};

int main() {
	int N, K;
	cin >> N >> K;
	
	queue<Pos> q;
	q.push({N, K, 0});
	
	bool visit[2][500001];
	for(int i = 0; i < 2; i++){
		for(int j = 0; j <= 500000; j++){
			visit[i][j] = false;
		}
	}
	
	visit[0][N] = true;
	while(!q.empty()){
		int a = q.front().a, b = q.front().b, sec = q.front().sec;
		q.pop();
		
		if(b > 500000){
			continue;
		}
		
		if(visit[sec%2][b]){
			cout << sec;
			return 0;
		}
		
		sec++;
		b += sec;
		if(a-1 >= 0){
			if(!visit[sec%2][a-1]){
				visit[sec%2][a-1] = true;
				q.push({a-1,b,sec});
			}
		}
		
		if(a+1 <= 500000){
			if(!visit[sec%2][a+1]){
				visit[sec%2][a+1] = true;
				q.push({a+1,b,sec});
			}
		}
		
		if(2*a <= 500000){
			if(!visit[sec%2][2*a]){
				visit[sec%2][2*a] = true;
				q.push({2*a,b,sec});
			}
		}
	}
	
	cout << -1;
	
	return 0;
}
