#include <iostream>
#include <stack>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	long long int height[N];
	for(int i = 0; i < N; i++){
		cin >> height[i];
	} // 높이를 담을 배열(높이 범위 주의! int 안됨)
	
	int num[N] = {0,}; // 각 건물이 볼 수 있는 건물들의 수
	
	stack<int> s; // 건물들의 index를 담을 stack
	s.push(N-1);
	for(int i = N-2; i >= 0; i--){ // 맨 끝의 건물은 볼 수 있는 건물이 없으므로 N-1번째 건물부터 확인하면서 앞으로 이동
		int cnt = 0;
		while(!s.empty()){ // stack이 비어있지 않아야 함
			if(height[s.top()] >= height[i]){ // 현재 stack에 있는 건물들의 높이 확인 더 높은 건물이라면 볼 수 없기 때문에 break
				break;
			}
			cnt++; // 현재 stack 맨 위의 건물은 볼 수 있는 건물이므로 볼 수 있는 건물 개수 1 추가
			
			int n = s.top();
			num[i] += num[n]; // 현재 stack 맨 위의 건물이 볼 수 있는 건물은 현재 건물도 볼 수 있는 건물이므로 모두 더해주기(이전에 pop 되어서 stack 안에는 존재하지 않을 것 -> stack 내에 없는 건물 중 현재 건물에서 볼 수 있는 건물의 수 추가) 
			s.pop();
		}
		num[i] += cnt; // 볼 수 있는 건물의 수 더해주기(stack 내에 있었던 건물 중 현재 있는 건물에서 볼 수 있는 건물의 수)
		
		s.push(i); // 확인한 건물의 index stack에 삽입
	}
	
	long long int result = 0; // result 범위 주의(int 안됨)
	for(int i = 0; i < N; i++){ // num 배열의 합 구하기
		result += num[i];
	}
	
	cout << result;
	
	return 0;
}
