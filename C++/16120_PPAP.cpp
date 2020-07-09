#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	vector<char> v; // stack 대신 사용할 vector
	char PPAP[4] = {'P','A','P','P'}; // 뒤부터 PPAP가 맞는지 확인하기 위해 거꾸로 넣어 놓기
	
	int s_len = s.size();
	for(int i = 0; i < s_len; i++){
		if(s[i] == 'P'){ // P라면 그냥 삽입
			v.push_back(s[i]);
			continue;
		}
		
		// A라면 PPAP 문자열이 만들어지는 지 확인
		bool flag = true; // PPAP 문자가 만들어지는지 여부를 나타내는 flag
		
		v.push_back(s[i++]); // A 삽입
        if(i >= s_len){ // 범위 초과 여부 예외처리
            break;
        }
		v.push_back(s[i]); // A 다음 문자열 삽입(PPAP가 되려면 A 다음에 P가 삽입되기를 기대)
		for(int j = 0; j < 4; j++){ // PPAP가 되는지 확인
			if(PPAP[j] == v.back()){
				v.pop_back(); // 확인해서 일치하면 pop
			}
			else{ // 일치하지 않으면 PPAP 문자열이 아님 -> 더 이상 볼 필요 없음
				flag = false;
				break;
			}
		}
		if(!flag){
			break;
		}
		
		v.push_back('P'); // PPAP가 만들어졌으면 PPAP를 모두 빼고 P 넣기
	}
	
	if(v.size() == 1 && v[0] == 'P'){ // stack이 P 1개로만 이루어져 있다면
		cout << "PPAP"; // PPAP 문자열
	}
	else{ // 아니라면
		cout << "NP"; // PPAP 문자열이 아님
	}
	
	return 0;
}
