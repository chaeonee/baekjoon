#include <iostream>
using namespace std;

int getNum(int con);

int main() {
	int isSelf[10001] = {0,};

	for(int i = 1; i < 10001; i++){
		int num = getNum(i);
		if(num < 10001){
			isSelf[num] = 1;
		}
		
		if(isSelf[i] == 0){
			cout << i << "\n";
		}
	}
	return 0;
}

int getNum(int con){
	int num = con;
	
	while(con != 0){
		num += con % 10;
		con /= 10;
	}
	return num;
}