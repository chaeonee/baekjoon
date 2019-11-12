#include <iostream>
#include <stdio.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    
    int S, S_sum = 0;
    for(int i = 0; i < N; i++){ //한 자리 씩 받아서 더하기
        scanf("%1d",&S);
        S_sum += S;
    }
    
    cout << S_sum;
    
    return 0;
}