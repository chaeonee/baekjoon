#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Con{ //국가 정보를 담을 struct
	int num, g, s, c; // num: 국가 번호, g: 금메달 수, s: 은메달 수, c: 동메달 수
};

// 국가를 정렬하기 위한 기준
bool cmp(Con a, Con b){
	if(a.g == b.g){ // 금메달의 수가 같다면 은메달의 수 비교
		if(a.s == b.s){ // 은메달의 수가 같다면 동메달의 수 비교
			if(a.c == b.c){
				return a.num < b.num; // 모두 같으면 국가 번호로 정렬(안그래도 )
			}
			
			return a.c > b.c; // 동메달의 수가 많은 국가를 앞쪽으로(금,은메달의 수 같을 때)
		}
		
		return a.s > b.s; // 은메달의 수가 많은 국가를 앞쪽으로(금메달의 수 같을 때)
	}
	return a.g > b.g; // 금메달의 수가 많은 국가를 앞쪽으로(기본)
}

int main() {
	int N, K;
	cin >> N >> K;
	
	vector<Con> v;
	for(int i = 0; i < N; i++){
		int n, g, s, c;
		cin >> n >> g >> s >> c;
		v.push_back({n,g,s,c});
	}
	
	sort(v.begin(),v.end(),cmp); // cmp를 기준으로 벡터 정렬
	
	if(v[0].num == K){ // 이 경우 1등
		cout << 1;
		return 0;
	}
	
	int l = v.size();
	int now = 1, next = 1; // now: 현재 등수, next: 그 다음 등수를 위한 변수(현재 등수와 더해서 사용)
	for(int i = 1; i < l; i++){
		if(v[i].g == v[i-1].g && v[i].s == v[i-1].s && v[i].c == v[i-1].c){ // 모두 같으면 현재 등수는 변화 없고 다음 등수에만 영향 미침
			next++; // 같은 개수 만큼 등수 건너 뛰기 위함
		}
		else{ // 같지 않으면
			now += next; // 등수 갱신
			next = 1; // next는 1로 다시 갱
		}
		
		if(v[i].num == K){ // 구하고자 하는 국가의 번호를 만나면
			cout << now; // 등수 출력 후 break
			break;
		}
	}
	
	return 0;
}