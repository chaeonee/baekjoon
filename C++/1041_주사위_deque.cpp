#include <iostream>
#include <deque>
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
		//3개: 3개의 합이 최소인 것
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
	int min = 10000;
	//주사위 굴리기 위한 초기 값
	deque<int> d1, d2;
	d1.push_back(dice[0]);
	d1.push_back(dice[2]);
	d1.push_back(dice[5]);
	d1.push_back(dice[3]);
	
	d2.push_back(dice[0]);
	d2.push_back(dice[1]);
	d2.push_back(dice[5]);
	d2.push_back(dice[4]);
	
	for(int i = 0; i < 4; i++){
		deque<int> dq;
		dq.push_back(d2[1]);
		dq.push_back(d1[1]);
		dq.push_back(d2[3]);
		dq.push_back(d1[3]);
		
		for(int j = 0; j < 4; j++){
			int tmp = d1[0];
			tmp += dq[0]+dq[1];
			if(min > tmp){
				min = tmp;
			}
			
			tmp = dq.front();
			dq.pop_front();
			dq.push_back(tmp);
		}
		
		int tmp = d1.front();
		d1.push_back(tmp);
		d1.pop_front();
		d2[0] = d1[0];
		d2[2] = d1[2];
	}
	
	for(int i = 0; i < 3; i++){
		int tmp = d2.front();
		d2.push_back(tmp);
		d2.pop_front();
		d1[0] = d2[0];
		d1[2] = d2[2];
		
		deque<int> dq;
		dq.push_back(d2[1]);
		dq.push_back(d1[1]);
		dq.push_back(d2[3]);
		dq.push_back(d1[3]);
		
		for(int j = 0; j < 4; j++){
			int tmp = d1[0];
			tmp += dq[0]+dq[1];
			if(min > tmp){
				min = tmp;
			}
		}
	}
	
	return min;
}