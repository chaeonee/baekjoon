#include <iostream>
#include <cmath>
using namespace std;

void hanoi(int N, int s, int m, int e);

int main() {
	int N;
	cin >> N;
	
	cout << (int)pow(2,N)-1 << "\n";
	
	hanoi(N,1,2,3);
	
	return 0;
}

void hanoi(int N, int s, int m, int e){
	if(N == 1){
		cout << s << " " << e << "\n";
		return;
	}
	
	N--;
	hanoi(N,s,e,m);
	cout << s << " " << e << "\n";
	hanoi(N,m,s,e);
}