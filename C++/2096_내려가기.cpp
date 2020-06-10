#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Score{
	int s_min, s_max;
};

int main() {
	int N;
	cin >> N;
	
	vector<Score> score(3);
	vector<Score> pre_score(3);
	for(int i = 0; i < 3; i++){
		int tmp;
		cin >> tmp;
		score[i] = {tmp,tmp};
		pre_score[i] = {tmp,tmp};
	} // 점수의 {최소, 최대}, pre_score는 이전 행까지의 {최소, 최대}를 의미 score는 현재 행까지의{최소, 최대}를 의미 / 초기화
	
	
	for(int i = 1; i < N; i++){
		for(int j = 0; j < 3; j++){
			int tmp;
			cin >> tmp;
			if(j-1 >= 0){
				if(j+1 < 3){ // 2번째 열의 경우: pre_score 1,2,3열 중 가장 큰 값, 작은 값 찾아서 최대, 최소에 넣어주되 현재의 값을 더해서 넣어야 함
					int s_tmp = min(pre_score[j-1].s_min, pre_score[j].s_min);
					s_tmp = min(s_tmp,pre_score[j+1].s_min);
					score[j].s_min = s_tmp + tmp;
					
					s_tmp = max(pre_score[j-1].s_max, pre_score[j].s_max);
					s_tmp = max(s_tmp, pre_score[j+1].s_max);
					score[j].s_max = s_tmp + tmp;
				}
				else{ // 3번째 열의 경우: pre_score의 2,3열 중 가장 큰 값, 작은 값 찾아서 최대, 최소에 넣어주되 현재의 값을 더해서 넣어야 함
					score[j].s_min = min(pre_score[j-1].s_min, pre_score[j].s_min) + tmp;
					score[j].s_max = max(pre_score[j-1].s_max, pre_score[j].s_max) + tmp;
				}
			}
			else{
				if(j+1 < 3){ // 1번째 열의 경우: pre_score의 1,2열 중 가장 큰 값, 작은 값 찾아서 최대, 최소에 넣어주되 현재의 값을 더해서 넣어야 함
					score[j].s_min = min(pre_score[j].s_min, pre_score[j+1].s_min) + tmp;
					score[j].s_max = max(pre_score[j].s_max, pre_score[j+1].s_max) + tmp;
				}
			}
		}
		for(int i = 0; i < 3; i++){
			pre_score[i] = score[i]; // pre_score 값 갱신(다음 계산을 위해)
		}
	}
	
	int s_min = 1000000, s_max = 0;
	for(int i = 0; i < 3; i++){ // 진짜 최대 최소 구하기 위해서는 계산 값의 최소 중 가장 최소, 최대 중 가장 최대인 값을 구해야 함
		if(s_min > score[i].s_min){
			s_min = score[i].s_min;
		}
		if(s_max < score[i].s_max){
			s_max = score[i].s_max;
		}
	}
	
	cout << s_max << " " << s_min;
	
	return 0;
}
