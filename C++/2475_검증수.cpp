#include <iostream>
using namespace std;

int main() {
	int num = 0, n;
	
	for(int i = 0; i < 5; i++){
		cin >> n;
		num += n*n;
	}
	
	cout << num%10;
	
	return 0;
}
