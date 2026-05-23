#include <bits/stdc++.h>
#define maxn 3086

using namespace std;

int n, m, k;
int a[maxn][maxn];
int x, y, z;
long long f[maxn][maxn][4];

inline void Max(long long &x, long long y){
	x = max(x, y);
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	while(k--){
		scanf("%d%d%d", &x, &y, &z);
		a[x][y] = z;
	}
	memset(f, -0x3f, sizeof(f));
	f[1][1][0] = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			for(int k = 0;k <= 3;k++){
				Max(f[i][j][k], f[i - 1][j][0]);
				Max(f[i][j][k], f[i - 1][j][1]);
				Max(f[i][j][k], f[i - 1][j][2]);
				Max(f[i][j][k], f[i - 1][j][3]);
				Max(f[i][j][k], f[i][j - 1][k]);
			}
			if(a[i][j]) for(int k = 3;k;k--) Max(f[i][j][k], f[i][j][k - 1] + a[i][j]);
		}
	}
	long long ans = -1e18;
	for(int i = 0;i <= 3;i++) Max(ans, f[n][m][i]);
	printf("%lld", ans);
}
