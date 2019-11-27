#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int getDegree(int n, int p1, int p2, bool **matrix, bool *visit, int d, int r);

int main() {
	int n;
	cin >> n;
	
	int p1, p2;
	cin >> p1 >> p2;
	
	bool **matrix = new bool*[n];
	for(int i = 0; i < n; i++){
		matrix[i] = new bool[n];
		memset(matrix[i],false,sizeof(bool)*n);
	}
	
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		int x, y;
		cin >> x >> y;
		
		matrix[x-1][y-1] = true;
		matrix[y-1][x-1] = true;
	}
	
	bool *visit = new bool[n];
	cout << getDegree(n, p1-1, p2-1, matrix, visit, 0, -1);
	
	return 0;
}

int getDegree(int n, int p1, int p2, bool **matrix, bool *visit, int d, int r){
	visit[p1] = true;
	
	vector<int> v;
	for(int i = 0; i < n; i++){
		if(matrix[p1][i] == true && visit[i] == false){ //현재 사람과 부모 자식 관계이고 방문한 적 없는 노드 중
			if(p2 == i){ // 목적지에 도달할 수 있는 경우 존재한다면
				r = d+1; //트리 깊이+1을 return
				return r;
			}
			else{
				v.push_back(i);
			}
		}
	}
	while(!v.empty()){ //아니라면 다음 경우 살펴보기
		int tmp;
		tmp = v.back();
		v.pop_back();
		r = getDegree(n, tmp, p2, matrix, visit, d+1, r);
	}
	return r;
}