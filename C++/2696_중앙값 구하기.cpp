#include <iostream>
#include <queue>
using namespace std;

int main() {
	int T;
	cin >> T;
	while(T--){
		int M;
		cin >> M; // 주어진 수의 개수
		
		queue<int> mid; // 홀수번째 수일 때마다 중앙 값을 담을 queue
		priority_queue<int,vector<int>,greater<int> > min_heap; // min heap
		priority_queue<int,vector<int>,less<int> > max_heap; // max heap
		for(int i = 0; i < M; i++){
			int n;
			cin >> n; 
			if(min_heap.size() == max_heap.size()){ // min heap의 크기와 max heap의 크기가 같다면,
				max_heap.push(n); // max heap에 push(max heap이 min heap의 크기와 같거나 1 커야하기 때문)
			}
			else{ // min heap의 크기와 max heap의 크기가 같지 않을 경우(max heap의 크기가 1만큼 큰 경우),
				min_heap.push(n); // max heap에 push(min heap과 max heap의 크기는 1이상 차이날 수 없기 때문)
			}
			
			if(!min_heap.empty() && min_heap.top() < max_heap.top()){ // min heap의 root보다 max heap의 root의 값이 더 클 경우
				int tmp = min_heap.top();
				min_heap.pop();
				min_heap.push(max_heap.top());
				max_heap.pop();
				max_heap.push(tmp);
			} // min heap의 root와 max heap의 root 값을 바꿔주어야 함(swap)

			if(i % 2 == 0){ // heap에 추가한 수가 홀수 번째 수일 때,(인덱스가 0부터 시작하기 때문에 인덱스가 짝수여야 홀수 번째 수가 됨)
				mid.push(max_heap.top()); // 중앙 값 추가
			}
		}
		
		int n = 0;
		cout << mid.size() << '\n'; // 출력할 중앙값의 개수
        while(!mid.empty()){ // 중앙 값 출력
            n++;
            if(n > 10){ // 10줄씩 출력해야 하므로 10줄이 넘어갈 때마다 다음 줄로 넘어가도록 함
                n = 1;
                cout << '\n';
            }
			cout << mid.front() << " ";
			mid.pop();
		} cout << '\n';
	}
	
	return 0;
}
