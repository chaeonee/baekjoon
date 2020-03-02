#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t = 0; t < T; t++){
		string s;
		cin >> s;
		
		bool flag = true; // flag가 true면 규칙에 위배되는 ')'는 존재하지 않음(규칙에 위배되는 '('는 존재할 수 있음)
		stack<char> bracket;
		int s_len = s.size();
		for(int i = 0; i < s_len; i++){
			if(s[i] == '('){ // 여는 괄호는 stack에 삽입
				bracket.push('(');
			}
			else{ // 닫는 괄호 만나면 여는 괄호 pop
				if(bracket.size() == 0){ // 만약 pop할 괄호가 없다면 닫는 괄호와 쌍이 될 여는 괄호 없다는 뜻이므로 flag를 false로 바꾸고 break
					flag = false;
					break;
				}
				bracket.pop(); // 아니라면 pop
			}
		}
		
		if(bracket.size() == 0 && flag == true){ // 규칙에 위배되는 ')'가 존재하지 않고(flag = true), 모든 '('의 쌍이 존재한다면(bracket.size() = 0)
			cout << "YES\n"; // YES 출력
		}
		else{ // 아니라면 NO 출력
			cout << "NO\n";
		}
	}
	return 0;
}
