#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int F, S, G, U, D;
	cin >> F >> S >> G >> U >> D;
	
	bool *floor = new bool[F]; // 층에 방문했는지 여부(0부터 시작)
	memset(floor,false,sizeof(bool)*F);
	floor[S-1] = true; // 현재 층은 방문 표시
	
	int cnt = 0; // 버튼을 몇 번 눌렀는지 세기 위한 변수
	int cur = S-1; // 현재 층
	while(true){
		if(cur == G-1){ // 만약 목적지에 도착했다면 while문 탈출
			break;
		}
		
		if(cur < G-1){ // 만약 목적지가 더 위쪽이라면
			if(cur+U < F && floor[cur+U] == false){ // 위쪽으로 이동 가능한지 먼저 확인 / 범위 내에 있어야 하며, 이동할 층에 방문한 적이 없어야 함
				cur = cur+U; // 현재 위치 이동 층으로 변경
				floor[cur] = true; // 방문 체크
				cnt++; // 버튼 누른 횟수 1 증가
			}
			else if(cur-D >= 0 && floor[cur-D] == false){ // 위쪽으로 가지 못한다면 아래쪽으로 이동 / 범위 내에 있어야 하며, 이동할 층는 방문한 적 없어야 함
				cur = cur-D; // 현재 위치 이동 층으로 변경
				floor[cur] = true; // 방문 체크
				cnt++; // 버튼 누른 횟수 1 증가
			}
			else{ // 위로 아래로 모두 이동할 수 없다면 더 이상 목적지로 갈 방법이 없음
				cout << "use the stairs"; // "use the stairs"를 출력 후 종료
				return 0;
			}
		}
		else{ // 목적지가 더 아래쪽이라면
			if(cur-D >= 0 && floor[cur-D] == false){ // 아래쪽으로 이동 가능한지 먼저 확인 /  범위 내에 있어야 하며, 이동할 층에 방문한 적이 없어야 함
				cur = cur-D; // 현재 위치 이동 층으로 변경
				floor[cur] = true; // 방문 체크
				cnt++; // 버튼 누른 횟수 1 증가
			}
			else if(cur+U < F && floor[cur+U] == false){ // 아래쪽으로 이동 불가능하다면 위쪽으로 이동 / 범위 내에 있어햐 하며, 이동할 층에 방문한 적이 없어야 함
				cur = cur+U; // 현재 위치 이동 층으로 변경
				floor[cur] = true; // 방문 체크
				cnt++; // 버튼 누른 횟수 1 증가
			}
			else{ // 위로 아래로 모두 이동할 수 없다면 더 이상 목적지로 갈 방법이 없음
				cout << "use the stairs"; // "use the stairs"를 출력 후 종료
				return 0;
			}
		}
	}
	
	cout << cnt; // 목적지 도착 시 버튼 누른 횟수 출력
	
	return 0;
}
