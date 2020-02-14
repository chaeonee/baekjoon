#include <iostream>
using namespace std;

int main(){
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	
	for(int i = 0; i < 3; i++){
		for(int j = i+1; j < 3; j++){ // 배열을 한 칸씩 이동하며 해당 배열의 값과 뒤쪽에 존재하는 수들을 비교
			if(arr[j] < arr[i]){ // 오름차순 조건에 위배된다면(더 작은 수가 뒤에 있는 경우), 위치 변경
				int tmp;
				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	
	cout << arr[0] << " " << arr[1] << " " << arr[2];
	
	return 0;
}
