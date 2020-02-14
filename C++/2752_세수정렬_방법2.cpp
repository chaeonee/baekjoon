#include <iostream>
using namespace std;

int main(){
	int arr[3];
	cin >> arr[0] >> arr[1] >> arr[2];
	
	for(int i = 0; i < 3; i++){
		for(int j = i+1; j < 3; j++){
			if(arr[j] < arr[i]){
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