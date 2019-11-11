#include <iostream>
using namespace std;

int getNum(int con);

int main() {
	int isSelf[10001] = {0,}; // 셀프 넘버인지 아닌지를 담을 배열(0: 셀프 넘버, 1: 셀프 넘버 아님)

	for(int i = 1; i < 10001; i++){ // 1부터 10000까지 셀프 넘버인지 체크
		int num = getNum(i);
		if(num < 10001){ // getNum의 결과가 구하고자 하는 셀프 넘버의 범위 내에 있으면
			isSelf[num] = 1; // 셀프 넘버 아님
		}
		
		if(isSelf[i] == 0){ // 셀프 넘버 일 때, 출력
			cout << i << "\n";
		}
	}
	return 0;
}

int getNum(int con){ //생성자가 주어지면 생성자로부터 만들어지는 수 return
	int num = con;
	
	while(con != 0){
		num += con % 10;
		con /= 10;
	} // 생성자 + 생성자의 각 자리수
	
	return num;
}
