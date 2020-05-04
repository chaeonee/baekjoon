#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main() {
	int T = 0; // 루프의 순서 알려줄 변수
	while(true){
		string S;
		cin >> S;
		
		int s_len = S.length();
		if(s_len > 0 && S[0] == '-'){ // 만약 '-'가 한 개 이상 존재하면 종료
			break;
		}
		
		T++;
		
		int cnt = 0; // 연산의 수를 세기 위한 변수
		stack<bool> s; // '{'를 넣기 위한 stack('{'를 true로 넣을 것)
		for(int i = 0; i < s_len; i++){ // 문자열의 문자 하나씩 확인
			if(S[i] == '{'){ // '{'일 경우
				s.push(true); // stack에 추가
			}
			else{ // '}'일 경우
				if(s.empty()){ // stack이 비어있는지 확인해서 비어있으면 짝이 맞지 않는 것
					cnt++; // 이때 '}'를 '{'로 바꿔주기 -> 연산 수 1증가
					s.push(true); // '{'로 바꾸었기 때문에 stack에 추가
				}
				else{ // stack이 비어있지 않으면
					s.pop(); // stack의 '{'와 짝을 이루기 때문에 하나 pop!
				}
			}
		}
		
		int s_size = s.size();
		if(s_size != 0){ // 안정적인 문자열이라면 짝이 모두 맞기 때문에 stack이 비어있어야 함 -> 비어있지 않은 경우는 '{'가 더 많은 경우
			cnt += s_size/2; // 남은 '{'끼리 서로 짝을 만들어 주어야 하므로 남은 '{'의 절반을 '}'로 바꿔야 함 -> 연산수: 남은 '{'의 수/2 만큼 추가
		}
		
		cout << T << ". " << cnt << '\n';
	}
	
	return 0;
}
