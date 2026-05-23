#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 5003;
const ll MOD = 1e9+7;
ll fac[5010], fnv[5010];
ll D[5010][5010];
int ni[5010], sz[5010];
int n;
vector<int> lis[5010];

int idfs(int here, int p) {
    sz[here] = 1;
    for (int &there : lis[here]) {
        if (there==p) continue;
        sz[here] += idfs(there,here);
    }
    return sz[here];
}

int cdfs(int here, int p) {
    for (int &there :lis[here]) {
        if (there==p) continue;
        if (sz[there]>n/2) return cdfs(there,here);
    }
    return here;
}

ll power(ll a, ll n) {
    if (!n) return 1;
    ll t = power(a,n/2);
    return t*t%MOD*((n&1)?a:1)%MOD;
}

void init() {
    int i;
    fac[0] = 1;
    for (i=1;i<MAXN;i++) fac[i]=fac[i-1]*i%MOD;
    for (i=0;i<MAXN;i++) fnv[i]=power(fac[i],MOD-2);
}

ll calc(int p) {
    int i, j, k, s = ni[0];
    for (i=0;i<=ni[0];i++) D[0][i] = fnv[ni[0]-i]*fnv[ni[0]-i]%MOD*fnv[i]%MOD;
    for (i=1;i<p;i++) {
        s += ni[i];
        for (j=0;j<=s;j++) {
            D[i][j] = 0;
            for (k=0;k<=min(j,ni[i]);k++) D[i][j] += D[i-1][j-k]*fnv[ni[i]-k]%MOD*fnv[ni[i]-k]%MOD*fnv[k]%MOD;
            D[i][j]%=MOD;
        }
    }
    int q = 1;
    ll res = 0, val = 1;
    for (i=0;i<p;i++) val = val*fac[ni[i]]%MOD*fac[ni[i]]%MOD;
    for (i=0;i<=s;i++,q=-q) {
        res = (res+q*D[p-1][i]*fac[s-i]%MOD)%MOD;
    }
    return (res*val%MOD+MOD)%MOD;
}

int main() {
    scanf("%d",&n);
    int i;

    init();
    for (i=0;i<n-1;i++){
        int a, b;
        scanf("%d%d",&a,&b);--a;--b;
        lis[a].push_back(b);lis[b].push_back(a);
    }
    idfs(0,-1);
    int cen = cdfs(0,-1);
    idfs(cen,-1);
    if (n%2==0) {
        bool flag = 0;
        for (int &there : lis[cen]) {
            if (sz[there]==n/2) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            printf("%lld\n",fac[n/2]*fac[n/2]%MOD);
            return 0;
        }
    }
    int p = 0;
    for (int &there : lis[cen]) ni[p++] = sz[there];
    ni[p++] = 1;
    printf("%lld\n",(calc(p-1)+calc(p))%MOD);

    return 0;
}
