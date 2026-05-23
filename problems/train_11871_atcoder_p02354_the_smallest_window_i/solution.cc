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

int main(){

	int N,S;
	scanf("%d %d",&N,&S);

	int* table = new int[N];

	for(int i = 0; i < N; i++)scanf("%d",&table[i]);

	int ans = BIG_NUM,left = 0,right = 0,tmp_sum = 0;

	while(true){
		while(true){
			tmp_sum += table[right];
			if(tmp_sum >= S){
				break;
			}else if(right == N-1){
				break;
			}
			right++;
		}
		if(tmp_sum < S)break;

		while(true){
			ans = min(ans,right-left+1);
			tmp_sum -= table[left];
			left++;
			if(tmp_sum < S){
				break;
			}else if(left == right+1){
				break;
			}
		}
		if(ans == 1 || left == N || right == N-1)break;
		right += 1;
	}

	if(ans == BIG_NUM){
		printf("0\n");
	}else{
		printf("%d\n",ans);
	}

	return 0;
}