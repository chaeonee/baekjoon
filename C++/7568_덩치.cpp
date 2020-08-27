#include <iostream>
#include <algorithm>
using namespace std;

struct Person{
	int w, h;
}; // 사람의 무게와 키

int main() {
	int N;
	cin >> N;
	
	Person person[N]; // 사람들의 무게와 키를 저장하기 위한 배열
	int rank[N]; // 사람들의 등수를 저장할 배열
	for(int i = 0; i < N; i++){
		rank[i] = 1; // 등수는 모두 1등으로 초기화(나보다 덩치 큰 사람이 없을 때의 등수)
		cin >> person[i].w >> person[i].h;
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){ // 모든 사람들을 보면서
			if(person[i].w < person[j].w && person[i].h < person[j].h){ // 나보다 덩치 큰 사람이 있다면
				rank[i]++; // 등수 1씩 증가 시켜서 등수 내려 줌
			}
		}
	}
	
	for(int i = 0; i < N; i++){
		cout << rank[i] << " ";
	} // 덩치 등수 출력
	
	return 0;
}
