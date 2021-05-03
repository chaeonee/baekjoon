#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	for(int i = 0; i < 2*N; i++){
		for(int j = 0; j < N; j++){
			if(i%2 == 0){
				if(j%2 == 0){
					cout << "*";
				}
				else{
					cout << " ";
				}
			}
			else{
				if(j%2 == 0){
					cout << " ";
				}
				else{
					cout << "*";
				}
			}
		}
		cout << '\n';
	}
	
	return 0;
}
