#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

void getSeries(int N, int M, vector<int> num, int d, vector<int> series, bool *visit){
  if(d == M){
    for(int i = 0; i < series.size(); i++){
      cout << series[i] << " ";
    }
    cout << '\n';
    return;
  }

  int pre_num = -1;
  for(int i = 0; i < N; i++){
    if(pre_num == num[i] || visit[i]){
      continue;
    }
    visit[i] = true;
    series.push_back(num[i]);
    getSeries(N,M,num,d+1,series,visit);
    pre_num = num[i];
    visit[i] = false;
    series.pop_back();
  }
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> num(N);
  for(int i = 0; i < N; i++){
    cin >> num[i];
  }
  sort(num.begin(),num.end());
  
  vector<int> series;
  bool *visit = new bool[N];
  memset(visit,false,N);
  getSeries(N,M,num,0,series,visit);
}
