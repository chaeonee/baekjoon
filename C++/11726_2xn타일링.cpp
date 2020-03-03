#include <iostream>
using namespace std;

int main() {
	int N;
	cin >> N;
	
  // dp 또는 재귀로 풀 수 있음 f(n) = f(n-1)+f(n-2)
	int arr[N];
	arr[0] = 1;
    if(N >= 2){
	    arr[1] = 2;
	    for(int n = 2; n < N; n++){
		    arr[n] = (arr[n-1] + arr[n-2])%10007;
	    }
    }
	
	cout << arr[N-1];
	
	return 0;
}
