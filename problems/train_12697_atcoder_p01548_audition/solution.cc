#include<iostream>
#include<sstream>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<complex>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

int n, m, a[2000], b[2000], c[2000];
double sum[2010], e[3][2010], dp[4][2010];

void calc(double *e, int *v, int bonus){
	rep(i, m + 1){
		double dp[4] = {}, p = 1;
		dp[0] = 1;
		for(int j = 1; j < n; j++){
			int need = (v[0] * i + v[j] - 1) / v[j] - 1;
			double w = need < 0 ? 0 : sum[min(m, need)];
			
			p *= 1 - w;
			for(int k = 2; k >= 0; k--){
				dp[k + 1] += dp[k] * (1 - w);
				dp[k] *= w;
			}
		}
		e[i] = (dp[0] + dp[1] + dp[2]) * bonus - p;
	}
}

int main(){
	cin >> n >> m;
	sum[0] = 1;
	rep(i, m) for(int j = i; j >= 0; j--){
		sum[j + 1] += sum[j] / 3;
		sum[j] *= 2 / 3.0;
	}
	rep(i, m) sum[i + 1] += sum[i];
	
	rep(i, n) cin >> a[i] >> b[i] >> c[i];
	calc(e[0], a, 5);
	calc(e[1], b, 3);
	calc(e[2], c, 2);
	
	rep(i, 4) rep(j, m + 1) dp[i][j] = -INF;
	dp[0][0] = 0;
	rep(i, 3) rep(j, m + 1) if(dp[i][j] > -INF){
		rep(k, m - j + 1) dp[i + 1][j + k] = max(dp[i + 1][j + k], dp[i][j] + e[i][k]);
	}
	printf("%.9f\n", dp[3][m]);
	
	return 0;
}