#include <iostream>
using namespace std;

void Union(int *parent, int a, int b);
int Find(int *parent, int a);

int main() {
	int N, M;
	cin >> N >> M;
	
	int *parent = new int[N];
	for(int i = 0; i < N; i++){
		parent[i] = i; // 부모 노드를 자기 자신으로 모두 초기화
	}
	
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			int link;
			cin >> link;
			if(link == 0){ // i와 j가 연결되어 있지 않다면 아무것도 수행하지 않음
				continue;
			}
			Union(parent,i,j); // i와 j가 연결되어 있다면, 두 도시를 하나의 집합으로 합침
		}
	}
	
	int city, p_city;
	cin >> city;
	p_city = Find(parent, city-1); // 첫 번째 주어진 도시의 root로 초기화
	M--;
	while(M-- > 0){
		cin >> city; // 가고자하는 도시를 입력받은 후
		int tmp = Find(parent, city-1); // 현재 도시의 root(어떤 집합에 속하는지)를 구함
		
		if(tmp != p_city){ // 현재 도시가 속한 집합과 기준 도시가 속한 집합이 같은 집합이 아니라면(root가 다르다면)
			cout << "NO\n"; // NO 출력 후
			return 0; // 종료
		}
	}
	
	cout << "YES\n"; // while문 안의 if에 걸리지 않았으므로 여행지 모두 같은 집합에 속함 -> YES 출력
	
	return 0;
}

void Union(int *parent, int a, int b){ // 도시 a와 b를 하나의 집합으로 결합
	a = Find(parent, a);
	b = Find(parent, b); // a와 b의 root 구한 후
	
	if(a == b){
		return;
	}
	
	parent[a] = b; // 두 도시를 하나로 연결(a의 부모를 b로 설정)
}

int Find(int *parent, int a){ // 도시 a가 어떤 집합에 속하는지 root를 구하는 함수
	a = parent[a];
	while(a != parent[a]){ // 해당 노드가 root일 때까지 반복문 수행
		a = parent[a]; // root가 아니라면 부모 노드로 이동
	}
	
	return a; // 최종 root return
}
