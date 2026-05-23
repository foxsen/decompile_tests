# include <bits/stdc++.h>
using namespace std;
# define pb push_back
const int N = 100005;
# define MOD 1000000007
typedef long long i64;

int a[N];
i64 A[N];

i64 pow_mod(i64 a, i64 n, i64 mod){
    i64 ret=1, tmp=a%mod;
    while (n) {
        if (n&1) ret=ret*tmp%MOD;
        tmp=tmp*tmp%MOD;
        n>>=1;
    }
    return ret;
}
i64 inv(i64 a, i64 mod){return pow_mod(a,mod-2,mod);}
i64 C(int x, int y) {
    return A[x]*inv(A[y], MOD)%MOD*inv(A[x-y], MOD)%MOD;
}
int main ()
{
    int n, k;
    cin >> n >> k;
    A[0] = 1;
    for (int i = 1; i <= n; ++i) A[i] = A[i-1]*i%MOD;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + n + 1);
    i64 ans = 0;
    for (int i = 1; i <= n-k+1; ++i) {
        ans = (ans - a[i] * C(n-i, k-1) % MOD)%MOD;
    }
    for (int i = n; i >= k; --i) {
        ans = (ans + a[i] * C(i-1, k-1) % MOD)%MOD;
    }
    cout << (ans + MOD)%MOD << endl;
    return 0;
}
