#include<bits/stdc++.h>
using namespace std;
const int N=305,mod=998244353;
typedef long long ll;
int n,a[N];
ll dp[N][N*N],p[N];
ll qpow(ll a,ll n)
{
    ll ans=1;
    while(n)
    {
        if(n&1) ans=ans*a%mod;
        a=a*a%mod;
        n>>=1;
    }
    return ans;
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]);
    ll ans=qpow(3,n);
    dp[0][0]=1;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=s;j>=0;j--)
        {
            dp[i][j+a[i]]=(dp[i][j+a[i]]+dp[i-1][j])%mod;
            dp[i][j]=(dp[i][j]+dp[i-1][j]*2)%mod;
        }
        s+=a[i];
    }
    for(int i=s/2+s%2;i<=s;i++)
        ans=(ans-3*dp[n][i])%mod;
    memset(dp,0,sizeof(dp));
    s=0;dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=s;j>=0;j--)
        {
            dp[i][j+a[i]]=(dp[i][j+a[i]]+dp[i-1][j])%mod;
            dp[i][j]=(dp[i][j]+dp[i-1][j])%mod;
        }
        s+=a[i];
    }
    if(s%2==0)
        ans=(ans+3*dp[n][s/2])%mod;
    ans=(ans+mod)%mod;
    printf("%lld\n",ans);
}
