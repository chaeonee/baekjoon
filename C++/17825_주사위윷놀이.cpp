#include <iostream>
#include <vector>
using namespace std;

struct Node{
	int score; // 해당 노드의 점수
	vector<Node*> n; // 해당 노드 다음에 올 노드 vector(2개일 수도 있어서 vector로)
};

Node *head; // 윷판의 시작점
Node *tail; // 윷판의 도착점

void gameStart(int s, int *dice, vector<Node*> mal, int cur_score, int &max_score);
Node* addNode(int score, Node *cur);

int main() {
	int *dice = new int[10]; // 10개의 주사위 값 저장
	for(int i = 0; i < 10; i++){
		cin >> dice[i];
	}
	
	// 윷판 만들기(linked list 이용)
	for(int i = 0; i <= 40; i += 2){ // 먼저 2~40까지 연결(시작점의 score 값은 0으로 설정)
		tail = addNode(i,tail); // 도착점은 아직 추가하지 않고 score가 40인 부분까지
	}
	
	Node *cur = head;
	while(true){ // 10에서 갈라지는 부분 구현
		if(cur->score == 10){
			break;
		}
		cur = cur->n[0];
	}
	cur = addNode(13,cur);
	cur = addNode(16,cur);
	cur = addNode(19,cur);
	cur = addNode(25,cur); // 10 뒤쪽으로 13, 16, 19, 25 연결
	Node *cur2 = cur; // 25는 가운데 점으로, 계속 연결할 필요가 있기 때문에 따로 저장해 놓기
	
	cur = addNode(30,cur);
	cur = addNode(35,cur); // 25 뒤쪽으로 30,35 연결
	cur->n.push_back(tail); // 35와 도착점 이전에 score가 40인 노드와 연결
	
	cur = head;
	while(true){
		if(cur->score == 20){ // 20에서 갈라지는 부분 구현
			break;
		}
		cur = cur->n[0];
	}
	cur = addNode(22,cur);
	cur = addNode(24,cur); // 20 뒤에 22, 24 연결
	cur->n.push_back(cur2); // 24 뒤에 아까 저장했던 25 연결
	
	cur = head;
	while(true){
		if(cur->score == 30){ // 30에서 갈라지는 부분 구현
			break;
		}
		cur = cur->n[0];
	}
	cur = addNode(28,cur);
	cur = addNode(27,cur);
	cur = addNode(26,cur); // 30 뒤로 28, 27, 26 연결
	cur->n.push_back(cur2); // 26 뒤에 아까 저장했던 25 연결
	tail = addNode(0,tail); // score가 0인 노드로 도착점 설정
	
	vector<Node*> mal; // 4개의 말의 커서를 저장하기 위한 벡터
	for(int i = 0; i < 4; i++){
		mal.push_back(head); // 초기값은 모두 시작점으로 설정
	}
	
	int max_score = 0;
	gameStart(0,dice,mal,0,max_score);
	
	cout << max_score;
	
	return 0;
}

void gameStart(int s, int *dice, vector<Node*> mal, int cur_score, int &max_score){
	if(s == 10){ // 주사위 모두 방문했으면
		if(max_score < cur_score){ // 점수의 최대값 구하기
			max_score = cur_score;
		}
		
		return;
	}
	
	for(int i = 0; i < 4; i++){ // 말 4개 모두 수행해보기
		if(mal[i] == tail){ // 말이 이미 도착점에 있다면 선택할 수 없음
			continue;
		}
		
		Node *tmp = mal[i]; // 말 선택(백트래킹을 위해 저장해 놓음)
		
		int step = dice[s]; // 현재 주사위 값
		if(mal[i]->n.size() == 2){ // 만약 갈라지는 부분이 있으면 원래 길이 아닌 갈라지는 길로 이동해야 함(그것이 벡터의 두번 째 위치에 저장되어 있음)
			mal[i] = mal[i]->n[1]; // 방향 이동 후
			step--; // 주사위 값 1 감소시킴
		}
		
		while(step > 0 && mal[i] != tail){ // 주사위의 값이 0일 때까지 이동하거나 말이 도착점에 도착하기 전까지 이동
			mal[i] = mal[i]->n[0];
			step--;
		}
		
		bool flag = true; // 말의 위치 겹치는지 확인하는 변수
		if(mal[i] != tail){ // 말이 도착점이 경우에는 위치가 동일해도 무방... 아닐 때만 겹치는 위치 있는지 확인
			for(int j = 0; j < 4; j++){
				if(i == j){
					continue;
				}
				
				if(mal[i] == mal[j]){ // 말의 위치 겹치면
					flag = false; // 이동 못하기 때문에 false
					break;
				}
			}
		}
		
		if(flag == true){ // 말의 위치가 겹치지 않아야 이동
			cur_score += mal[i]->score; // 현재 score 더해주기
			gameStart(s+1,dice,mal,cur_score,max_score); // 재귀 수행
			cur_score -= mal[i]->score; // 백트래킹을 위해 // 현재 score 빼주기
		}
		mal[i] = tmp; // 백트래킹..(말 다시 원래 상태로)
	}
}

Node* addNode(int score, Node *cur){ // 커서 뒤쪽으로 노드를 삽입하기 위한 함수
	Node *new_node = new Node; // 노드 생성
	new_node->score = score; // score 값 추가
	
	if(head == NULL){ // 빈 윷판이라면
		head = new_node;
		cur = new_node;
	} // 시작점과 현재 커서가 모두 생성한 노드를 가리키도록
  
	else{ // 아니라면
		cur->n.push_back(new_node);
		cur = new_node;
	} // 현재 커서가 가리키는 노드 뒤에 생성된 노드 추가하고 커서가 현재 생성된 노드를 가리키도록 함
	
	return cur; // 커서의 위치 return
}
