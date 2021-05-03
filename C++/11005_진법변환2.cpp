#include <iostream>
using namespace std;

int main() {
	char num[36] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	int cal[100] = {0,};
	
	int B;
	long long int N;
	cin >> N >> B;
	
	int digit = 0;
	while(N != 0){
		cal[digit] = N % B;
		N /= B;
		digit++;
	}
	
	for(int i = digit-1; i >= 0; i--){
		cout << num[cal[i]];
	}
	return 0;
}
