//little jump frog txdy
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#define rep(i,l,r) for(int i=(l);i<=(r);++i)
#define per(i,r,l) for(int i=(r);i>=(l);--i)
#define pb push_back
using namespace std;
const int N=2e5+10,P=1e9+7;
vector<int> F[N],G[N];
int vis[N],s[N],tp,x,y,n,u,v,fac[N],inv[N],ifac[N],sz[N],dsy[N],tot;
void dfs(int u,int fa=0){
    vis[u]=1;s[++tp]=u;tot+=G[u].size();
    for(int v:G[u]) if(v^fa){
        if(!vis[v]) dfs(v,u);
        else x=u,y=v;
    }
}
void DFS(int u,int fa){for(int v:G[u]) if((v^fa)&&(v^x)) DFS(v,u),dsy[v]=u;}
void cmz(int u){
    sz[u]=1;
    for(int v:F[u]) cmz(v),sz[u]+=sz[v];
}
int QFJ(){
    dsy[x]=y;DFS(x,y);
    rep(i,1,tp) vis[s[i]]=0,F[s[i]].clear();
    rep(i,1,tp) for(int v:G[s[i]]) if(v<dsy[s[i]]) vis[v]=1,F[s[i]].pb(v);
    rep(i,1,tp) if(!vis[s[i]]) cmz(s[i]);
    int ans=fac[tp];
    rep(i,1,tp) ans=1ll*ans*inv[sz[s[i]]]%P;
    rep(i,1,tp) vis[s[i]]=1;
    return ans;
}
int main(){
    scanf("%d",&n);
    rep(i,1,(n<<1)) scanf("%d%d",&u,&v),G[u].pb(v+n),G[v+n].pb(u);
    fac[0]=inv[1]=ifac[0]=1;
    rep(i,2,(n<<1)) inv[i]=1ll*(P-P/i)*inv[P%i]%P;
    rep(i,1,(n<<1)) fac[i]=1ll*fac[i-1]*i%P,ifac[i]=1ll*ifac[i-1]*inv[i]%P;
    int qfj=0,ans=fac[n<<1];
    rep(i,1,(n<<1)) if(!vis[i]){
        tp=tot=0,dfs(i);if(tot^(tp<<1)) return puts("0"),0;
        qfj=QFJ(),swap(x,y),qfj=(qfj+QFJ())%P,ans=1ll*ans*ifac[tp]%P*qfj%P;
    }
    printf("%d\n",ans);
    return 0;
}