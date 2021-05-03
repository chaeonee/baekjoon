#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	int *parti = new int[N];
	for(int i = 0; i < N; i++){
		cin >> parti[i];
	}
	
	int super,sub;
	cin >> super >> sub;
	long long int total = 0;
	for(int i = 0; i < N; i++){
		if (parti[i] > 0){
			total++;
			parti[i] -= super;
		}
		
		if(parti[i] > 0){
			total += (int)ceil((float)parti[i]/(float)sub);
		}
	}
	
	cout << total;
	
	return 0;
}
