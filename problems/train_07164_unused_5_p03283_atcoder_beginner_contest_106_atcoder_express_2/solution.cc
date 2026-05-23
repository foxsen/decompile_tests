#include <bits/stdc++.h>
#define ll long long
using namespace std;

int N, M, Q;
int Dp[510][510];

int main(){
	int i, j, x, y;
	scanf("%d %d %d", &N, &M, &Q);
	for(i = 0; i < M; i++){
		scanf("%d %d", &x, &y);
		Dp[x][y]++;
	}
	for(i = 1; i <= N; i++){
		for(j = 0; j + i <= N + 1; j++) Dp[j][j + i] += Dp[j][j + i - 1] + Dp[j + 1][j + i] - Dp[j + 1][j + i - 1];
	}
	for(i = 0; i < Q; i++){
		scanf("%d %d", &x, &y);
		printf("%d\n", Dp[x][y]);
	}
	return 0;
}