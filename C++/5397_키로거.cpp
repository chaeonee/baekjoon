#include <iostream>
#include <deque>
#include <cstring>
using namespace std;

// vector로 풀면 시간 초과 -> 2개의 deque를 이용하여 풀기로 함
int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		char c[1000001];
		cin >> c;
		
		int len = strlen(c);
		
		deque<char> dq1; // 커서를 중심으로 앞쪽
		deque<char> dq2; // 커서를 중심으로 뒤쪽
		for(int i = 0; i < len; i++){
			if(c[i] == '<'){ // 커서 왼쪽 이동
				if(dq1.size() != 0){ // 앞쪽 deque의 마지막 값이 뒤쪽 deque의 첫 번째 값이 됨(커서 위치가 맨 앞이면 이동 불가)
					char tmp = dq1.back();
					dq1.pop_back();
					dq2.push_front(tmp);
				}
			}
			else if(c[i] == '>'){ // 커서 오른쪽 이동
				if(dq2.size() != 0){ // 뒤쪽 deque의 첫 번째 값이 앞쪽 deque의 마지막 값이 됨(커서 위치가 맨 뒤면 이동 불가)
					char tmp = dq2.front();
					dq2.pop_front();
					dq1.push_back(tmp);
				}
			}
			else if(c[i] == '-'){ // 커서 앞쪽 문자 삭제
				if(dq1.size() != 0){ // 커서가 맨 앞에 위치하지 않았다면, 커서 앞쪽 문자 삭제(커서 앞쪽은 앞쪽 deque의 마지막 값)
					dq1.pop_back();
				}
			}
			else{ // 문자 삽입, 문자 삽입 후 커서는 삽입 문자 뒤쪽으로 이동해야 하므로 앞쪽 deque의 마지막에 문자 추가
				dq1.push_back(c[i]);
			}
		}
		
		// 앞쪽 deque와 뒤쪽 deque를 차례로 출력
		len = dq1.size();
		for(int i = 0; i < len; i++){
			cout << dq1[i];
		}
		len = dq2.size();
		for(int i = 0; i < len; i++){
			cout << dq2[i];
		}
		cout << '\n';
	}
	
	return 0;
}