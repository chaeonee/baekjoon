#include <iostream>
#include <deque>
using namespace std;

int main() {
	ios::sync_with_stdio(0);
    cin.tie(0); // cin, cout 속도를 더 빠르게 해주기 위함
    
	int N;
	cin >> N;
	
	deque<int> q; // deque 사용하는 이유는 back을 출력하기 위함
	for(int i = 0; i < N; i++){
		string order;
		cin >> order; // 명령어 받기 위함
		
		if(order == "push"){ // push 명령어
			int n;
			cin >> n;
			q.push_back(n); // q에 숫자 n삽입
		}
		
		else if(order == "pop"){ // pop 명령어
			if(q.empty()){ // q가 비어있으면
				cout << "-1\n"; // -1 출력
			}
			else{ // 비어있지 않으면
				cout << q.front() << '\n';
				q.pop_front(); // pop한 문자 출력(c++에서는 pop했을 때의 return 값이 void이므로 pop되는 문자를 출력하려면 front 값을 출력한 후 pop 진행해야 함)
			}
		}
		
		else if(order == "size"){ // size 명령어
			cout << q.size() << '\n'; // q의 크기 출력
		}
			
		else if(order == "empty"){ // empty 명령어
			if(q.empty()){ // 비어있으면
				cout << "1\n"; // 1 출력
			}
			else{ // 아니면
				cout << "0\n"; // 0 출력
			}
		}
		
		else if(order == "front"){ // front 명령어
			if(q.empty()){ // q가 비어있으면
				cout << "-1\n"; // -1 출력
			}
			else{ // 아니면
				cout << q.front() << '\n'; // q의 맨 앞 값 출력
			}
		}
		
		else if(order == "back"){ // back 명령어
			if(q.empty()){ // q가 비어있으면
				cout << "-1\n"; // -1 출력
			}
			else{
				cout << q.back() << '\n'; // q의 맨 뒷 값 출력
			}
		}
	}
	
	return 0;
}
