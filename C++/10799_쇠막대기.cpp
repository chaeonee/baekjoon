#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char s[100001];
	cin >> s;
	
	int s_len = strlen(s);
	int open = 0, cnt = 0; // open 현재 열려있는 괄호 개수(현재 레이저 영향권에 있는 막대기들 수), cnt: 전체 막대의 수
	for(int i = 0; i < s_len; i++){
		if(s[i] == '('){ // 괄호가 열리면 레이져일수도 있고 막대기 일 수도 있음
			if(s[i+1] == ')'){ // 바로 뒤에 있는 괄호가 닫히는 괄호이면 레이저
				i++; // 건너뛰기 위해 i 한 번 더 증가
				cnt += open; // 잘렸을 테니까 현재 영향권에 있는 막대기들 수 만큼 전체 막대의 수가 늘어남
			}
			else{ // 아니라면 막대기라는 이야기
				cnt++; // 전체 막대기의 수 1 증가(막대기가 하나 더 생긴 것)
				open++; // 영향권에 있는 막대기의 수도 1 증가
			}
		}
		else{ // 이는 막대기 끝 점
			open--; // 레이저 영향권에 있는 막대기 하나 줄임
		}
	}
	
	cout << cnt;
	
	return 0;
}
