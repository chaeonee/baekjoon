#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int N;
	cin >> N;
	for(int n = 0; n < N; n++){
		char a[1001], b[1001];
		cin >> a >> b;
		
		int a_len, b_len;
		a_len = strlen(a);
		b_len = strlen(b);
		
		if(a_len != b_len){ // 만약 문자열의 길이가 다르다면 더 이상 비교 진행하지 않고 불가능함을 출력(strfry함수가 적용되려면 구성이 아예 동일해야 하기 때문)
			cout << "Impossible\n";
			continue;
		}
		
		int count[26] = {0,}; // a와 b의 알파벳 구성을 나타낼 배열
		for(int i = 0; i < a_len; i++){
			count[a[i]-97]++; // a에 포함된 알파벳에 해당하는 index를 증가시켜줌
			count[b[i]-97]--; // b에 포함된 알파벳에 해당하는 index를 감소시켜줌
		} // 이를 계산했을 때 배열 내의 모든 값이 0이어야 strfry함수가 적용하여 얻을 수 있는 문자로 판단
		
		bool flag = true;
		for(int i = 0; i < 26; i++){
			if(count[i] != 0){
				flag = false; // 0이 아닌 값을 만나면 바로 반복문을 나가 Impossible 출력
				break;
			}
		}
		if(flag == true){ // 배열의 값이 모두 0이면 Possible 출력
			cout << "Possible\n";
		}
		else{
			cout << "Impossible\n";
		}
	}
	
	return 0;
}
