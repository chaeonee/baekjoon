#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Array{
	int value = 0, count = 0;
};

bool cmp(Array a, Array b){
	if(a.count == b.count){
		return a.value < b.value;
	}
	else{
		return a.count < b.count;
	}
}

int main() {
	int r, c, k;
	cin >> r >> c >> k;
	
	int arr[100][100];
	for(int i = 0; i < 100; i++){
		for(int j = 0; j < 100; j++){
			if(i < 3 && j < 3){
				cin >> arr[i][j];
			}
			else{
				arr[i][j] = 0;
			}
		}
	}
	
	int num_r = 3;
	int num_c = 3;
	int time = 0;
	while(time <= 100){
		if(arr[r-1][c-1] == k){
			break;
		}
		if(num_r >= num_c){
			time++;
			int max_num = 0;
			
			for(int i = 0; i < num_r; i++){
				vector<Array> v(100);
				for(int j = 0; j < num_c; j++){
					if(arr[i][j] > 0){
						v[arr[i][j]-1].value = arr[i][j];
						v[arr[i][j]-1].count++;
						arr[i][j] = 0;
					}
				}
				
				sort(v.begin(),v.end(),cmp);
				
				int k = 0;
				for(int j = 0; j < 100; j++){
					if(v[j].count != 0 && k < 100){
						arr[i][k] = v[j].value;
						arr[i][k+1] = v[j].count;
						k += 2;
					}
				}
				if(k > max_num){
					max_num = k;
				}
			}
			
			num_c = max_num;
		}
		else{
			time++;
			int max_num = 0;
			
			for(int j = 0; j < num_c; j++){
				vector<Array> v(100);
				for(int i = 0; i < num_r; i++){
					if(arr[i][j] > 0){
						v[arr[i][j]-1].value = arr[i][j];
						v[arr[i][j]-1].count++;
						arr[i][j] = 0;
					}
				}
				
				sort(v.begin(),v.end(),cmp);
				
				int k = 0;
				for(int i = 0; i < 100; i++){
					if(v[i].count != 0 && k < 100){
						arr[k][j] = v[i].value;
						arr[k+1][j] = v[i].count;
						k += 2;
					}
				}
				if(k > max_num){
					max_num = k;
				}
			}
			
			num_r = max_num;
		}
	}
	//for(int i = 0; i < num_r; i++){for(int j = 0; j < num_c; j++){cout<<arr[i][j]<<" ";}cout << endl;}
	if(time > 100){
		cout << -1;
	}
	else{
		cout << time;
	}
	return 0;
}
