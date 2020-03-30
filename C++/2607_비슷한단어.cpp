#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	char s1[11];
	cin >> s1;
	
	int len1 = strlen(s1);
	int s1_arr[26] = {0,};
	for(int i = 0; i < len1; i++){
		s1_arr[s1[i]-65] += 1;
	} // 첫 번째 단어 알파벳 세기
	
	int result = 0; // 비슷한 단어 찾기 시작
	for(int n = 1; n < N; n++){
		char s2[11];
		cin >> s2;
		
		int len2 = strlen(s2);
		int s2_arr[26] = {0,};
		for(int i = 0; i < len2; i++){
			s2_arr[s2[i]-65] += 1;
		} // 비교할 단어 알파벳 세기
		
		if(len1-len2 < 2 && len1-len2 > -2){ // 일단 길이가 1이상 차이나면 비슷한 단어가 될 수 없음
			result++; // 일단 비슷한 단어라고 생각하고 result 1 증가
			int sub1 = 0, sub2 = 0; // 대치 되는 단어도 고려해 주어야 함(교체가 될때는 다른 단어가 2개 존재할텐데 무작정 다 빼서 생각하면 다른 문자 2개 있을 때도 포함되게 됨 -> 따라서 첫 번째 단어에만 존재하는 알파벳의 수 비교할 단어에만 존재하는 알파벳의 수 따로 세어주어야 함)
			for(int i = 0; i < 26; i++){
				if(s1_arr[i] - s2_arr[i] > 0){ // 첫 번째 단어에만 존재하는 알파벳일 경우
					sub1 += s1_arr[i] - s2_arr[i]; // 더 있는만큼 sub1에 추가
				}
				else if(s1_arr[i] - s2_arr[i] < 0){ // 비교할 단어에만 존재하는 알파벳일 경우
					sub2 += s2_arr[i] - s1_arr[i]; // 더 있는만큼 sub2에 추가
				}
				
				if(sub1 > 1 || sub2 > 1){ // 둘 중 하나라도 1보다 클 경우에는 비슷한 단어 아님
					result--; // 처음에 비슷한 단어라고 가정하였기 때문에 1만큼 다시 감소시킴
					break; // 더이상 볼 필요 없으므로 break
				}
			}
		}
	}
	
	cout << result;
	
	return 0;
}
