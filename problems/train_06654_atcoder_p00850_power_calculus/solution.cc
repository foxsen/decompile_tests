#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <cfloat>
#include <stack>
#include <queue>
#include <vector>
#include <string>
#include <iostream>
#include <set>
#include <map>
#include <time.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define NUM 8192

int dp[NUM+1];


void dfs(int current,int array[15],int depth){

	if(depth == 13)return;

	for(int i = 0; i <= depth; i++){
		if(current+array[i] > NUM)continue;

		if(dp[current+array[i]] >= depth+1){
			dp[current+array[i]] = depth+1;
			int next_array[15];
			for(int k = 0; k <= depth; k++)next_array[k] = array[k];
			next_array[depth+1] = current+array[i];
			dfs(current+array[i],next_array,depth+1);
		}
	}

	for(int i = 0; i <= depth; i++){
		if(current-array[i] <= 0)continue;

		if(dp[current-array[i]] >= depth+1){
			dp[current-array[i]] = depth+1;
			int next_array[15];
			for(int k = 0; k <= depth; k++)next_array[k] = array[k];
			next_array[depth+1] = current-array[i];
			dfs(current-array[i],next_array,depth+1);
		}
	}
}


int main(){

	dp[0] = 0;
	dp[1] = 0;
	for(int i = 2; i <= NUM; i++)dp[i] = BIG_NUM;

	int first_array[15];
	first_array[0] = 1;

	dfs(1,first_array,0);

	int N;

	while(true){
		scanf("%d",&N);
		if(N == 0)break;

		printf("%d\n",dp[N]);
	}

	return 0;
}

