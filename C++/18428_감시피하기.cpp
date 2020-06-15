#include <iostream>
#include <vector>
using namespace std;

void chooseWall(int N, char **school, int n, vector<pair<int, int> > teacher, bool &flag);
bool doAvoid(int N, char **school, vector<pair<int, int> > teacher);

int main() {
	int N;
	cin >> N;
	
	vector<pair<int, int> > teacher; // 선생님의 위치 담기 위한 벡터
	char **school = new char*[N];
	for(int i = 0; i < N; i++){
		school[i] = new char[N];
		for(int j = 0; j < N; j++){
			cin >> school[i][j];
			if(school[i][j] == 'T'){ // 선생님
				teacher.push_back(make_pair(i,j));
			}
		}
	}
	
	bool flag = false; // 감시를 피할 수 있는지 여부
	chooseWall(N,school,0,teacher,flag);
	if(flag){ // 피할 수 있다면
		cout << "YES"; // YES 출력
	}
	else{ // 피할 수 없다면
		cout << "NO"; // NO 출력
	}
	
	return 0;
}

void chooseWall(int N, char **school, int n, vector<pair<int, int> > teacher, bool &flag){ // 3개의 장애물을 선택하기 위한 함수
	if(n == 3){ // 장애물 3개 모두 선택했다면 감시를 피할 수 있는지
		if(doAvoid(N,school,teacher)){ // 감시를 피할 수 있다면
			flag = true; // flag를 true로 갱신
		}
		return; // 함수 종료
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			if(school[i][j] == 'X'){ // 아무것도 없는 경우에만 장애물을 설치할 수 있음
				school[i][j] = 'O'; // 장애물 설치
				chooseWall(N,school,n+1,teacher,flag); // 장애물의 수 1 증가 시킨 후 재귀
				school[i][j] = 'X'; // 백트래킹(원래대로 돌려 놓음)
				
				// 감시를 피할 수 있는 경우가 한 개라도 존재하면 더 이상 확인할 필요 없음
				if(flag){ // 따라서 flag가 true가 되는 순간 함수를 종료
					return;
				}
			}
		}
	}
}

bool doAvoid(int N, char **school, vector<pair<int, int> > teacher){ // 감시를 피할 수 있는지 확인하기 위한 함수
	int n_teacher = teacher.size();
	for(int i = 0; i < n_teacher; i++){
		int x = teacher[i].first, y = teacher[i].second;
		int j = 1; // 현재 선생님 좌표를 기준으로 상하좌우로 감시(상하좌우 j칸)
		bool flag1 = false, flag2 = false, flag3 = false, flag4 = false; // 벽을 만났는지 여부 체크
		while((x-j >= 0 || x+j < N || y-j >= 0 || y+j < N)){ // 상하좌우 중 어떤 경우라도 범위 내에 존재한다면 반복문 수행(상하좌우 범위 내에 존재하는 경우 모두 체크하기 위함)
			if (flag1 == true && flag2 == true && flag3 == true && flag4 == true){ // 상하좌우 모두 벽을 만났다면 볼 필요 없음
				break;
			}
			
			if(!flag1 && x-j >= 0){ // 상
				if(school[x-j][y] == 'S'){ // 학생 발견
					return false; // 감시 피할 수 없음(더 볼 필요도 없음 -> 종료)
				}
				else if(school[x-j][y] == 'O'){ // 벽 발견
					flag1 = true; // 이 이상으로는 볼 필요 없기 때문에 flag로 체크
				}
			}
			
			if(!flag2 && x+j < N){ // 하
				if(school[x+j][y] == 'S'){ // 학생 발견
					return false; // 감시 피할 수 없음(더 볼 필요도 없음 -> 종료)
				}
				else if(school[x+j][y] == 'O'){ // 벽 발견
					flag2 = true; // 이 이상으로는 볼 필요 없기 때문에 flag로 체크
				}
			}
			
			if(!flag3 && y-j >= 0){ // 좌
				if(school[x][y-j] == 'S'){ // 학생 발견
					return false; // 감시 피할 수 없음(더 볼 필요도 없음 -> 종료)
				}
				else if(school[x][y-j] == 'O'){ // 벽 발견
					flag3 = true; // 이 이상으로는 볼 필요 없기 때문에 flag로 체크
				}
			}
			
			if(!flag4 && y+j < N){ // 우
				if(school[x][y+j] == 'S'){ // 학생 발견
					return false; // 감시 피할 수 없음(더 볼 필요도 없음 -> 종료)
				}
				else if(school[x][y+j] == 'O'){ // 벽 발견
					flag4 = true; // 이 이상으로는 볼 필요 없기 때문에 flag로 체크
				}
			}
			j++;
		}
	}
	
	return true; // 중간에 return되지 않았다면 학생 발견하지 못했다는 뜻이기 때문에 true return
}
