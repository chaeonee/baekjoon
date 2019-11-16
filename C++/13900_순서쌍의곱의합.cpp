#include <iostream>
using namespace std;

// 2중 루프를 이용해서 계산하면 시간초과
int main() {
    int N;
    cin >> N;
    
    int *num = new int[N];
    long long int sum = 0;
    for(int i = 0; i < N; i++){
        cin >> num[i];
        sum += num[i];
    }
    
    long long int result = 0;
    for(int i = 0; i < N; i++){
        sum -= num[i];
        result += num[i] * sum;
    }
    
    cout << result;
    
    return 0;
}
