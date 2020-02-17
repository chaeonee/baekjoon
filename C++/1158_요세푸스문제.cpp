#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	vector<int> v;
	for(int i = 0; i < N; i++){
		v.push_back(i+1);
	} // vector에 존재하는 사람들 번호 넣기(1~N)
	
	cout << "<";
	int idx = 0;
	while(!v.empty()){ // vector에 아무 사람도 없을 때까
		idx += K-1;
		idx = idx % v.size(); // 삭제할 index를 구함(회전하기 때문에 vetor의 크기로 나눈 나머지 값을 index로 사용해야 함) - vector의 크기 매번 바뀌므로, 매번 크기 구해서 나눠줘야 함
		cout <<  v[idx];
		v.erase(v.begin()+idx); // idx index를 갖는 벡터 삭제
		
		if(!v.empty()){ // vector에 아직 사람이 남아 있으면 쉼표도 출력
			cout << ", ";
		}
	}
	cout << ">";
	
	return 0;
}