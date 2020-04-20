#include <iostream>
#include <cmath>
using namespace std;

// 에라토스테네스의 체 알아야 풀 수 있음...ㅎ
int main() {
	long long int s,e;
	cin >> s >> e;
	
	long long int cnt = 0, e_sqrt = (long long int)sqrt((long double)e);
	bool arr[e_sqrt+1] = {0,}; // 범위 끝 값의 루트 이상은 거의 소수 존재하지 않음(제곱해도 범위를 넘을테니) -> 루트만큼만 구하기
	
	for(long long int i = 2; i <= e_sqrt; i++){
		if(arr[i] == false){ // false면 소수
			arr[i] = true;
			long long int tmp = e_sqrt/i;
			for(long long int j = 2; j <= tmp; j++){ // 소수의 배수들은 소수가 아닐 것이므로 방문처리
				arr[i*j] = true;
			}
			
			long long int  n = 1;
			while(true){ // 거의 소수 구하기
				long long int result = (long long int)pow(i,n);
				if(result > e/i){ // result가 long long int의 범위 넘을 수 있기 때문에 i^(n-1)구해서 e/i와 비교하기(그래서 위쪽의 n이 2가아닌 1부터 시작하는 것)
					break; // 끝값을 넘으면 더이상 범위 내의 거의 소수가 없다는 것이므로 break
				}
				else if(result*i >= s){ // 시작점 비교는 원래 값과 해야 함 -> 따라서 소수를 한 번 더 곱해주고 시작점과 비교
					cnt++; // 범위 안에 속하기 때문에 cnt 1증가
				}
				n++;
			}
		}
	}
	
	cout << cnt;
	
	return 0;
}
