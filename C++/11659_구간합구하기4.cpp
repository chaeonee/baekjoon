#include <iostream>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;
	cin >> N >> M;
	
	int sum[N+1] = {0};
	for(int i = 1; i <= N; i++){
		cin >> sum[i];
		sum[i] += sum[i-1];
	}
	
	for(int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		
		cout << sum[b]-sum[a-1] << '\n';
	}
	
	return 0;
}
