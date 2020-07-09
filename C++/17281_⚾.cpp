#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

void getOrder(int N, int idx, int **hitting, int &score, int *order, bool *visit);
void getScore(int N, int &score, int *order, int **hitting);

int main(){
	int N;
	cin >> N;
	
	int **hitting = new int*[N];
	for(int i = 0; i < N; i++){
		hitting[i] = new int[9];
		for(int j = 0; j < 9; j++){
			cin >> hitting[i][j];
		}
	}
	
	int score = 0;
	int *order = new int[9];
	bool *visit = new bool[9];
	for(int i = 0; i < 9; i++){
		order[i] = -1;
		visit[i] = false;
	}
	order[3] = 0; // 4번 타자를 0번 선수로 고정
	visit[0] = true; // 0번 선수 방문 표시
	getOrder(N,0,hitting,score,order,visit);

	cout << score;

	return 0;
}

void getOrder(int N, int idx, int **hitting, int &score, int *order, bool *visit){ // 순서를 구하기 위한 함수
	if(idx == 9){ // 9명의 순서를 모두 정했으면
		getScore(N,score,order,hitting); // 점수 구하기
		return;
	}

	for(int i = 1; i < 9; i++){
		if(idx == 3){ // 4번 타자의 경우 이미 정해져 있기 때문에
			getOrder(N,idx+1,hitting,score,order,visit); // 그냥 다음 타자 순서를 구하는 함수로 이동
			break;
		}
		
		if(visit[i]){ // 이미 순서가 정해진 타자라면
			continue; // 그냥 넘기기
		}
		
		// 순서가 정해지지 않은 타자라면
		order[idx] = i; // 현재 순서에 현재 타자 번호 넣기
		visit[i] = true; // 방문 표시
		getOrder(N,idx+1,hitting,score,order,visit); // 다음 타자 순서 구하기
		visit[i] = false; // 방문 표시 취소(백트래킹)
	}
}

void getScore(int N, int &score, int *order, int **hitting){ // 점수를 구하기 위한 함수
	int start = 0, tmp_score = 0; // 이닝이 끝나도 타자 순서는 그대로 진행되며 이전 이닝과 연결된 순서로 진행되어야 하므로 밖으로 뺌 / 현재 순서로 진행했을 때의 점수를 담을 것(나중에 최고 점수와 비교하여 더 크면 갱신할 것)
	for(int i = 0; i < N; i++){
		bool base[3] = {false, }; // 1루, 2루, 3루에 타자가 있는지 여부
		int out = 0; // out의 수
		while(out < 3){ // 3 out이 되기 전까지는 이닝 진행해야 함
			if(hitting[i][order[start]] == 0){ // out인 경우
				out++; // out의 수 증가
			}
			else{ // out이 아닌 경우
				int hit = hitting[i][order[start]]; // 1이면 1루타(안타), 2이면 2루타, 3이면 3루타, 4이면 홈런이므로 이 숫자 이용하여 계산 진행
				for(int j = 2; j >= 0; j--){ // 3루부터 거꾸로 확인해서 진루시키기
					if(base[j] == true){ // 사람이 있다면
						base[j] = false; // 사람 없애기(이동시켜야 하기 때문)
						if(j+hit > 2){ // 3루 이상으로 나가면
							tmp_score++; // 1점 획득
						}
						else{ // 아직 득점 못했을 때
							base[j+hit] = true; // 진루 시킨 위치 표시
						}
					}
				}
				
				if(hit > 3){ // 홈런일 때는 현재 타자도 점수를 획득
					tmp_score++;
				}
				else{ // 아니라면 현재 타자는 점수는 획득 못하고 진루만
					base[hit-1] = true;
				}
			}
			
			start = (start+1)%9; // 다음 타자로 변경(1~9번 타자가 돌아가면서 진행해야 하기 때문에 9로 나눈 나머지로! -> 그래야 회전할 것)
		}
	}
	score = max(score,tmp_score); // 현재까지 최고점과 현재 점수를 비교하여 더 큰 값으로 갱신
}
