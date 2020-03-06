#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int main() {
	int T;
	cin >> T;
	for(int t= 0; t < T; t++){
		int N;
		cin >> N;
		
		int arr[N];
		for(int n = 0; n < N; n++){
			cin >> arr[n];
			arr[n]--; // 인덱스로 접근하기 위해 1부터 시작하는 값을 0부터로 바꿔줌(1씩 줄임으로써)
		}
		
		int cnt = 0; // 팀에 속하는 값 구하기 위함
		bool visit[N]; // 방문했는지 안했는지 표시
		memset(visit,false,sizeof(visit));
		for(int n = 0; n < N; n++){
			visit[n] = true;
			int val = arr[n];
			
			bool flag = false;
			vector<int> v;
			
			if(n == val){ // 자기 자신과 팀이 되기를 원하는 사람들
				flag = true;
			}
			while(val != n && visit[val] == false){
				 v.push_back(val);
				 visit[val] = true;
				 val = arr[val];
				 
				 if(val == n){ // 사이클을 찾았을 때
				 	flag = true;
				 }
			}
			
			if(flag == false){ // 사이클을 발견하지 못했기 때문에 true로 바꿔놨던 노드를 false로
				while(!v.empty()){
					visit[v.back()] = false;
					v.pop_back();
				}
			}
			else{ // 현재 값을 벡터에 저장 안했기 때문에 현재 벡터 크기에 1 더해 주어야 함
				cnt += v.size() + 1;
			}
		}
		
		cout << N-cnt << '\n'; // 팀에 속하지 않으려면 N에서 속하는 수 빼기
	}
	
	return 0;
}
