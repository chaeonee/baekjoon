#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct Pos{
	int x, y;
};

int Choice(int M, int s, int depth, int min_dist, vector<Pos> house, vector<Pos> chicken, vector<Pos> pick);
int getChickenDist(vector<Pos> house, vector<Pos> pick);
int getDist(int x1, int y1, int x2, int y2);

int main() {
	int N, M;
	cin >> N >> M;
	
	int **map = new int*[N];
	for(int i = 0; i < N; i++){
		map[i] = new int[N];
	}
	
	vector<Pos> house;
	vector<Pos> chicken;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> map[i][j];
			
			if(map[i][j] == 1){ // 집 좌표
				house.push_back({i,j});
			}
			else if(map[i][j] == 2){ // 치킨집 좌표
				chicken.push_back({i,j});
			}
		}
	}
	
	if(chicken.size() <= M){ // 존재하는 치킨집의 수가 선택해야하는 치킨집의 수보다 작거나 같은 경우(문제의 조건으로는 같을 경우만 존재)
		cout << getChickenDist(house,chicken); // 치킨 거리 바로 구해서 출력
		return 0;
	}
	
	vector<Pos> pick;
	cout << Choice(M,0,0,100000,house,chicken,pick); // 존재하는 치킨집의 수가 선택해야 하는 치킨집의 수보다 클 경우 치킨집을 먼저 선택한 후, 치킨 거리 구해야 함
	
	return 0;
}

int Choice(int M, int s, int depth, int min_dist, vector<Pos> house, vector<Pos> chicken, vector<Pos> pick){ // 치킨 집 선택을 위한 함수
	if(depth == M){ // 치킨 집을 M개 모두 선택했으면
		min_dist = min(min_dist,getChickenDist(house,pick)); // 치킨 거리 구하기(구한 치킨 거리가 최소 치킨 거리라면 return, 아니면 원래의 최소 치킨 거리 return)
		return min_dist;
	}
	
	int c_len = chicken.size();
	for(int i = s; i < c_len; i++){ // 치킨 집 한 개씩 선택
		pick.push_back(chicken[i]);
		min_dist = Choice(M,i+1,depth+1,min_dist,house,chicken,pick); // 해당 치킨집보다 뒷쪽에 저장된 치킨집만 선택할 수 있도록 하면 visit 확인할 필요 없음(순서가 상관 없기 때문)
		pick.pop_back();
	}
	
	return min_dist;
}

int getChickenDist(vector<Pos> house, vector<Pos> pick){ // 치킨 거리 구하기
	int chicken_dist = 0;
	
	int h_len = house.size(), p_len = pick.size();
	for(int i = 0; i < h_len; i++){ // 집과
		int hx = house[i].x, hy = house[i].y, tmp = 100000;
		for(int j = 0; j < p_len; j++){ // 가장 가까운 치킨집과의 거리 구하기
			tmp = min(tmp,getDist(hx,hy,pick[j].x,pick[j].y));
		}
		chicken_dist += tmp; // 집-치킨집의 최소거리의 합
	}
	
	return chicken_dist;
}

int getDist(int x1, int y1, int x2, int y2){ // 좌표간의 L1 거리 구하기
	return abs(x1 - x2) + abs(y1 - y2);
}
