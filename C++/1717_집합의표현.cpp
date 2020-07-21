#include <iostream>
using namespace std;

struct Node{
	int p, h;
}; // p: 해당 노드의 부모 값, h: 해당 노드부터 leaf 노드까지의 깊이

void Union(Node *parent, int a, int b);
int Find(Node *parent, int a);

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(0);
    
	int n, m;
	cin >> n >> m;
	
	// 초기화
	Node *parent = new Node[n+1];
	for(int i = 0; i <= n; i++){
		parent[i].p = i; // 노드의 부모 자기 자신으로 설정
		parent[i].h = 1; // 해당 노드의 높이 1로 초기화
	}
	
	while(m-- > 0){
		int oper, a, b;
		cin >> oper >> a >> b;
		
		if(oper == 0){ // 합집합 연산
			Union(parent,a,b);
		}
		else{ // 두 원소가 같은 집합에 속하는지 구하기 위한 연산
			int pa = Find(parent, a); // a가 어떤 집합에 속하는지 구하기(a의 root 구하기)
			int pb = Find(parent, b); // b가 어떤 집합에 속하는지 구하기(b의 root 구하기)
			
			if(pa == pb){ // 두 원소가 같은 집합에 속한다면
				cout << "YES\n";
			}
			else{ // 두 원소가 다른 집합에 속한다면
				cout << "NO\n";
			}
		}
	}
	
	return 0;
}

void Union(Node *parent, int a, int b){ // 두 원소를 하나의 집합으로 만들기 위한 함수(합집합 연산)
	int pa = Find(parent, a); // a의 root 구하기
	int pb = Find(parent, b); // b의 root 구하기
	
	// 높이 비교 하여 더 얕은 tree의 root를 더 깊은 tree의 root 아래에 삽입
	if(parent[pa].h < parent[pb].h){ // b가 속한 부분 집합의 높이가 더 높을 때
		parent[pa].p = parent[pb].p; // a 집합 root의 부모를 b 집합 root로 설정
	}
	else{ // a가 속한 부분 집합의 높이가 같거나 더 높을 때
		parent[pb].p = parent[pa].p; // b 집합 root의 부모를 a 집합 root로 설정
		
		if(parent[pa].h == parent[pb].h){ // 두 집합의 높이가 같을 때
			parent[pa].h++; // 합친 후 집합의 높이 1 증가
		}
	}
}

int Find(Node *parent, int a){
	int p = parent[a].p;
	while(p != parent[p].p){ // 부모 노드와 본인의 값이 같으면 root -> 같을 때까지(root 찾을 때까지) 반복문 수행
		p = parent[p].p;
	}
	
	return p; // 최종 root return
}
