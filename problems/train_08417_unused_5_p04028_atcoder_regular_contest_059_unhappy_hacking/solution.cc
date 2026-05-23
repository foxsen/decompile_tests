#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod = 1e9+7;
#define MAXN 5000
LL ksm(LL p, LL q)
{
    LL ret = 1LL;
    while(q != 0){
        if (q & 1) 
			ret = ret * p % mod;
        p = p * p % mod;
        q >>= 1;
    }
    return ret;
}
LL dp[MAXN+5][MAXN+5];
int main()
{
	LL N, len;
	string p;
	cin>>N>>p;
	len = p.size();
	dp[0][0] = 1;
	for(int i=0; i<=MAXN; i++)
	{
		for(int j=0; j<=i; j++)
		{
			dp[i+1][j+1] = (dp[i][j] * 2 % mod + dp[i+1][j+1]) % mod;
			dp[i+1][j-1>0?j-1:0] = (dp[i][j] % mod + dp[i+1][j-1>0?j-1:0] % mod) % mod;
		}
	}
	LL ans = ksm(ksm(2, len), (mod - 2)) * dp[N][len] % mod;
	printf("%lld", ans);
}