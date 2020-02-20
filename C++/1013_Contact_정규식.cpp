#include <iostream>
#include <regex>
using namespace std;

// 정규식 쓰기 위해 regex include 해줌
int main() {
	int T;
	cin >> T;
	
	for(int t = 0; t < T; t++){
		char S[201];
		cin >> S;
		
		regex reg("(100+1+|01)+"); // 해당 패턴을 갖는 문자열 찾기 위해 패턴 입력
		if(regex_match(S,reg)){ // 해당 패턴으로 이루어져있으면 YES
			cout << "YES\n";
		}
		else{ // 해당 패턴으로 이루어져 있지 않으면 NO
			cout << "NO\n";
		}
	}
	
	return 0;
}
