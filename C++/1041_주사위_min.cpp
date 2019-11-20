#include <iostream>
using namespace std;

int getMin2(int dice[]);
int getMin3(int dice[]);

int main() {
	long long int N;
	cin >> N;
	
	int dice[6];
	int min = 10000;
	for(int i = 0; i < 6; i++){
		cin >> dice[i];
		if(min > dice[i]){
			min = dice[i];
		}
	}
	
	long long int result = 0;
	if(N != 1){
		long long int n1, n2, n3;
		n1 = (N-2)*(5*N-6);
		n2 = 4*(2*N-3);
		n3 = 4;
		
		//1개: 최솟값
		result += min*n1;
		//2개: 합이 최소인 것
		result += getMin2(dice)*n2;
		//3개: 3개의 합이 최소인 것(마주보는 것 중에 작은 것만 고름)
		result += getMin3(dice)*n3;
	}
	else{
		int max = -1;
		for(int i = 0; i < 6; i++){
			result += dice[i];
			if(max < dice[i]){
				max = dice[i];
			}
		}
		result -= max;
	}
	
	cout << result;
	
	return 0;
}

int getMin2(int dice[]){
	int min = 10000;
	for(int i = 0; i < 6; i++){
		for(int j = i+1; j < 6; j++){
			if(i+j == 5){
				continue;
			}
			int tmp = dice[i]+dice[j];
			if(min > tmp){
				min = tmp;
			}
		}
	}
	
	return min;
}

int getMin3(int dice[]){
	int min = 0;
	for(int i = 0; i < 3; i++){
		if(dice[i] >= dice[5-i]){
			min += dice[5-i];
		}
		else{
			min += dice[i];
		}
	}
	return min;
}