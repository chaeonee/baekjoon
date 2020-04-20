#include <iostream>
#include <vector>
using namespace std;

vector<int> calNum(int N, int s, int A[], vector<int> oper, vector<int> result, int now, bool visit[]);

int main() {
	int N;
	cin >> N;
	
	int A[N];
	for(int i = 0; i < N; i++){
		cin >> A[i];
	}
	
	vector<int> oper; // 연산자 담기
	for(int i = 0; i < 4; i++){
		int tmp;
		cin >> tmp;
		for(int j = 0; j < tmp; j++){
			oper.push_back(i);
		}
	}
	
	bool visit[N-1] = {0,}; // 연산자 사용 여부
	vector<int> result(2); // 최대 최소를 담을 vector
	result[0] = -1000000001; //최대값을 구하기 위한 초기값
	result[1] = 1000000001; // 최소값을 구하기 위한 초기값
	result = calNum(N,1,A,oper,result,A[0],visit);
	cout << result[0] << '\n' << result[1];
	
	return 0;
}

vector<int> calNum(int N, int s, int A[], vector<int> oper, vector<int> result, int now, bool visit[]){
	if(s == N){
		if(now > result[0]){
			result[0] = now; // 최대값 갱신
		}
		if(now < result[1]){ // 최소값 갱신
			result[1] = now;
		}
		
		return result;
	}
	
	for(int i = 0; i < N-1; i++){
		if(visit[i] == false){ // 사용한 적 없는 연산자라면
			visit[i] = true; // 연산자 사용 표시
			
			switch(oper[i]){
				case 0: // 더하기
					result = calNum(N,s+1,A,oper,result,now+A[s],visit);
					break;
				case 1: // 빼기
					result = calNum(N,s+1,A,oper,result,now-A[s],visit);
					break;
				case 2: // 곱하기
					result = calNum(N,s+1,A,oper,result,now*A[s],visit);
					break;
				case 3: // 나누기
					result = calNum(N,s+1,A,oper,result,now/A[s],visit);
					break;
			}
			
			visit[i] = false; // 연산자 사용 취소(백트래킹위해)
		}
	}
	
	return result;
}
