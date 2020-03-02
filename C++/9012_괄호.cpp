#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		string s;
		cin >> s;
		
		int s_len = s.size(), cnt = 0;
		for(int i = 0; i < s_len; i++){
			if(cnt < 0){ // cnt가 0이면 짝이 맞지 않는 ')'가 존재한다는 뜻이므로 규칙 위반 -> 더 이상 볼 필요 없음
				break;
			}
			if(s[i] == '('){ // '(' 일때는 cnt 1 증가
				cnt++;
			}
			else{ // ')' 일때는 cnt 1 감소
				cnt--;
			}
		}
		
    // cnt가 0일 때만 모든 짝이 맞는 것
		if(cnt == 0){
			cout << "YES\n";
		}
		else{
			cout << "NO\n";
		}
	}
	return 0;
}
