#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef long long LL;
const int SIZEN = 10000010;
const LL mod = 998244353;
LL pw[SIZEN];
LL fac[SIZEN];
LL inv[SIZEN];
int N;
LL qpow(LL x,LL len){
    LL ret = 1;
    for(;len;len>>=1){
        if(len & 1)ret = ret * x % mod;
        x = x * x % mod;
    }
    return ret;
}
LL C(int n,int m){
    if(n < m)return 0;
    return fac[n] * inv[m] % mod * inv[n-m] % mod;
}
int main(){
    scanf("%d",&N);
    for(int i = 0;i <= N;i++)pw[i] = (i == 0?1:pw[i-1] * 2 % mod);
    for(int i = 0;i <= N;i++)fac[i] = (i == 0?1:fac[i-1] * i % mod);
    for(int i = N;i >= 0;i--)inv[i] = (i == N?qpow(fac[N],mod-2):inv[i+1] * (i+1) % mod);
    LL ans = qpow(3,N);
    for(int i = N/2+1;i <= N;i++){
        // printf("C(%d,%d) = %lld\n",N,i,C(N,i));
        ans = (ans - 2*C(N,i) * pw[N-i] % mod) % mod;
    }
    printf("%lld",(ans+mod)%mod);
    return 0;
}