#include <iostream>
#include <vector>
using namespace std;

vector<int> getPaper(int**paper, int N, int x, int y);
bool isWhole(int**paper, int N, int x, int y);

int main() {
	int N;
	cin >> N;
	int **paper = new int*[N];
	for(int i = 0; i < N; i++){
		paper[i] = new int[N];
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> paper[i][j];
		}
	}
	
	vector<int> v = getPaper(paper,N,0,0);
	cout << v[0] << '\n' << v[1];
	
	return 0;
}

vector<int> getPaper(int**paper, int N, int x, int y){ // 색종이를 1/4로 잘라가며 확인(재귀) x,y는 시작점
	vector<int> v(2); // 흰색 색종이, 파란색 색종이의 개수가 각각 담겨있는 vector
	if(N == 1 || isWhole(paper,N,x,y)){ // 색종이가 한 칸이거나, 한 색깔로 이루어진 경우
		if(paper[x][y] == 0){ // 흰색인 경우
			v[0] = 1;
		}
		else{ // 파란색인 경우
			v[1] = 1;
		}
		
		return v;
	}
	
	int w, b; // w: 흰색 색종이의 수, b: 파란색 색종이의 수
  	// 1/4로 나눠서 색종이의 수를 재귀적으로 count
	w = getPaper(paper,N/2,x,y)[0] + getPaper(paper,N/2,x+(N/2),y)[0] + getPaper(paper,N/2,x,y+(N/2))[0] + getPaper(paper,N/2,x+(N/2),y+(N/2))[0];
	b = getPaper(paper,N/2,x,y)[1] + getPaper(paper,N/2,x+(N/2),y)[1] + getPaper(paper,N/2,x,y+(N/2))[1] + getPaper(paper,N/2,x+(N/2),y+(N/2))[1];
	v[0] = w;
	v[1] = b;
	
	return v;
}

bool isWhole(int**paper, int N, int x, int y){ // 한 색깔로 이루어진 색종이가 맞는지 확인
	bool flag = true;
	for(int i = x; i < x+N; i++){
		for(int j = y; j < y+N; j++){
			if(paper[x][y] != paper[i][j]){ // 모두 같은 색이 아니라면
				flag = false; // flag를 false로 바꿔줌
				break;
			}
			if(flag == false){
				break;
			}
		}
	}
	
	return flag; // 모두 같은 색으로 이루어져있다면 true, 아니면 false return
}
