#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void getSeries(int *num, int N, int M, int s, int d, vector<int> series){
  if(d == M){
    for(int i = 0; i < M; i++){
      cout << series[i] << " ";
    }
    cout << '\n';
    return;
  }

  for(int i = s; i < N; i++){
    series.push_back(num[i]);
    getSeries(num,N,M,i,d+1,series);
    series.pop_back();
  }
}

int main() {
  int N, M;
  cin >> N >> M;

  int *num = new int[N];
  for(int i = 0; i < N; i++){
    cin >> num[i];
  }
  sort(num,num+N);

  vector<int> series;
  getSeries(num,N,M,0,0,series);
}
