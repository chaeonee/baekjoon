#include <iostream>
#include <vector>
using namespace std;

struct Pos{
	int x, y;
};

int main() {
	int D, K;
	cin >> D >> K;
	
	vector<Pos> v; // 피보나치형의 계수를 갖는 두 수를 계산할 것, v는 두 수의 계수를 담고 있는 벡터
	v.push_back({1,0}); // A
	v.push_back({0,1}); // B
	int d = 2;
	while(true){ // 3일차부터 계산
		if(d == D){ // D일차가 되면 루프를 빠져나감
			break;
		}
		
		Pos p1 = v[d-2];
		Pos p2 = v[d-1];
		v.push_back({p1.x+p2.x,p1.y+p2.y}); // 계수 피보나치 계산
		d++;
	}
	
	int a = v.back().x, b = v.back().y; // A와 B의 최종 계수
	for(int i = 1; i <= K; i++){ // A를 1부터 대입하면서 적절한 수 찾기
		if((K-a*i)%b == 0){ // B를 계산하기 위한 식, A와 B 모두 자연수 -> 나머지가 0이 아니면 안됨(0이면 만족하는 조건 만족)
			cout << i << '\n' << (K-a*i)/b; // A와 B 순서대로 출력 후
			break; // 끝
		}
	}
	
	return 0;
}
