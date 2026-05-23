#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 100000

int N,E;
int height[NUM],boss[NUM];
int in_num[NUM];

int get_boss(int id){
	if(id == boss[id])return id;
	else{
		return boss[id] = get_boss(boss[id]);
	}
}

void unite(int x,int y){

	int x_boss_id = get_boss(x);
	int y_boss_id = get_boss(y);

	if(x_boss_id == y_boss_id)return;

	if(height[x_boss_id] < height[y_boss_id]){

		boss[x_boss_id] = y_boss_id;

	}else{
		boss[y_boss_id] = x_boss_id;
		if(height[x_boss_id] == height[y_boss_id])height[x_boss_id]++;
	}
}

void func(){

	for(int i = 0; i < N; i++){
		boss[i] = i;
		height[i] = 0;
		in_num[i] = 0;
	}

	int from,to;
	for(int loop = 0; loop < E; loop++){
		scanf("%d %d",&from,&to);
		from--;
		to--;
		unite(from,to);
		in_num[from]++;
		in_num[to]++;
	}

	for(int i = 0; i < N; i++){
		if(in_num[i] > 2){
			printf("no\n"); //次数が3以上のノードがあればfalse
			return;
		}
	}

	int group_num = 0;
	for(int i = 0; i < N; i++){
		if(i == get_boss(i))group_num++;
	}

	/*
	 * 1本辺を引く(1回uniteする)毎にbossが1つ減るので、
	 * 辺の両端に重複がなければ、group_numはN-Eになるはず
	 * */
	if(group_num == N-E){
		printf("yes\n");
	}else{
		printf("no\n");
	}
}

int main(){

	while(true){
		scanf("%d %d",&N,&E);
		if(N == 0 && E == 0)break;

		func();
	}

	return 0;
}

