#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;

#define NUM 81

int N;
int energy[NUM];
bool dp[321][321][NUM];

void func(){

	scanf("%d",&N);

	int sum = 0;
	for(int i = 0; i < N; i++){
		scanf("%d",&energy[i]);
		sum += energy[i];
	}

	if(N <= 2){
		printf("%d\n",energy[N-1]);
		return;
	}

	for(int a = 0; a <= sum; a++){
		for(int b = 0; b <= sum; b++){
			for(int c = 0; c < NUM; c++)dp[a][b][c] = false;
		}
	}

	dp[energy[0]][energy[1]][0] = true;

	int right_value;
	for(int i = 1; i <= N-2; i++){

		right_value = energy[i+1];

		for(int left_value = 0; left_value <= sum; left_value++){
			for(int self_value = 0; self_value <= sum; self_value++){
				if(!dp[left_value][self_value][i-1])continue;

				dp[self_value][right_value][i] = true;
				if(self_value > 0){
					dp[self_value-1][right_value+left_value][i] = true;
				}
			}
		}
	}

	int ans = 0;
	for(int i = 0; i <= sum; i++){
		for(int k = 0; k <= sum; k++){
			if(dp[i][k][N-2]){
				ans = max(ans,k);
			}
		}
	}

	printf("%d\n",ans);
}


int main(){

	int num_case;
	scanf("%d",&num_case);

	for(int loop = 0; loop < num_case; loop++){
		func();
	}

	return 0;
}

