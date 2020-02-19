#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
	int arr[26] = {0,}; // 문자 열에 해당 알파벳이 몇 개 존재하는지 저장하기 위한 배열
	
	char S[1001];
	cin >> S; // 첫 번째 문자열
		
	int len = strlen(S);
	for(int j = 0; j < len; j++){
		arr[S[j]-97]++; // 첫 번째 문자열에 존재하는 해당 알파벳의 수를 기록하기 위해 더함
	}
	
	cin >> S; // 두 번째 문자열
	len = strlen(S);
	for(int j = 0; j < len; j++){
		arr[S[j]-97]--; // 공통되지 않은 부분을 찾아야 하기 때문에 두 번째 문자열에 대한 알파벳은 빼줌
	}
	
	len = 0;
	for(int i = 0; i < 26; i++){ // 아예 존재하지 않거나 두 문자열 모두에게 동일하게 존재하는 알파벳의 수는 0이 될 것
		len += abs(arr[i]); // 첫 번째 문자열은 더해주었고 두 번째 문자열은 빼주었으니 둘의 절댓값의 합을 구해줘야 함(수를 세기 위해서는 모두 양수여야 함)
	}
	
	cout << len;
	
	return 0;
}