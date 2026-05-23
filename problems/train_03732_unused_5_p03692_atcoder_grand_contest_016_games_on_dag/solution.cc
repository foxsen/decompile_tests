#include<bits/stdc++.h>

using namespace std;

int N, M, msk[15], dp[1 << 15], nrb[1 << 15];
bool ok[1 << 15];
const int mod = 1e9 + 7;
const int long long mod2 = 1LL * mod * mod;
void mul (int &x, int y) {x = (1LL * x * y) % mod;}
void adto (int &x, int y) {x += y; if (x >= mod) x -= mod;}

int main ()
{
//freopen ("input", "r", stdin);
//freopen ("output", "w", stdout);

scanf ("%d %d", &N, &M);
int ans = 1;
while (M --)
{
    int x, y;
    scanf ("%d %d", &x, &y), x --, y --;
    msk[x] |= 1 << y, ans += ans;
    if (ans >= mod) ans -= mod;
}
for (int i=0; i<1 << N; i++)
{
    nrb[i] = nrb[i >> 1] + (i & 1);
    ok[i] = (i & 1) ^ ((i >> 1) & 1) ^ 1;
}
for (int i=0; i<1 << N; i++)
if (ok[i])
{
    dp[i] = 1;
    for (int j=(i - 1) & i; j != 0; j = (j - 1) & i)
    if (ok[j] && ok[j ^ i])
    {
        int cnt = dp[j], j0 = j ^ i;
        for (int k=0; k<N; k++)
            if ((j >> k) & 1)
                mul (cnt, (1 << nrb[msk[k] & j0]) - 1);
        for (int k=0; k<N; k++)
            if ((j0 >> k) & 1)
                mul (cnt, 1 << nrb[msk[k] & j]);
        dp[i] += cnt;
        if (dp[i] >= mod)
            dp[i] -= mod;
    }
}
ans -= dp[(1 << N) - 1];
if (ans < 0) ans += mod;
printf ("%d\n", ans);

return 0;
}
