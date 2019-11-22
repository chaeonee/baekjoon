#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int T;
	cin >> T;
	
	char s[11];
	cin >> s; // 기준 단어
	
	int s_arr[26] = {0,}; //s에 A부터 Z까지의 알파벳이 몇 개 있는지 세기 위한 배열
	for(int i = 0; i < strlen(s); i++){
		int idx = (int)s[i]-65;
		s_arr[idx]++;
	}
	
	int result = 0;
	for(int t = 1; t < T; t++){
		char w[11];
		cin >> w; // 비교할 단어
		
		int w_arr[26] = {0,}; //w에 A부터 Z까지의 알파벳이 몇 개 있는지 세기 위한 배열
		for(int i = 0; i < strlen(w); i++){
			int idx = (int)w[i]-65;
			w_arr[idx]++;
		}
		
		// 길이가 같을 때는 아예 구성이 아예 같거나, 하나만 달라서 다른 문자로 바꾸는 경우 존재
		// 바꾸는 경우 s와 w배열에서 다른 부분이 하나씩 존재(다른 부분의 수 총 2개)
		if(strlen(s) == strlen(w)){ 
			int tmp = 0;
			for(int i = 0; i < 26; i++){
				if(s_arr[i] != w_arr[i]){
					tmp++;
					
					if(tmp > 2){ // 다른게 2개 넘어가면 더 이상 볼 필요 없음
						break;
					}
				}
			}
			if(tmp <= 2){
				result++;
			}
		}
		
		// 길이가 다를 때는 딱 하나만 다르고 나머지는 같아야 함
		// s와 w 중 더 긴 쪽에 다른 부분이 하나 존재할 것임
		else{
			int tmp = 0;
			for(int i = 0; i < 26; i++){
				if(s_arr[i] != w_arr[i]){
					tmp++;
					
					if(tmp > 1){ // 한 개 이상 다르면 더 이상 볼 필요 없음
						break;
					}
				}
			}
			if(tmp <= 1){
				result++;
			}
		}
	}
	
	cout << result;
	
	return 0;
}