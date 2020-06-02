#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void getPwd(int L, int C, char *letter, vector<char>pwd, int c, int v, int s);

int main() {
	int L,C;
	cin >> L >> C;
	
	char *letter = new char[C];
	for(int i = 0; i < C; i++){
		cin >> letter[i];
	}
	
	sort(letter,letter+C); // 사전 순으로 sorting
	
	vector<char> pwd; // 암호를 담을 벡터
	getPwd(L,C,letter,pwd,2,1,0);
	
	return 0;
}

void getPwd(int L, int C, char *letter, vector<char>pwd, int c, int v, int s){
	if(pwd.size() == L){ // 암호의 길이 만족하고
		if(c <= 0 && v <= 0){  // 자음 최소 2개, 모음 최소 1개 모두 사용했다면
			for(int i = 0; i < L; i++){ // 암호 조건 만족하므로 출력
				cout << pwd[i];
			}cout << '\n';
		}
		
		return;
	}
	
	for(int i = s; i < C; i++){ // 암호 만들기(백트래킹 이용하여서 만들기)
		pwd.push_back(letter[i]); // 해당 문자 암호 값에 추가
		if(letter[i] == 'a' || letter[i] == 'e' || letter[i] == 'i' || letter[i] == 'o' || letter[i] == 'u'){ // 해당 문자가 모음이면
			getPwd(L,C,letter,pwd,c,v-1,i+1); // 모음의 최소 사용 횟수 1 감소, 사전 순의 암호만 유효하기 때문에 다음 문자는 i+1번째 문자부터 확인하기
		}
		else{ // 해당 문자가 자음이면
			getPwd(L,C,letter,pwd,c-1,v,i+1); // 자음의 최소 사용 횟수 1 감소, 사전 순의 암호만 유효하기 때문에 다음 문자는 i+1번째 문자부터 확인하기
		}
		pwd.pop_back(); // 백트래킹을 위해 넣었던 문자 pop
	}
}
