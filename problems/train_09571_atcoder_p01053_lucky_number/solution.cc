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


struct Info{
	Info(int arg_start,int arg_end){
		start = arg_start;
		end = arg_end;
	}
	int start,end;
};

ll dp[5001][5001],work[16000];


int main(){

	int N,M,K,Q;

	scanf("%d %d %d %d",&N,&M,&K,&Q);

	int LIMIT = 0;
	while(LIMIT < N)LIMIT += 2*K;

	vector<Info> V;

	for(int day = 0; day <= M; day++){
		for(int num = 0; num <= N-1; num++)dp[day][num] = 0;
	}

	dp[0][0] = 1;

	for(int day = 0; day <= M-1; day++){

		for(int i = 0; i < 2*N; i++)work[i] = 0;

		for(int num = 0; num <= N-1; num++){

			if(dp[day][num] == 0)continue;

			work[num] += dp[day][num];
			work[num+K] -= dp[day][num];
			if(num+LIMIT < 2*N)work[num+LIMIT] -= dp[day][num];
			if(num+LIMIT+K < 2*N)work[num+LIMIT+K] += dp[day][num];
		}

		for(int i = 1; i < 2*N; i++){
			work[i] += work[i-1];
		}

		for(int i = 0; i < 2*N; i++){
			if(i+2*K < 2*N){
				work[i+2*K] += work[i];
			}else{
				break;
			}
		}

		for(int i = 0; i < N; i++){
			dp[day+1][i] = (work[i]+work[i+N])%MOD;
		}
	}

	int a,b,c;

	for(int loop = 0; loop < Q; loop++){
		scanf("%d %d %d",&a,&b,&c);

		c = (c-a+N)%N;

		printf("%lld\n",dp[b][c]%MOD);
	}

	return 0;
}

