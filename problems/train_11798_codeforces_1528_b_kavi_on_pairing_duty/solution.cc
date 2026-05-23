//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")
#include <bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(),(x).end()

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector < int > VI;
typedef double D;

const int MN = 1000005, inf = 1000000005, mod = 998244353;
const LL INF = 1000000000000000005LL;

LL dp[MN];
LL suma[MN];
int dziel[MN];

int main()
{
	int n;
	scanf("%d", &n);
	dp[1] = 1;
	suma[1] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = i; j <= n; j += i)
			dziel[j]++;
	for(int i = 2; i <= n; ++i)
	{
		dp[i] = (suma[i - 1] + (LL)dziel[i]) % mod;
		suma[i] = (suma[i - 1] + dp[i]) % mod;
	}
	printf("%lld", dp[n]);
}
