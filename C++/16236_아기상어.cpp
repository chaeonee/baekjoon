#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct Fish{
	int r, c, size, eat=0, time=0;
};

void findFish(int N, Fish &shark, int** area, bool** visit, int fish_num[]);
void eatFish(int &num, int N, Fish &shark, vector<Fish> &fish, int **area, bool **visit, int fish_num[]);

bool cmp(Fish a, Fish b){
	if(a.r == b.r){
		return a.c < b.c;
	}
	
	return a.r < b.r;
}

int main() {
	int N;
	cin >> N;
	
	int **area = new int*[N];
	bool **visit = new bool*[N];
	for(int i = 0; i < N; i++){
		area[i] = new int[N];
		visit[i] = new bool[N];
		memset(visit[i],false,sizeof(bool)*N);
	}
	
	Fish shark;
	int fish_num[6] = {0,};
	for(int i = 0; i < N; i++){
		for(int j = 0; j < N; j++){
			cin >> area[i][j];
			
			if(area[i][j] == 9){
				area[i][j] = 0;
				
				shark.r = i;
				shark.c = j;
				shark.size = 2;
			}
			else if(area[i][j] != 0 && area[i][j] != 9){
				fish_num[area[i][j]-1]++;
			}
		}
	}
	
	findFish(N, shark, area, visit, fish_num);
	
	cout << shark.time;
	
	return 0;
}

void findFish(int N, Fish &shark, int** area, bool** visit, int fish_num[]){
	vector<Fish> fish;
	fish.push_back(shark);
    visit[shark.r][shark.c] = true;
	
	int num = fish_num[0];
	while(!fish.empty() && num > 0){
		vector<Fish> tmp;
		
		for(int i = 0; i < fish.size(); i++){
			if(fish[i].r-1 >= 0){
				if(area[fish[i].r-1][fish[i].c] <= shark.size && visit[fish[i].r-1][fish[i].c] == false){
					visit[fish[i].r-1][fish[i].c] = true;
                    
                    Fish f;
					f.r = fish[i].r-1;
					f.c = fish[i].c;
					f.size = area[fish[i].r-1][fish[i].c];
					f.time = fish[i].time+1;
					tmp.push_back(f);
				}
			}
			
			if(fish[i].c-1 >= 0){
				if(area[fish[i].r][fish[i].c-1] <= shark.size && visit[fish[i].r][fish[i].c-1] == false){
					visit[fish[i].r][fish[i].c-1] = true;
                    
                    Fish f;
					f.r = fish[i].r;
					f.c = fish[i].c-1;
					f.size = area[fish[i].r][fish[i].c-1];
					f.time = fish[i].time+1;
					tmp.push_back(f);
				}
			}
			
			if(fish[i].c+1 < N){
				if(area[fish[i].r][fish[i].c+1] <= shark.size && visit[fish[i].r][fish[i].c+1] == false){
					visit[fish[i].r][fish[i].c+1] = true;
                    
                    Fish f;
					f.r = fish[i].r;
					f.c = fish[i].c+1;
					f.size = area[fish[i].r][fish[i].c+1];
					f.time = fish[i].time+1;
					tmp.push_back(f);
				}
			}
			
			if(fish[i].r+1 < N){
				if(area[fish[i].r+1][fish[i].c] <= shark.size && visit[fish[i].r+1][fish[i].c] == false){
					visit[fish[i].r+1][fish[i].c] = true;
                    
                    Fish f;
					f.r = fish[i].r+1;
					f.c = fish[i].c;
					f.size = area[fish[i].r+1][fish[i].c];
					f.time = fish[i].time+1;
					tmp.push_back(f);
				}
			}
		}
		
		swap(fish,tmp);
		sort(fish.begin(),fish.end(),cmp);
		
		eatFish(num, N, shark, fish, area, visit, fish_num);
	}
}

void eatFish(int &num, int N, Fish &shark, vector<Fish> &fish, int **area, bool **visit, int fish_num[]){
	for(int i = 0; i < fish.size(); i++){
		if(area[fish[i].r][fish[i].c] < shark.size && area[fish[i].r][fish[i].c] != 0){
			shark.r = fish[i].r;
			shark.c = fish[i].c;
			shark.time = fish[i].time;
			shark.eat++;
			
			num--;
			if(shark.eat == shark.size && shark.size < 7){
				shark.size++;
				shark.eat = 0;
				num += fish_num[shark.size-2];
			}
			
			fish.clear();
			fish.push_back(shark);
			area[shark.r][shark.c] = 0;
			
			for(int i = 0; i < N; i++){
				memset(visit[i],false,sizeof(bool)*N);
			}
            visit[shark.r][shark.c] = true;
			
			break;
		}
	}
}
