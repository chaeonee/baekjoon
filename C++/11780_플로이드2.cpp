#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

void findRoute(int i, int j, vector<int> &v, int** route); // 경로를 찾기 위한 함수

int main() {
   int n, m;
   cin >> n >> m;
   
   int **cost = new int*[n]; // i->j로 가는 최소 cost를 담을 배열
   int **route = new int*[n]; // i->j로 갈 때, 들러야 하는 경로를 담을 배열
   for(int i = 0; i < n; i++){
      cost[i] = new int[n];
      route[i] = new int[n];
      memset(cost[i],0,sizeof(int)*n);
      for(int j = 0; j < n; j++){
         route[i][j] = -1;
      }
   }
   
   for(int k = 0; k < m; k++){
      int i, j, c;
      cin >> i >> j >> c;
      if(cost[i-1][j-1] == 0){ // cost가 0일 때는 방문할 수 없었다는 뜻
         cost[i-1][j-1] = c;
      }
      else{
         cost[i-1][j-1] = min(cost[i-1][j-1], c); // 최소 cost 저장
      }
   }
   
   for(int k = 0; k < n; k++){ i와 j 사이에 k를 들린다면..?
      for(int i = 0; i < n; i++){
         for(int j = 0; j < n; j++){
            if(i == j || cost[i][k] == 0 || cost[k][j] == 0){ // i와 j가 같다면 이동 불가능, i->k, k->j 중에 하나라도 방문할 수 없는 길이라면 수행하지 않음
               continue;
            }
            if(cost[i][j] != 0){ // i->j로 이동하는게 가능했다면 k를 사이에 낀 것과 아닌 것 비교하여 k를 끼지 않은 것의 cost가 더 작다면 아무것도 수행X
               if(cost[i][j] > cost[i][k]+cost[k][j]){ // k를 거쳐서 이동하는 cost가 더 작다면
                  route[i][j] = k; // i->j로 이동할 때의 경로에 k 추가
                  cost[i][j] = cost[i][k]+cost[k][j]; // cost i->k cost + k->j cost로 갱신
               }
            }
            else{ // cost가 0이라면(이전에는 원래 i->j로 이동 불가능했다면
               route[i][j] = k; // i->j사이에 들러야하는 경로 k 추가
               cost[i][j] = cost[i][k]+cost[k][j]; // cost도 i->k cost + k->j cost로 갱신
            }
         }
      }
   }
   
   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         cout << cost[i][j] << ' ';
      }
      cout << '\n';
   } // cost 출력
   
   for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){ // 경로 출력하기 위함
         vector<int> v;
         if(cost[i][j] == 0){ // cost가 0이면 이동 불가능하다는 의미
            cout << 0 << '\n'; // 0 출력
            continue;
         }
         
         v.push_back(i);
         v.push_back(j); // vector에 i와 j추가 후 그 사이에 들어갈 경로 탐색
         findRoute(i,j,v,route);
         
         int v_size = v.size();
         cout << v_size << " ";
         for(int k = 0; k < v_size; k++){ // vector에 추가된 값이 경로 값이므로 vector 순서대로 출력(0부터 시작하도록 했으므로 1씩 더해주어야 함)
         	cout << v[k]+1 << " ";
         }
         cout << '\n';
      }
   }

   return 0;
}

void findRoute(int i, int j, vector<int> &v, int** route){
	if(route[i][j] == -1){ // route가 -1라면 i->j 이동할 때 들러야 하는 곳 없다는 의미
		return;
	}
	
	v.pop_back();
	v.push_back(route[i][j]); // 맨뒤 값을 빼고 i,j사이에 들러야 하는 값(편의상 k) push
	findRoute(i,route[i][j],v,route); // i부터 k까지 경로 찾기 (재귀)
	v.push_back(j); // j 삽입 후
	findRoute(route[i][j],j,v,route); // k부터 j까지 경로 찾기(재귀)
}
