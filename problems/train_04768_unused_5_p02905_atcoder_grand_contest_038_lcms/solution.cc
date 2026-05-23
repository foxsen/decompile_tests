#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5,mod=998244353;
int n,inv[N],f[N],u[N],vis[N];
bool vv[N];
int tot,p[N];
ll g[N];
void init()
{
    inv[1]=1;
    for(int i=2;i<N;i++) inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
    u[1]=1;
    for(int i=2;i<N;i++)
    {
        if(!vv[i]) p[++tot]=i,u[i]=-1;
        for(int j=1;j<=tot&&i*p[j]<N;j++)
        {
            vv[i*p[j]]=true;
            if(i%p[j]==0)
            {
                u[i*p[j]]=0;
                break;
            }
            u[i*p[j]]=-u[i];
        }
    }
    for(int i=1;i<N;i++)
        for(int j=i;j<N;j+=i)
        f[j]=(f[j]+u[j/i]*inv[i])%mod;
}
int main()
{
    init();
    scanf("%d",&n);
    ll ans=0;
    while(n--)
    {
        int x;scanf("%d",&x);vis[x]++;
        ans=(ans-x)%mod;
    }
    for(int i=1;i<N;i++)
        for(int j=i;j<N;j+=i)
        g[i]=(g[i]+1ll*vis[j]*j)%mod;
    for(int t=1;t<N;t++)
        ans=(ans+1ll*f[t]*g[t]%mod*g[t]%mod)%mod;
    ans=ans*inv[2]%mod;
    ans=(ans+mod)%mod;
    printf("%lld\n",ans);
}
