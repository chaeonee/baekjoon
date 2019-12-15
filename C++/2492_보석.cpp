#include <iostream>
#include <vector>
using namespace std;

struct Pos{
	int x, y;
};

int main() {
	int N, M, T, K;
	cin >> N >> M >> T >> K;

	vector<Pos> v;
	for(int t = 0; t < T; t++){
		int x, y;
		cin >> x >> y;
		v.push_back({M-y,x});
	} // 좌표 입력, 주어진 그림과 c++의 배열은 위아래 방향이 다르다. 따라서 행은 M-y로 표현하고 나중에 새로 계산해서 출력해주어야 함

	int max = 0; // 정사각형 안의 존재하는 좌표의 최대 개수
	int result[2] = {0,0}; // 정답 좌표를 저장할 것임
	for(int i = 0; i < T; i++){
		for(int j = 0; j < T; j++){ // 입력된 좌표의 조합을 이용해야 함(x,y 좌표의 조합..)
			int tmp_x = v[i].x; //행
			int tmp_y = v[j].y; //열

			if(tmp_x+K > M){ // 범위를 넘어가는 경우 보정해주는 작업
				tmp_x = M-K;
			}
			if(tmp_y+K > N){ // 범위를 넘어가는 경우 보정해주는 작업
				tmp_y = N-K;
			}

			int num = 0;
			for(int t = 0; t < T; t++){ // 해당 정사각형 안에 몇개의 좌표가 있는지 세기
				if(v[t].x >= tmp_x && v[t].x <= tmp_x+K && v[t].y >= tmp_y && v[t].y <= tmp_y+K){
					num++;
				}
			}

			if(max < num){ // 현재 좌표의 수가 최대 좌표 수보다 많으면 갱신 필요
				max = num;
				result[0] = tmp_y;
				result[1] = tmp_x;
			}
		}
	}

	cout << result[0] << ' ' << (result[1]-M)*-1 << '\n' << max; // result[1]은 아까 보정한 행의 값 -> 따라서 다시 원상태로 복구 하는 과정 필요

	return 0;
}
