#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#define INF 0x3f3f3f3f
#define lowbit(x) x & -x
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const int N=2e5+5;
vector<int>G[N];
int dep[N];
int ans,maxdepv=0;
void dfs(int u,int fa){
    dep[u]=1;
    int minn=2e5+5;
    int maxx=0;
    for(int v:G[u]){
        if(v==fa)
            continue;
        dfs(v,u);
        minn=min(dep[v],minn);
        maxx=max(maxx,dep[v]);
    }
    if(minn==2e5+5)
        return ;
    if(u!=1 && G[u].size()>2){
        ans=max(ans,maxx+1);
    }
    if(u==1){
        maxdepv=maxx;
    }
    dep[u]+=minn;
}

int main(){
#ifdef Mizp
    freopen("in.txt","r",stdin);
#endif
    int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        ans=0;
        maxdepv=0;
        for(int i=1;i<=n;i++)
            G[i].clear();
        for(int i=1;i<n;i++){
            int u,v;
            cin>>u>>v;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        dfs(1,0);
        if(G[1].size()>1){
            int flag=0;
            for(int i: G[1]){
                if(maxdepv==dep[i]){
                    flag++;
                }else{
                    ans=max(ans,dep[i]+1);
                }
            }
            if(flag==1){
                ans=max(ans,maxdepv);
            }else{
                ans=max(ans,maxdepv+1);
            }
            cout<<ans<<'\n';
        }
        else
            cout<<max(ans,dep[1]-1)<<'\n';
    }
    return 0;
}