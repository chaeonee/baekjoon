#include <iostream>
#include <cstring>
using namespace std;

bool check(char S[], int idx, int len, bool flag);

int main() {
	int T;
	cin >> T;
	
	for(int t = 0; t < T; t++){
		char S[201];
		cin >> S;
		int len = strlen(S);
		bool flag = true;
		flag = check(S,0,len,flag);
		
		if(flag == true){ // flag가 true이면 해당 패턴으로 이루어진 것
			cout << "YES\n";
		}
		else{ //false라면 해당 패턴 이외의 패턴 존재
			cout << "NO\n";
		}
	}
	
	return 0;
}

bool check(char S[], int idx, int len, bool flag){
	if(flag == false){ // flag가 flase이면 해당 패턴과 벗어나는 패턴 존재 -> 더 이상 볼 필요 없이 false return
		return flag;
	}
	
	if(idx == len){ // flag가 false인 경우는 위에서 이미 종료, ture인 경우만 존재하게 됨
		return flag; //idx == len이면 끝까지 확인한 것 -> 진행 완료되었으므로, flag return(여기서 flag는 true)
	}
	
	// 패턴은 크게 두 가지로 나눌 수 있음 / 100+1+과 01
	if(S[idx] == '0' && idx < len-1){ // 01 패턴 찾기 위함 01이 모두 있어야 하므로 뒤에 적어도 한 개 이상의 문자 남아 있어야 함
		if(S[idx+1] == '1'){ // 01 패턴 완성되면
			flag = true; // flag == true
			flag = check(S, idx+2, len, flag); // 다음 문자 패턴 확인하기 위한 재
		}
		else{ // 01패턴 아니므로 false
			flag = false;
		}
	}
	else if(S[idx] == '1' && idx < len-3){ //100+1+ 패턴이 구성되기 위해서는 적어도 1001 4개 문자 있어야 
		int tmp = 1;
		while(S[idx+tmp] == '0' && idx+tmp < len){ // 1 뒤에 0이 몇 개 있는지 확인(2개 이상이어야 함)
			tmp++;
		}
		if(tmp <= 2 || idx+tmp == len){ // 0이 2개 이상되지 않거나 끝까지 다 0일 경우 false(맨 뒤에 1이 있어야 하는데 들어갈 자리가 없으니까)
			flag = false;
		}
		else{ // 일단 0 이후의 첫 번째 1은 100+1+ 패턴에 꼭 포함되어야 함 / 그 이후의 1은 1+에 포함되는 것일 수도 있고 새로운 100+1+ 패턴이 시작되는 것일 수도 있
			idx += tmp;
			tmp = 0;
			while(S[idx+tmp] == '1' && idx+tmp < len){
				tmp++;
			}
			// 1+ 패턴 먼저 확인
			flag = check(S, idx+tmp, len, flag);
			
			if(flag == false && tmp > 1){ // false이면 1+ 패턴으로 재귀 수행했을 때, 해당 패턴 이외의 패턴 존재하는 것이므로 100+1+ 패턴 확인해 봐야 함
				flag = true; // 100+1+ 패턴인지 다시 확인하기 위해 flag true로 바꾸기
				flag = check(S, idx+tmp-1,len,flag); // 100+1+ 패턴이 다시 시작하기 위해서는 반복되는 1 중 마지막 1부터 시작하면됨(다음에는 00이 추가로 나와야 하니까)
			}
		}
	}
	else{ // 두 패턴에 모두 포함되지 않으면 false
		flag = false;
	}
	return flag;
}