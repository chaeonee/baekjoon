#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
	char a[20000], b[20000];
	cin >> a >> b;
	int a_len = strlen(a)-1, b_len = strlen(b)-1;
	
	int total = max(a_len, b_len)+1;
	int num[total] = {0};
	
	int add = 0, cur = total;
	while(cur > 0){
		cur--;
		
		int tmp = 0;
		if(a_len >= 0){
			tmp += (int)a[a_len]-'0';
			a_len--;
		}
		
		if(b_len >= 0){
			tmp += (int)b[b_len]-'0';
			b_len--;
		}
		
		tmp += add;
		num[cur] = tmp % 10;
		add = tmp / 10;
	}
	
	if(add != 0){
		cout << add;
	}
	for(int i = 0; i < total; i++){
		cout << num[i];
	}
	
	return 0;
}
