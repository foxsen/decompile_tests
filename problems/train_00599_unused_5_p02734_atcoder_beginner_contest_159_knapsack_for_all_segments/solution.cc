#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll mod=998244353;
int n,s;
ll dp[3005],ans;

int main()
{
    scanf("%d%d",&n,&s);
    for(int i=1,x;i<=n;i++)
    {
        scanf("%d",&x);
        dp[0]++;
        for(int j=s;j>=x;j--)
            dp[j]=(dp[j]+dp[j-x])%mod;
        ans=(ans+dp[s])%mod;
    }
    printf("%lld",ans);
    return 0;
}