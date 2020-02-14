#include <iostream>
#include <cstring>
using namespace std;

int main() {
	char S[101];
	cin >> S;
	
	int arr[26] = {0,}; // 알파벳 개수 담을 배열
	int num = strlen(S);
	for(int i = 0; i < num; i++){ // 입력 받은 알파벳 수만큼 for문
		int idx = S[i]-97; // 소문자 a의 아스키코드 97(a를 0으로 넣기 위함)
		arr[idx] += 1; // 현재 알파벳에 해당하는 배열의 값 1 증가
	}
	
	for(int i = 0; i < 26; i++){
		cout << arr[i] << ' ';
	}
	
	return 0;
}