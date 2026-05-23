#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
typedef long long int ll;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000001
using namespace std;

enum DIR{
	None,
	Right,
	Left,
};

DIR dir_array[3] = {None,Right,Left};

struct Info{
	void set(ll arg_loc,DIR arg_dir){
		loc = arg_loc;
		dir = arg_dir;
	}
	ll loc,moved_loc;
	DIR dir;
	bool is_Moved;
};

int main(){

	int N,Q,tmp_dir;
	ll T,tmp_loc;
	scanf("%d %lld %d",&N,&T,&Q);

	int* most_left_to_left_Peron = new int[N+2];
	int* most_right_to_right_Person = new int[N+2];
	Info* info = (Info*)malloc(sizeof(Info)*(N+1));

	for(int i = 1; i <= N; i++){
		scanf("%lld %d",&tmp_loc,&tmp_dir);
		info[i].set(tmp_loc,dir_array[tmp_dir]);
		info[i].is_Moved = false;
	}

	most_left_to_left_Peron[N+1] = BIG_NUM;
	for(int i = N; i >= 1; i--){
		if(info[i].dir == Left){
			most_left_to_left_Peron[i] = i;
		}else{
			most_left_to_left_Peron[i] = most_left_to_left_Peron[i+1];
		}
	}

	most_right_to_right_Person[0] = 0;
	for(int i = 1; i <= N; i++){
		if(info[i].dir == Right){
			most_right_to_right_Person[i] = i;
		}else{
			most_right_to_right_Person[i] = most_right_to_right_Person[i-1];
		}
	}

	int tmp;

	for(int i = 1; i <= N; i++){
		if(info[i].dir == Right && most_left_to_left_Peron[i] != BIG_NUM && most_right_to_right_Person[most_left_to_left_Peron[i]] == i){
			tmp = most_left_to_left_Peron[i];
			if(info[tmp].loc-info[i].loc > 2*T){
				info[tmp].moved_loc = info[tmp].loc - T;
				info[i].moved_loc = info[i].loc + T;
			}else{
				info[tmp].moved_loc = (info[tmp].loc + info[i].loc)/2;
				info[i].moved_loc = (info[tmp].loc + info[i].loc)/2;
			}
			info[tmp].is_Moved = true;
			info[i].is_Moved = true;
		}
	}

	for(int i = 1; i <= N; i++){
		if(info[i].dir == Right && info[i].is_Moved == false){
			if(most_left_to_left_Peron[i] == BIG_NUM){
				info[i].moved_loc = info[i].loc + T;
			}else{
				tmp = most_left_to_left_Peron[i];
				if(info[tmp].moved_loc > info[i].loc+T){
					info[i].moved_loc = info[i].loc + T;
				}else{
					info[i].moved_loc = info[tmp].moved_loc;
				}
			}
		}else if(info[i].dir == Left  && info[i].is_Moved == false){
			if(most_right_to_right_Person[i] == 0){
				info[i].moved_loc = info[i].loc-T;
			}else{
				tmp = most_right_to_right_Person[i];
				if(info[tmp].moved_loc < info[i].loc-T){
					info[i].moved_loc = info[i].loc-T;
				}else{
					info[i].moved_loc = info[tmp].moved_loc;
				}
			}
		}
	}

	int person;

	for(int i = 0; i < Q; i++){
		scanf("%d",&person);

		printf("%lld\n",info[person].moved_loc);
	}

	return 0;
}