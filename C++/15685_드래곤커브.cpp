#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

struct Dir{
	int r, c;
};

//Dir direction[4] = {{1,0},{0,-1},{-1,0},{0,1}};
void getCurve(vector<Dir> &dragon, int s, int g);
int main() {
	int N;
	cin >> N;
	
	vector<Dir> dragon;
	int max = 0;
	for(int i = 0; i < N; i++){
		vector<Dir> tmp_dragon;
		int x, y, d, g;
		cin >> x >> y >> d >> g;
	
		Dir dir;
		dir.r = x;
		dir.c = y;
		tmp_dragon.push_back(dir);
		
		if(d == 0){
			dir.r += 1;
		}
		else if(d == 1){
			dir.c -= 1;
		}
		else if(d == 2){
			dir.r -= 1;
		}
		else{
			dir.c += 1;
		}
		tmp_dragon.push_back(dir);
		
		getCurve(tmp_dragon, 0, g);
		
		while(!tmp_dragon.empty()){
			Dir tmp_d = tmp_dragon.back();
			tmp_dragon.pop_back();
			dragon.push_back(tmp_d);
			
			if(max < abs(tmp_d.r)){
				max = abs(tmp_d.r);
			}
			if(max < abs(tmp_d.c)){
				max = abs(tmp_d.c);
			}
		}
	}
	
	int **sq = new int*[2*max+1];
	for(int i = 0; i < 2*max+1; i++){
		sq[i] = new int[2*max+1];
		memset(sq[i],0,sizeof(int)*(2*max+1));
	}
	/*for(int i = 0; i < dragon.size();i++){
		cout << dragon[i].r << " " << dragon[i].c << endl;
	}*/
	while(!dragon.empty()){
		Dir dir = dragon.back();
		dragon.pop_back();
		
		if(sq[dir.r+max][dir.c+max] == 0){
			sq[dir.r+max][dir.c+max] = 1;
		}
	}
	
	int num = 0;
	for(int i = 0; i < 2*max+1;i++){
		for(int j = 0; j < 2*max+1;j++){
			//cout << sq[i][j] << " ";
			if(sq[i][j] == 1 && i+1 < 2*max+1 && j+1 < 2*max+1){
				if(sq[i][j+1] == 1 && sq[i+1][j] == 1 && sq[i+1][j+1] == 1){
					num++;
				}
			}
		}//cout << endl;
	}
	
	cout << num;
	return 0;
}

void getCurve(vector<Dir> &dragon, int s, int g){
	if(s == g){
		return;
	}
	
	Dir end = dragon.back();
	for(int i = dragon.size()-2; i >= 0; i--){
		Dir dir;
		dir.r = end.r+(end.c - dragon[i].c);
		dir.c = end.c-(end.r - dragon[i].r);
		dragon.push_back(dir);
	}
	getCurve(dragon,s+1,g);
}
