#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void getSeries(int N, int M, vector<int> num, int s, int d, vector<int> series){
	if(d == M){
		for(int i = 0; i < M; i++){
			cout << series[i] << ' ';
		}
		cout << '\n';
		return;
	}
	
	int pre_num = -1;
	for(int i = s; i < N; i++){
		if(num[i] == pre_num){
			continue;
		}
		pre_num = num[i];
		
		series.push_back(num[i]);
		getSeries(N,M,num,i+1,d+1,series);
		series.pop_back();
	}
}

int main() {
	int N, M;
	cin >> N >> M;
	
	vector<int> num(N);
	for(int i = 0; i < N; i++){
		cin >> num[i];
	}
	sort(num.begin(),num.end());
	
	vector<int> series;
	getSeries(N,M,num,0,0,series);
	
	return 0;
}
