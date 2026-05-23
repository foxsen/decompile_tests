#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>
using namespace std;
typedef long long ll;
const int N = 5005;
const int p = 1e9 + 7;

int n, k, q;
int a[N];
ll ans;
ll num[N], dp[N][N];

int main(){
    scanf("%d%d%d", &n, &k, &q);  ++k;
    for(int i = 1; i <= n; ++i)  scanf("%d", &a[i]);
    for(int i = 1; i <= k; ++i)
        for(int t = 1; t <= n; ++t)
            dp[t][i] = (i == 1 ? 1 : (dp[t - 1][i - 1] + dp[t + 1][i - 1]) % p);
    for(int i = 1; i <= n; ++i){
        for(int t = 1; t <= k; ++t){
            num[i] = (num[i] + dp[i][t] * dp[i][k - t + 1]) % p;
		}
        ans = (ans + a[i] * num[i]) % p;
    }
    //for(int i = 1; i <= k; ++i)  printf("%lld ", dp[2][i]);puts("kk");
    for(int i = 1, id, x; i <= q; ++i){
        scanf("%d%d", &id, &x);
        ans = (ans + 1LL * (x - a[id]) * num[id] % p + p) % p;
        a[id] = x;
        printf("%lld\n", ans);
    }
    return 0;
}