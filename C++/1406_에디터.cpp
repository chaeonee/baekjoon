#include <iostream>
#include <cstring>
using namespace std;

// double linked list 
struct Node{
	char data;
	Node *prev, *next;
	
	Node(){
		data = '\0';
		prev = NULL;
		next = NULL;
	}
	
	Node(char c){
		data = c;
	}
};

struct DLL{
	Node *head, *tail, *cur;
	
	DLL(){
		head = new Node();
		tail = new Node();
		cur = new Node();
		head->next = tail;
		tail->prev = head;
	}
	
	void insertNode(char c, Node *node){
		Node *n = new Node(c);
		if(node == tail){
			n->prev = node->prev;
			n->next = node;
			node->prev = n;
			n->prev->next = n;
		}
		else{
			n->prev = node->prev->prev;
			n->next = node->prev;
			n->prev->next = n;
			n->next->prev = n;
		}
	}
	
	void moveLeft(){
		if(cur->prev->prev != head){
			cur->prev = cur->prev->prev;
		}
	}
	
	void moveRight(){
		if(cur->prev != tail){
			cur->prev = cur->prev->next;
		}
	}
	
	void removeNode(){
		if(cur->prev->prev != head){
			Node *a = cur->prev->prev;
			cur->prev->prev = a->prev;
			cur->prev->prev->next = a->next;
			delete a;
		}
	}
	
	void printNode(){
		Node *start = head->next;
		while(start != tail){
			cout << start->data;
			start = start->next;
		}
	}
};

int main() {
	char S[100001];
	cin >> S;
	int len = strlen(S);
	
	DLL *d = new DLL();
	for(int i = 0; i < len; i++){
		d->insertNode(S[i],d->tail);
	}
	d->cur->prev = d->tail;
	
	int M;
	cin >> M;
	for(int m = 0; m < M; m++){
		char comm;
		cin >> comm;
		switch(comm){
		case 'L':
			d->moveLeft();
			break;
		case 'D':
			d->moveRight();
			break;
		case 'B':
			d->removeNode();
			break;
		case 'P':
			char c;
			cin >> c;
			d->insertNode(c,d->cur);
			break;
		}
	}
	
	d->printNode();
	return 0;
}
