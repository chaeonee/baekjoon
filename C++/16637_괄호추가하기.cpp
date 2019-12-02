#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int dfs(int s, int e, char num[], char oper[], int bracket[], int result);
int getNum(int N, char num[], char oper[], int bracket[]);

int main() {
	int N;
	cin >> N;
	char s[N];
	cin >> s;
	
	char num[(N/2)+1];
	char oper[N/2];
	for(int i = 0; i < N; i++){
		if(i%2 == 0){
			num[i/2] = s[i];
		}
		else{
			oper[i/2] = s[i];
		}
	}
	
	if(N == 1){ // input이 숫자 1개만 주어졌을 때는 주어진 숫자 출력하기(연산자 없을 때)
		cout << num[0];
		return 0;
	}
	int bracket[N/2] = {0,};
	cout << dfs(0, N/2, num, oper, bracket,-2147483648);
	
	return 0;
}

int dfs(int s, int e, char num[], char oper[], int bracket[], int result){ //괄호 선택
	if(s == e){ //s와 e가 같아지면 모든 괄호 선택할지 말지 결정했다는 의미
		int tmp = getNum(e, num, oper, bracket); // 선택한 괄호 이용하여 값 구하기
		result = max(result, tmp); //최댓값 선택
		return result;
	}
	
	result = max(result,dfs(s+1, e, num, oper, bracket, result)); //이전 괄호가 있는지 없는지에 관계 없이 현재 괄호는 없을 수 있음
	if(s == 0 || bracket[s-1] == 0){ // 이전 괄호가 없었으면 다음 차례 괄호 선택 가능
		bracket[s] = 1; //괄호 선택하고 dfs 재귀 진행
		result = max(result,dfs(s+1, e, num, oper, bracket, result)); // 최댓값 선택
		bracket[s] = 0; //괄호 해제
	}
	
	return result;
}

int getNum(int N, char num[], char oper[], int bracket[]){
	queue<int> q_num;
	queue<char> q_op;
	int visit[N+1] = {0,};
	
	for(int i = 0; i < N; i++){
		if(bracket[i] == 1){ //괄호가 선택 되었고
			if(visit[i] == 0){ // num을 사용한 적이 없다면 연산자에 따라 계산하여 queue에 넣기
				if(oper[i] == '+'){
					int x = (num[i]-'0');
					int y = (num[i+1]-'0');
					x += y;
					q_num.push(x);
					visit[i] = 1;
					visit[i+1] = 1;
				}
				else if(oper[i] == '-'){
					int x = (num[i]-'0');
					int y = (num[i+1]-'0');
					x -= y;
					q_num.push(x);
					visit[i] = 1;
					visit[i+1] = 1;
				}
				else if(oper[i] == '*'){
					int x = (num[i]-'0');
					int y = (num[i+1]-'0');
					x *= y;
					q_num.push(x);
					visit[i] = 1;
					visit[i+1] = 1;
				}
				
			}
		}
		else{
			if(visit[i] == 0){ //괄호가 선택되지 않았고 현재 숫자 방문한 적 없으면
				q_num.push((int)num[i]-'0'); //숫자 추가
				q_op.push(oper[i]); // 연산자 추가
			}
			else{ //괄호가 선택되지 않았고 현재 숫자 방문한 적 있으면
				q_op.push(oper[i]); // 연산자만 추가
			}
		}
	}
	if(visit[N] == 0){ // 마지막 숫자 방문한 적 없으면 추가하고 아니면 이미 계산된 것임(괄호에서)
		q_num.push((int)num[N]-'0');
	}
	
	int result = q_num.front();
	q_num.pop(); // 결과 값을 queue의 front 값으로 설정
	while(!q_num.empty()){ // 연산자 하나씩 빼면서 result에 저장된 값과 queue의 값을 순서대로 계산(이미 괄호는 계산되었고 이제 왼쪽부터 계산하는 과정)
		char op = q_op.front();
		q_op.pop();
		
		if(op == '+'){
			result += q_num.front();
			q_num.pop();
		}
		else if(op == '-'){
			result -= q_num.front();
			q_num.pop();
		}
		else if(op == '*'){
			result *= q_num.front();
			q_num.pop();
		}
	}
	
	return result;
}