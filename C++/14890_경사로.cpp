#include <iostream>
using namespace std;

int main() {
	int N, L;
	cin >> N >> L;
	
	int **map = new int*[N];
	for(int i = 0; i < N; i++){
		map[i] = new int[N];
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> map[i][j];
		}
	}
	
	int num = 0;
	for(int i = 0; i < N; i++){
		int continuous = 1;
		int j = 1;
		for(j; j < N; j++){
			if(map[i][j] == map[i][j-1]){
				continuous++;
			}
			else if(map[i][j] == map[i][j-1]+1){//뒤가 더 큰 경우
				if(continuous >= L){
					continuous = 1;
				}
				else{
					break;
				}
			}
			else if(map[i][j] == map[i][j-1]-1){//뒤가 더 작은 경우
				int flag = 1;
				for(int k = 0; k < L; k++){
					if(j+k < N){
						if(map[i][j] != map[i][j+k]){
							flag = 0;
						}
					}
					else{
						flag = 0;
						break;
					}
				}
				if(flag == 1){
					j += L-1;
					continuous = 0;
				}
				else{
					break;
				}
			}
			else{
				break;
			}
		}
		if(j == N){
			num++;
		}
	}//행고정
	
	for(int j = 0; j < N; j++){
		int continuous = 1;
		int i = 1;
		for(i; i < N; i++){
			if(map[i][j] == map[i-1][j]){
				continuous++;
			}
			else if(map[i][j] == map[i-1][j]+1){//아래가 더 큰 경우
				if(continuous >= L){
					continuous = 1;
				}
				else{
					break;
				}
			}
			else if(map[i][j] == map[i-1][j]-1){//아래가 더 작은 경우
				int flag = 1;
				for(int k = 0; k < L; k++){
					if(i+k < N){
						if(map[i][j] != map[i+k][j]){
							flag = 0;
						}
					}
					else{
						flag = 0;
						break;
					}
				}
				if(flag == 1){
					i += L-1;
					continuous = 0;
				}
				else{
					break;
				}
			}
			else{
				break;
			}
		}
		if(i == N){
			num++;
		}
	}//열고정
	
	cout << num;
	return 0;
}
