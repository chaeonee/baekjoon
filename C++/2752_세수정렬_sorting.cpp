#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	
	sort(arr,arr+3); // sort함수를 이용하여 오름차순 정렬 진행
	
	cout << arr[0] << " " << arr[1] << " " << arr[2];
	
	return 0;
}
