#include <iostream>
#include <set>
#include <string>
using namespace std;

// hash 또는 set을 이용하는 문제
int main() {
	int N;
	cin >> N;
	
	set<string> namecard; // 현재 회사에 있는 사람 목록(set이 자연스럽게 사전순으로 정의해 줌)
	set<string>::reverse_iterator iter; // 거꾸로 출력하기 위해 선언
	for(int n = 0; n < N; n++){
		string name, stat;
		cin >> name >> stat;
		if(stat == "enter"){ // 출근했으면 set에 추가해주기
			namecard.insert(name);
		}
		else if(stat == "leave"){ // 떠났으면 set에서 빼주기
			namecard.erase(namecard.find(name));
		}
	}
	
	for(iter = namecard.rbegin(); iter != namecard.rend(); iter++){ // 사전 반대 순으로 출력하기
		cout << *iter << '\n';
	}
	
	return 0;
}
