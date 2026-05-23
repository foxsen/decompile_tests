#include<bits/stdc++.h>
using namespace std;
const int Mod=998244353;
const int inv2=(Mod+1)>>1;
int n,len,f[310][310],g[310][310],tf[310],tg[310],maxd[310];
int edgenum,vet[610],Next[610],Head[310];
void addedge(int u,int v){
    vet[++edgenum]=v;
    Next[edgenum]=Head[u];
    Head[u]=edgenum;
}
//f[u][d]：u 子树中所有点都被标记，深度最小的黑色点的相对深度为 d
//g[u][d]：u 子树中存在点没被标记，没被标记的点的深度的最小值为 d
void dfs(int u,int fa){
    maxd[u]=0; int v;
    f[u][0]=1; g[u][0]=1;
    tf[u]=0; tg[u]=0;
    
    for (int e=Head[u];e;e=Next[e])
        if (vet[e]!=fa){
            v=vet[e]; dfs(v,u);
            for (int i=0;i<=maxd[u];i++)
                for (int j=0;j<=maxd[v];j++){
                    tf[min(i,j+1)]=(tf[min(i,j+1)]+1ll*f[u][i]*f[v][j])%Mod;
                    if (i+j+1<=len){//两个点能相互覆盖
                        tf[i]=(tf[i]+1ll*f[u][i]*g[v][j])%Mod;
                        tf[j+1]=(tf[j+1]+1ll*g[u][i]*f[v][j])%Mod;
                    } else{//两个点不能相互覆盖
                        tg[j+1]=(tg[j+1]+1ll*f[u][i]*g[v][j])%Mod;
                        tg[i]=(tg[i]+1ll*g[u][i]*f[v][j])%Mod;
                    }
                    tg[max(i,j+1)]=(tg[max(i,j+1)]+1ll*g[u][i]*g[v][j])%Mod;
                }
            maxd[u]=max(maxd[u],maxd[v]+1);
            for (int i=0;i<=maxd[u];i++){
                f[u][i]=tf[i]; g[u][i]=tg[i];
                tf[i]=0; tg[i]=0;
            }
        }
}
int main(){
    ios::sync_with_stdio(false);
    cin>>n; int u,v;
    for (int i=1;i<n;i++){
        cin>>u>>v;
        addedge(u,v); addedge(v,u);
    }
    int res,lst=0,ans=n-1;
    for (int i=1;i<=n;i++){
        len=i; dfs(1,0); res=0;
        for (int j=0;j<=maxd[1];j++) res=(res+f[1][j])%Mod;
        ans=(ans+1ll*(res-lst+Mod)*(i-1))%Mod; lst=res;
    }
    for (int i=1;i<=n;i++) ans=1ll*ans*inv2%Mod;
    cout<<ans<<endl;
    return 0;
}
