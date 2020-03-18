#include <iostream>
#include <cstring>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int problem;
	cin >> problem;
	
	int tmp_n = N;
	long long int num = 1;
	for(int i = 2; i <= N; i++){
		num *= i;
	}
	if(problem == 1){
		long long int k;
		cin >> k;
		
		bool visit[N];
		memset(visit,false,N);
		for(int i = 0; i < N-1; i++){
			num /= tmp_n;
			tmp_n--;
			
			long long int a = k/num;
			if(k%num == 0){
				a--;
				for(int i = 0; i < N; i++){
					if(visit[i] == false){	
						if(a == 0){
							cout << i+1 << " ";
							k -= num*((k/num)-1);
							visit[i] = true;
							break;
						}
						a--;
					}
				}
			}
			else{
				for(int i = 0; i < N; i++){
					if(visit[i] == false){
						if(a == 0){
							cout << i+1 << " ";
							k -= num*((k/num));
							visit[i] = true;
							break;
						}
						a--;
					}
				}
			}
		}
		
		for(int i = 0; i < N; i++){
			if(visit[i] == false){
				cout << i+1 << " ";
				break;
			}
		}
	}
	else{
		long long int result = 1;
		
		bool visit[N];
		memset(visit,false,N);
		for(int i = N; i > 0; i--){
			int n;
			cin >> n;
			visit[n-1] = true;
			
			int tmp = 0;
			for(int j = 0; j < N; j++){
				if(j == n-1){
					break;
				}
				if(visit[j] == false){
					tmp++;
				}
			}
			
			num /= i;
			result += tmp*num;
		}
		
		cout << result;
	}
	
	return 0;
}
