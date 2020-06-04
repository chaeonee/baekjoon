#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Days{
	int start, end;
}; // 꽃이 피는 날과 지는 날 저장

bool cmp(Days &a, Days &b){
	if(a.start == b.start){
		return a.end < b.end;
	}
	return a.start < b.start;
} // 정렬을 위한 함수 시작일이 같으면 끝나는날의 오름차순으로 아니라면 시작하는 날의 오름차순으로 정렬

int main() {
	int N;
	cin >> N;
	
	vector<Days> v;
	for(int i = 0; i < N; i++){
		int sm, sd, em, ed;
		cin >> sm >> sd >> em >> ed;
		v.push_back({sm*100+sd,em*100+ed});
	} // 월에 곱하기 100을하고 일을 더하니까 월+일 형태의 숫자가 됐다..... 힘들게 python 풀고 찾아보니까 나온 참신한방법... 비교하기 굉장히 편함 나중 날짜일수록 숫자가 큼
	
	sort(v.begin(),v.end(),cmp); // 위의 기준으로 벡터 정렬
	
	int idx = 0, cnt = 0, day = 301; // 시작 인덱스, 선택한 꽃의 수, 기준 날짜(3월 1일)
	while(idx < N && day <= 1130){ // 모든 꽃을 확인했거나 11월 30일 이후에 꽃이 지는 경우 선택하면 while문 탈출
		bool flag = false; // 현재 기준 이전에 피는 꽃이 있는지 여부를 확인하는 flag
		int tmp_day = 0; // 현재 기준 이전에 개화하면서 가장 늦게 지는 꽃 찾기 위한 변수(현재까지 본 꽃 중에 가장 늦게 지는 꽃의 끝 날짜)
		for(int i = idx; i < N; i++){ // idx 이후의 꽃만 보면됨(이전의 꽃은 선택한 꽃보다 일찍 지는 꽃만 있을 것이기 때문)
			int s = v[i].start, e = v[i].end;
      
			if(s == e){ // 시작 날짜와 끝나는 날짜가 같으면 그냥 핀적 없는 꽃과 같으므로 확인할 필요 없음
				continue;
			}
			
			if(s > day){ // 개화하는 날짜가 기준 날짜보다 나중인 경우에 break(이후에 있는 꽃들도 기준 날짜보다 나중에 필 것이기 때문)
				break;
			}
			
			if(e > tmp_day){ // 꽃이 지는 날짜가 지금까지 가장 늦게 지는 날짜보다 더 늦다면
				flag = true; // flag를 true로(기준에 적합한 꽃이 존재한다는 것이기 때문)
				idx = i+1; // 다음 루프에는 현재 꽃 이후의 꽃부터 보면 됨
				tmp_day = e; // 가장 늦게 지는 날짜 갱신
			}
		}
		
		if(flag){ // 기준에 적합한 꽃이 있다면
			cnt++; // 그 꽃 선택
			day = tmp_day; // 기준 갱신(현재 꽃 다음으로 연결)
		}
		else{ // 기준에 적합한 꽃이 없으면 중간에 정원에 꽃이 없는 시기가 있다는 뜻
			break; // 문제의 조건에 위배되므로 탐색 종료
		}
	}
	
	if(day > 1130){ // 꽃이 지는 날이 11월 30일 이후라면
		cout << cnt; // 선택한 꽃의 수 출력
	}
	else{ // 아니라면
		cout << 0; // 0 
	}
	
	return 0;
}
