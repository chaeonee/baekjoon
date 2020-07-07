#include <iostream>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	char formula[51];
	cin >> formula;
	
	vector<char> oper;
	vector<int> num;
	
	int len = strlen(formula);
	
	int digit = 4, n = 0; // 최대 5자리를 안 넘기 때문에 10^4부터 10^0까지 주어진 숫자와 곱해주는 과정 필요(일단 모든 수를 5자리라고 가정)
	for(int i = 0; i < len; i++){
		if(formula[i] == '+' || formula[i] == '-'){ // + 또는 -를 만나면
			num.push_back(n/(int)pow(10,digit+1)); // 지금까지 만난 수 계산하여 숫자를 담는 벡터에 넣기(5자리가 아니라면 digit이 0이 안되었을 것.. 그러므로 10^digit을 나눠줘서 주어진 수의 자릿수에 맞게..(불필요한 0 없애기))
			oper.push_back(formula[i]); // 연산자를 넣는 벡터에 연산자(+,-) 넣기
			digit = 4; // 자릿수 초기화
			n = 0; // 숫자를 계산할 값 역시 초기화
			continue;
		}
		
		n += (int)(formula[i]-'0')*(int)pow(10,digit); // char로 받았기 때문에 '0'를 빼주는 과정 필요 / 현재 숫자를 구하기 위한 과정
		digit--; // 한자리 수 감소시켜 한자리에 숫자 하나씩 넣도록
	}
	num.push_back(n/(int)pow(10,digit+1)); // 여기까지 수식 처리... 사실 나눠주는 형식 말고 1~10^4까지 곱해줘도 되는데.. 복잡하게 푼 것 같음ㅠ
	
	int result = num[0]; // 식의 첫 번째 숫자가 초기값이 됨
	for(int i = 0; i < oper.size(); i++){
		if(oper[i] == '+'){ // 이 '+'는 '-'가 한 번도 나오지 않을 때를 대비하여 넣은 것
			result += num[i+1]; // 결과에 더해주기
		}
		else{ // '-' 만났을 때
			int tmp = num[i+1], j = i+1;
			while(j < oper.size() && oper[j] == '+'){ // 다음 '-' 만나거나 마지막 숫자 만날 때까지 부분 합 구해주기
				tmp += num[j+1]; // 부분합 구하기
				j++;
			}
			i = j-1; // 계산한 값들 건너 뛰도록 i를 j-1로 갱신(for문 안의 식으로 인해 i가 1증가할 것이기 때문에 j가 아닌 j-1로 갱신)
			result -= tmp; // 부분 합을 전체 결과에서 빼줌
		}
	}
	
	cout << result;

	return 0;
}
