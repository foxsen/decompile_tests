#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int n,m;
int p[maxn], head[maxn];
int mn[maxn], bad[maxn];
deque<int> all;
int get(int x,int y) {
    if(p[x]<p[y]) return x;
    return y;
}
int findhead(int x) {
    if(x==head[x]) return x;
    return head[x] = findhead(head[x]);
}
int main() {
    int i,x,y;
    long long ans = 0;
    scanf("%d%d",&n,&m);
    for(i=1;i<=n;i++) scanf("%d",&p[i]);
    for(i=1;i<=n;i++) head[i] = i;
    for(i=0;i<m;i++) {
        scanf("%d%d",&x,&y);
        head[findhead(x+1)] = findhead(y+1);
    }
    p[0] = 2e9;
    for(i=1;i<=n;i++) {
        x = findhead(i);
        mn[x] = get(mn[x], i);
    }
    for(i=1;i<=n;i++) bad[mn[i]] = 1;
    for(i=1;i<=n;i++) if(!bad[i]) all.push_back(p[i]);
    sort(all.begin(),all.end());
    for(i=1;i<=n;i++) if(bad[i]) all.push_front(p[i]);
    if((n-m-1)*2>all.size()) return !printf("Impossible");
    for(i=0;i<(n-m-1)*2;i++) ans += all[i];
    printf("%lld",ans);
}
