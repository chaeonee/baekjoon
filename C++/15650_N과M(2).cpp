#include <iostream>
#include <vector>
using namespace std;

void dfs(int start, int N, int M, int* v, vector<int> &r);

int main() {
	int N, M;
	cin >> N >> M;
	
	vector<int> result;
	int *visit = new int[N];
	for(int i = 0; i < N; i++){
		visit[i] = 0;
	}
	
	dfs(0, N, M, visit, result);
	
	return 0;
}

void dfs(int start, int N, int M, int* v, vector<int> &r){
	if(r.size() == M){
		vector<int>::iterator iter;
		for(iter = r.begin(); iter != r.end(); iter++){
			cout << *iter << " ";
		}
		cout << "\n";
		return;
	}
	for(int i = start; i < N; i++){
		if(v[i] == 0){
			r.push_back(i+1);
			v[i] = 1;
			dfs(i, N, M, v, r);
			v[i] = 0;
			r.pop_back();
		}
	}
}
