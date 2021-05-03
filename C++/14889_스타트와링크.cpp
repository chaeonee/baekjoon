#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
using namespace std;

int select(int N, int **stat, vector<int> &selec, int start, int diff);
int compare(int N, int **stat, vector<int> &s);

int main() {
	int N;
	cin >> N;
	
	int **stat = new int*[N];
	for(int i = 0; i < N; i++){
		stat[i] = new int[N];
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> stat[i][j];
		}
	}
	
	vector<int> selec;
	cout << select(N, stat, selec, 0, 1001);
	
	return 0;
}

int select(int N, int **stat, vector<int> &selec, int start, int diff){
	if(selec.size() == N/2){
		int tmp = compare(N, stat, selec);
		if (diff > tmp){
			diff = tmp;
		}
		return diff;
	}
	for(int i = start; i < N; i++){
		selec.push_back(i);
		diff = select(N, stat, selec, i+1, diff);
		selec.pop_back();
	}
	return diff;
}

int compare(int N, int **stat, vector<int> &s){
	int diff = 0;
	
	int *visit = new int[N];
	memset(visit,0,sizeof(int));
	
	for(int i = 0; i < s.size(); i++){
		for(int j = i+1; j < s.size(); j++){
			diff += stat[s[i]][s[j]];
			diff += stat[s[j]][s[i]];
			visit[s[i]] = 1;
			visit[s[j]] = 1;
			
		}
	}
	
	for(int i = 0; i < N; i++){
		for(int j = i+1; j < N; j++){
			if(visit[i] == 0 && visit[j] == 0){
				diff -= stat[i][j];
				diff -= stat[j][i];
			}
		}
	}
	diff = abs(diff);
	return diff;
}
