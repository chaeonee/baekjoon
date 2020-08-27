#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int cnt = 0; // 시리즈 번호
	long long int num = 665; // 영화의 제목에 들어간 숫자
	while(num++){ // 666부터 수를 1씩 증가시켜가며 시리즈 번호가 될 수 있는지 확인
		bool flag = false; // 해당 수에 666이 들어가는지 여부
		long long int tmp = num;
		while(tmp > 0){ // 해당 수의 자리수 1씩 줄여가면서 666이 들어가는지 확인
			if(tmp % 1000 == 666){ // 뒤부터 3자리에 666이 들어가는지 확인
				flag = true; // 들어간다면 flag ture로 바꾸고
				break; // 탐색 중지
			}
			
			tmp /= 10; // 해당 수의 자리수 1 줄임(일의 자리 수 삭제)
		}
		
		if(flag){ // 666이 들어가는 수라면
			cnt++; // 시리즈 번호 1 증가
		}
		
		if(cnt == N){ // 해당 수가 원하는 시리즈 번호의 수라면
			cout << num; // 출력 후
			break; // 루프 탈출
		}
	}
	
	return 0;
}
