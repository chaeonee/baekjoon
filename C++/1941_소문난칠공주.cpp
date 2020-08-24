#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void select7Princess(int &num, int d, int s, int n_dasom, bool **selection, char **student);
bool isConnected(bool **selection);

int main() {
	int n_dasom = 0; // 이다솜파의 수
	
	bool **selection = new bool*[5]; // 해당 위치의 학생이 선택됐는지의 여부
	char **student = new char*[5]; // 해당 위치의 학생 정보
	for(int i = 0; i < 5; i++){
		selection[i] = new bool[5];
		student[i] = new char[5];
		for(int j = 0; j < 5; j++){
			selection[i][j] = false;
			cin >> student[i][j];
			if(student[i][j] == 'S'){ // 해당 학생이 이다솜파라면
				n_dasom++; // 이다솜파의 수 1 증가
			}
		}
	}
	
	if(n_dasom < 4){ // 전체 이다솜파가 4명 미만이라면
		cout << 0; // '소문난 칠공주' 결성 조건에 아예 부합시킬 수 없기 때문에
		return 0; // 탐색하지 않고 종료
	}
	
	int num = 0; // '소문난 칠공주'를 결성할 수 있는 모든 경우의 수
	select7Princess(num,0,0,0,selection,student);
	
	cout << num;
	
	return 0;
}

void select7Princess(int &num, int d, int s, int n_dasom, bool **selection, char **student){ // '소문난 칠공주'를 결성하기 위해 7명의 학생을 선택하는 함수
	if(d == 7){ // 7명을 모두 선택했고
		if(n_dasom >= 4){ // 선택한 학생 무리에 이다솜파가 4명 이상이고
			if(isConnected(selection)){ // '소문난 칠공주'를 결성할 수 있다면
				num++; // '소문난 칠공주'를 결성할 수 있는 경우의 수 1 증가
			}
		}
		return;
	}
	
	for(int i = s; i < 25; i++){ // 25명의 학생 중 한 명 선택하기 위함
		int x = i/5, y = i%5;
		selection[x][y] = true; // 해당 위치의 학생 선택했음을 표시
		if(student[x][y] == 'S'){ // 해당 위치의 학생이 이다솜파라면, 이다솜파의 수 1 증가
			select7Princess(num,d+1,i+1,n_dasom+1,selection,student);
		}
		else{ // 해당 위치의 학생이 임도연파라면, 이다솜파의 수 그대로
			select7Princess(num,d+1,i+1,n_dasom,selection,student);
		}
		selection[x][y] = false; // 해당 위치 학생 선택 취소(백트래킹)
	}
}

bool isConnected(bool **selection){ // 선택된 학생이 연결되어있는지 확인(BFS 변형)
	bool **visit = new bool*[5]; // 방문 체크를 위한 배열
	for(int i = 0; i < 5; i++){
		visit[i] = new bool[5];
		for(int j = 0; j < 5; j++){
			visit[i][j] = false;
		}
	} // 초기화
	
	queue<int> q;
	for(int i = 0; i < 5; i++){
		bool flag = false;
		for(int j = 0; j < 5; j++){
			if(selection[i][j]){
				visit[i][j] = true;
				q.push(5*i+j);
				flag = true;
				break;
			}
		}
		if(flag){
			break;
		}
	} // 선택된 학생 중 한 명을 queue에 넣어서 그래프 탐색을 위한 초기화 진행
	
	int n = 0; // 연결된 학생들의 수(처음 선택된 학생 기준)
	int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}}; // 상하좌우
	while(!q.empty() && n < 7){
		int x = q.front()/5, y = q.front()%5;
		q.pop();
		n++; // 연결된 학생의 수 1 증가
		
		for(int d = 0; d < 4; d++){
			int dx = x+dir[d][0], dy = y+dir[d][1]; // 좌표 계산
			if(dx >= 0 && dx < 5 && dy >= 0 && dy < 5){ // 범위 체크
				if(selection[dx][dy] && !visit[dx][dy]){ // 선택된 학생이고 방문한적 없다면
					q.push(5*dx+dy); // queue에 현재 학생 push
					visit[dx][dy] = true; // 방문 체크
				}
			}
		}
	}
	
	if(n != 7){ // 연결된 학생이 7명이 안된다면 '소문난 칠공주' 결성 불가
		return false;
	}
	
	// 선택된 7명의 학생이 모두 연결되어 있다면, '소문난 칠공주' 결성 가능
	return true;
}
