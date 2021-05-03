#include <iostream>
#include <vector>
using namespace std;

void dfs(int N, int M, vector<int> &r);

int main() {
	int N, M;
	cin >> N >> M;
	
	vector<int> result;
	dfs(N, M, result);
	
	return 0;
}

void dfs(int N, int M, vector<int> &r){
	if(r.size() == M){
		vector<int>::iterator iter;
		for(iter = r.begin(); iter != r.end(); iter++){
			cout << *iter << " ";
		}
		cout << "\n";
		return;
	}
	for(int i = 0; i < N; i++){
		r.push_back(i+1);
		dfs(N, M, r);
		r.pop_back();
	}
}
