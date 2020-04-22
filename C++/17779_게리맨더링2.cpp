#include <iostream>
#include <algorithm>
using namespace std;

struct Pos{
	int x, y;
};

void Division(int N, int **A, Pos std, int &sub, int sum);
int getPopulation(int **A, int N, int d1, int d2, Pos std, int c);

int main() {
	int N;
	cin >> N;
	
	int **A = new int*[N];
	for(int i = 0; i < N; i++){
		A[i] = new int[N];
	}
	
	int sum = 0;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> A[i][j];
			sum += A[i][j];
		}
	}
	
	int sub = 50000;
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			Pos std = {i,j}; // 기준점을 변화시키면서 선거구 나눠야 함(주어진 기준점 없기 때문에 모든 좌표값이 기준점될 수 있음)
			Division(N,A,std,sub,sum);
		}
	}
	
	cout << sub;
	
	return 0;
}

void Division(int N, int **A, Pos std, int &sub, int sum){ //
	for(int d1 = 1; d1 < N; d1++){
		for(int d2 = 1; d2 < N; d2++){ // d1과 d2도 주어진 값 없기 때문에 하나씩 구해봐야 함
			if(std.x+d1+d2 >= N || std.y-d1 < 0 || std.y+d2 >= N){ // 설정한 d1과 d2가 x,y를 범위에서 벗어나게 한다면(잘못된 범위) 더이상 진행하지 않음
				continue;
			}
			
			int p_min = 50000, p_max = -50000, t_sum = sum;
			for(int i = 0; i < 4; i++){ // 1~4번째 선거구의 인구수 구하는 작업
				int tmp = getPopulation(A,N,d1,d2,std,i);
				t_sum -= tmp; // 5번째 선거구의 인구수를 구하기 위한 작업(5번째 선거구의 인구수는 전체 인구수에서 나머지 선거구의 인구수를 뺀 값이기 때문)
				p_min = min(p_min,tmp);
				p_max = max(p_max,tmp); // 각 구의 최대&최소 인구수 구하기 위함
			}
			p_min = min(p_min,t_sum);
			p_max = max(p_max,t_sum); // 5번째 선거구의 인구수가 최대 또는 최소 값인지 확인
			
			sub = min(sub,p_max-p_min); // 최소값 갱신
		}
	}
}

int getPopulation(int **A, int N, int d1, int d2, Pos std, int c){ // 현재 선거구의 인구수를 구하는 작업
	int sum = 0, d; // sum: 현재 선거구의 인구의 합
	switch(c){ // c: 몇 번째 선거구인지 표시, 선거구를 구할 때는 각 선거구 행과 열의 범위를 가지는 직사각형에서 5번째 선거구의 경계를 기준으로 하는 값들을 빼 주면 됨(문제에 주어진 조건들을 이용)
		case 0: // 첫 번째 선거구
		for(int i = 0; i < std.x+d1; i++){
			for(int j = 0; j <= std.y; j++){
				sum += A[i][j];
			}
		}
		
		d = 0;
		while(std.x+d < std.x+d1){
			for(int i = std.y-d; i <= std.y; i++){
				sum -= A[std.x+d][i];
			}
			d++;
		}
		break;
		
		case 1: // 두 번째 선거구
		for(int i = 0; i <= std.x+d2; i++){
			for(int j = std.y+1; j < N; j++){
				sum += A[i][j];
			}
		}
		
		d = 0;
		while(std.x+d <= std.x+d2){
			for(int i = std.y+d; i > std.y; i--){
				sum -= A[std.x+d][i];
			}
			d++;
		}
		break;
		
		case 2: // 세 번째 선거구
		for(int i = std.x+d1; i < N; i++){
			for(int j = 0; j < std.y-d1+d2; j++){
				sum += A[i][j];
			}
		}
		
		d = 0;
		while(std.x+d1+d < N){
			for(int i = std.y-d1+d; i < std.y-d1+d2; i++){
				sum -= A[std.x+d1+d][i];
			}
			d++;
		}
		break;
		
		case 3: // 네 
		for(int i = std.x+d2+1; i < N; i++){
			for(int j = std.y-d1+d2; j < N; j++){
				sum += A[i][j];
			}
		}
		
		d = 1;
		while(std.x+d2+d < N){
			for(int i = std.y+d2-d; i >= std.y-d1+d2; i--){
				sum -= A[std.x+d2+d][i];
			}
			d++;
		}
		break;
	}
	
	return sum;
}
