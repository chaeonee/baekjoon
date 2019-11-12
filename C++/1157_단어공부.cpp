#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;

int main() {
	char S[1000001];
	cin >> S;
	
	int len = strlen(S);
	int arr[26] = {0,};
	for(int i = 0; i < len; i++){ // 알파벳 몇 개인지 세기
		if(S[i] >= 'A' && S[i] <= 'Z'){
			arr[S[i]-65]++;
		}
		else if(S[i] >= 'a' && S[i] <= 'z'){
			arr[S[i]-97]++;
		}
	}
	
	int max = 0, idx = -1;
	for(int i = 0; i < 26; i++){ //arr 돌면서
        	if(arr[i] != 0){
        		if(max < arr[i]){ // 등장 횟수 큰 것 등장
        			max = arr[i];
        			idx = i;
        		}
        		else if(max == arr[i]){ //등장한 것 중에 등장 횟수가 같은 것 존재하면 '?'
        			idx = -1;
        		}
		}
	}
	
	if(idx == -1){
		cout << '?';
	}
	else{
		cout << (char)(idx+65); //대문자로 출력
	}
	
	return 0;
}