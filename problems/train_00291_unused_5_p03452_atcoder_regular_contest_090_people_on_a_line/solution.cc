#include <bits/stdc++.h>
using namespace std;
const int maxn=112345;
typedef pair<int,int> pii;
int n,m,l,r,x,d[maxn],vis[maxn];
vector<pii> G[maxn];
bool dfs(int u,int dep) {
    vis[u]=1;
    d[u]=dep;
    for (int i=0;i<(int)G[u].size();++i) {
        int v=G[u][i].first,w=G[u][i].second;
        if (vis[v]&&d[u]+w!=d[v]) return false;
        if (!vis[v]&&!dfs(v,dep+w)) return false;
    }
    return true;
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i=0;i<m;++i) {
        scanf("%d%d%d",&l,&r,&x);
        G[l].push_back(pii(r,x));
        G[r].push_back(pii(l,-x));
    }
    for (int i=1;i<=n;++i) if (!vis[i]&&!dfs(i,0))
        return 0*puts("No");
    return 0*puts("Yes");
}
