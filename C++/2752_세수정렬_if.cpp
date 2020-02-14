#include <iostream>
using namespace std;

// 숫자가 3개 뿐이기 때문에 if문으로 정렬
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    
    if(a <= b && a <= c){ // 가장 첫 번째 수와 나머지 비교하여 가장 작은 수라고 판단되면 출력
        cout << a <<  " ";
        if(b <= c){ // 첫 번째 수가 가장 작은수라면 나머지 두 수를 비교하여 더 작은 수 먼저 출력
                cout << b << " " << c;
            }
            else{
                cout << c << " " << b;
            }
    }
    else{ // 첫 번째 수가 가장 작은 수가 아니라면 두 번째와 세 번째 수를 비교하여 더 작은 수 출력(그게 가장 작은 수가 될 테니까)
        // 가장 작은 수가 결정되면, 첫 번째 수와 나머지 수를 비교하여 작은 순서대로 출력
        if(b <= c){
            cout << b << " ";
            if(a <= c){
                cout << a << " " << c;
            }
            else{
                cout << c << " " << a;
            }
        }
        else{
            cout << c << " ";
            if(a <= b){
                cout << a << " " << b;
            }
            else{
                cout << b << " " << a;
            }
        }
    }
    
    return 0;
}
