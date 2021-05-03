#include <iostream>
#include <deque>
using namespace std;

struct Printer{
	int order, num;
};

int main() {
	int N, K;
	cin >> N >> K;
	
	deque<int> dq;
	for(int i = 1; i <= N; i++){
		dq.push_back(i);
	}
	
	cout << '<';
	while(!dq.empty()){
		for(int i = 1; i < K; i++){
			int tmp = dq.front();
			dq.pop_front();
			dq.push_back(tmp);
		}
		
		if(dq.size() == 1){
			cout << dq.front() << '>';
		}
		else{
			cout << dq.front() << ", " ;
		}
		dq.pop_front();
	}
	
	return 0;
}
