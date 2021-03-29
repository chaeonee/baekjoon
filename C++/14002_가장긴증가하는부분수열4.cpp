#include <iostream>
#include <stack>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int num[N];
	for(int i = 0; i < N; i++){
		cin >> num[i];
	}
	
	int arr[2][N];
	for(int i = 0; i < N; i++){
		arr[0][i] = 1;
		arr[1][i] = -1;
	}
	
	int total_max = 0;
	arr[0][0] = 1;
	for(int i = 0; i < N; i++){
		int max_num = 0;
		for(int j = 0; j < i; j++){
			if(num[j] < num[i] && max_num < arr[0][j]){
				max_num = arr[0][j];
				arr[1][i] = j;
			}
		}
		arr[0][i] += max_num;
		
		if(arr[0][i] > arr[0][total_max]){
			total_max = i;
		}
	}
	
	stack<int> s;
	s.push(total_max);
	
	int idx = total_max;
	while(arr[1][idx] != -1){
		s.push(arr[1][s.top()]);
		idx = s.top();
	}
	
	cout << s.size() << '\n';
	while(!s.empty()){
		cout << num[s.top()] << " ";
		s.pop();
	}
	
	return 0;
}
