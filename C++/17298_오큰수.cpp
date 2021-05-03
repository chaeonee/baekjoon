#include <iostream>
#include <stack>
using namespace std;

int main() {
	int n;
	stack<int> s;
	
	cin >> n;
	
	int num[n];
	for(int i = 0; i < n; i++){
		cin >> num[i];
	}
	
	s.push(num[n-1]);
	num[n-1] = -1;
	
	for(int i = n-2; i >= 0; i--){
		while(!s.empty()){
			if(s.top() <= num[i]){
				s.pop();
			}
			else{
				break;
			}
		}
		
		if(!s.empty()){
			int tmp = s.top();
			s.push(num[i]);
			num[i] = tmp;
		}
		else{
			s.push(num[i]);
			num[i] = -1;
		}
	}
	
	for(int i = 0; i < n-1; i++){
		cout << num[i] << " ";
	}
	cout << num[n-1] << endl;
	
	return 0;
}
