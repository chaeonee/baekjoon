#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Shortcut{
	int s, e, l;
}; // 시작점, 끝점, 지름길 길이

bool cmp(Shortcut &a, Shortcut &b){
	if(a.e == b.e){
		return a.s < b.s;
	}
	
	return a.e < b.e;
} // 지름길 정렬을 위한 함수 - 끝점을 기준으로 오름차순(끝점이 같다면 시작점 오름차순)

int main() {
	int N, D;
	cin >> N >> D;
	
	vector<Shortcut> shortcut;
	for(int i = 0; i < N; i++){
		int s, e, l;
		cin >> s >> e >> l;
		shortcut.push_back({s,e,l});
	}
	
	sort(shortcut.begin(),shortcut.end(),cmp); // 설정한 기준으로 정렬
	
    int drive[N]; // 현재 지름길을 포함하여 운전한 최소 거리가 담겨있는 배열
    for(int i = 0; i < N; i++){
    	if(shortcut[i].e > D){ // 끝점이 목적지보다 먼 경우
    		drive[i] = D; // 목적지로 초기화
    		continue;
    	}
    	int tmp = min(shortcut[i].e-shortcut[i].s, shortcut[i].l); // 지름길이 더 긴 경우도 존재 -> 지름길과 원래 길의 거리 비교해서 더 짧은 길이만큼 이동
        drive[i] = D-(shortcut[i].e-shortcut[i].s)+tmp; // 거리 계산(현재 지름길만 이동했을 때, 안 이용했을 수도..(지름길이 더 길면)) 
    } // 배열 초기화
    
  int min_dist = drive[0]; // 첫 번째 지름길 사용한 거리로 최소 운전 거리 초기화
	for(int i = 1; i < N; i++){
		if(shortcut[i].e > D){ // 만약 끝점이 도착점보다 더 멀다면
			break; // 뒤에 있는 끝점들도 도착점보다 더 멀 것이기 때문에 루프 탈출
		}
        
		int tmp = min(shortcut[i].e-shortcut[i].s, shortcut[i].l); // 지름길이 더 긴 경우도 존재하기 때문에 지름길과 기존 길 중 더 짧은 길 선택
		for(int j = 0; j < i; j++){ // 이전 지름길들 확인
			if(shortcut[i].s < shortcut[j].e){ // 역주행할 수 없기 때문에 둘의 경로가 겹치면 안됨 -> 현재 길의 시작점보다 이전에 존재하는 길의 끝점이 더 큰 경우
				break; // 이전 길 더 이상 확인할 필요 없음(이 뒤에 있는 길 역시 현재 시작점보다 끝점이 더 클 것이기 때문(정렬했기 때문))
			}
			
      drive[i] = min(drive[i], drive[j]-(shortcut[i].e-shortcut[i].s)+tmp); // 더 짧은 길로 갱신
		}
		min_dist = min(min_dist,drive[i]); // 현재 위치에서의 최단 경로 계산 후, 최단 경로 갱신
	}
    
	cout << min_dist;
	
	return 0;
}
