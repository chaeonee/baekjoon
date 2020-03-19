#include <iostream>
#include <stack>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int top[N];
	for(int i = 0; i < N; i++){
		cin >> top[i];
	}
	
  // 현재 위치의 탑보다 낮은 탑이 내 앞쪽에 위치하고 있으면, 앞쪽 탑들은 더 이상 신호 받을 수 없음
	stack<int> s;
	for(int i = 0; i < N; i++){
		while(!s.empty()){
			int pos = s.top();
			if(top[i] > top[pos]){ // 기존의 탑이 현재의 위치의 탑보다 낮다면, 더 이상 신호 받을 수 없으므로 pop
				s.pop();
			}
			else{ // 더 높은 애 있으면 일단 while에서 빠져나오기
				break;
			}
		}
		
		if(s.empty()){ // stack이 비어있으면 내 앞쪽에 나보다 높은 탑 없다는 뜻이므로 0 출력
			cout << 0 << " ";
		}
		else{ // 아니라면 앞쪽 탑 중 나랑 가장 가까운애 출력하기 위해 stack의 top index 출력(1더해준 이유는 현재 index는 0부터 시작하는데 문제 정답을 위한 index는 1부터 시작되도록 설계되어야 함)
			cout << s.top()+1 << " ";
		}
		
		s.push(i); // 현재 탑의 레이져 수신 결과를 출력하면 현재 탑을 stack에 넣어줌
	}
	
	return 0;
}
