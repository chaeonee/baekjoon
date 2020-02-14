#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	
	sort(arr,arr+3); // 정렬하면 가장 큰 수를 마지막에 배치할 수 있고, 같은 수의 개수 셀 때, 바로 뒤에 존재하는 수와 비교하면됨
	
	int eq = 1, num;
	for(int i = 0; i < 3; i++){ // 같은 수가 몇 개 존재하는지 세기, 같은 수가 있다면 어떤 수가 같은지 세기
		if(arr[i] == arr[i+1]){
			eq += 1; // 같은 수 몇 개인지 저장
			num = arr[i]; // 같은 수 저장
		}
	}
	
	if(eq == 3){
		cout << 10000+num*1000;
	}
	else if(eq == 2){
		cout << 1000+num*100;
	}
	else{
		cout << arr[2]*100;
	}
	
	return 0;
}