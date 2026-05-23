#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <ctime>

#define Rep(i, n) for (int i = 1; i <= n; i ++)
#define Rep0(i, n) for (int i = 0; i <= n; i ++)
#define RepG(i, x) for (int i = head[x]; i; i = edge[i].next)
#define v edge[i].to
#define mp(a, b) make_pair(a, b)

using namespace std;

typedef long long LL;
const int N = 4010;
const int mod = 1e9 + 7;
int f[N][N][2], s[N][N];

int main()
{
	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	f[0][0][0] = 1;
	Rep0(i, n) s[0][i] = 1;
	LL ans = 0;
	Rep(i, max(n, m) * 2) {
		Rep0(j, n){
			f[i][j][0] = (f[i - 1][j][0] + f[i - 1][j][1]) % mod;
			if (j){
				if (j - k >= 0) f[i][j][1] = (s[i - 1][j - 1] - s[i - 1][j - k] + mod) % mod;
				else f[i][j][1] = s[i - 1][j - 1];
			}
			s[i][j] = (f[i][j][0] + f[i][j][1]) % mod;
			if (j) s[i][j] = (s[i][j] + s[i][j - 1]) % mod;
		}
		Rep(j, n) if (j % (k - 1) == n % (k - 1) && ((k - 1) * i - j + 1) <= m && ((k - 1) * i - j + 1) % (k - 1) == m % (k - 1)){
			ans = (ans + f[i][j][1]) % mod;}
	}
	printf("%lld\n", ans);
	
	return 0;
}