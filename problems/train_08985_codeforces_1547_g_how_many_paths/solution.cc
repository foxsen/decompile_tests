#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 10, M = N * 2;
typedef long long ll;
typedef pair<ll, ll> pii;
#define endl '\n'
// 1 到当前点：
// 0：没有路
// 1：一条路
// 2：多条路
// -1：无线条路
// 与1号点在同一强连通分量中的点：-1
// 搜一遍，每个点最多两边
int n, m, t;
int h[N], ne[M], e[M], idx;
void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int dfn[N], low[N], timestamp;
stack<int> s;
bool in_s[N], st[N];
int scc_cnt;
int a[N];
void tarjan(int u) {
    dfn[u] = low[u] = ++timestamp;
    s.push(u); in_s[u] = 1;
    for (int i = h[u]; ~i; i = ne[i]) {
        int v = e[i];
        if (u == v)a[v] = -1; //自己连自己 自环
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (in_s[v])low[u] = min(low[u], dfn[v]);
    }
    if (dfn[u] == low[u]) {
        if (s.top() != u) { //找强连通块
            ++scc_cnt;
            int v;
            do {
                v = s.top(); s.pop();
                in_s[v] = 0;
                a[v] = -1;
            } while (v != u);
        }
        else {
            in_s[s.top()] = 0; s.pop();
        }
    }
}

void init(){
    while (!s.empty()) s.pop();
    for(int i = 1; i <= n + 5; i++){
        timestamp = scc_cnt = dfn[i] = low[i] = st[i] = a[i] = 0;
        h[i] = -1;
    }
}
void cal(int u, int k){
    if (k == -1) a[u] = -1;
    if (a[u] == -1) return;
    a[u] = min(a[u] + k, 2);
}
void dfs1(int x){
    if(st[x]) return;
    st[x] = 1;
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        cal(j, a[x]);
        dfs1(j);
    }
}
void dfs2(int x){
    for(int i = h[x]; ~i; i = ne[i]){
        int j = e[i];
        if(a[j] == 1){
            a[j] = 2;
            dfs2(j);
        }
    }
}
int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n>>m;
        init();
        for(int i = 1; i <= m; i++){
            int a, b; cin>>a>>b;
            add(a, b);
        }
        tarjan(1);
       // for(int i = 1; i <= n; i++) cout<<a[i]<<" ";
        cal(1, 1);
        for (int i = 1; i <= n; i++)
            if (a[i] == -1) dfs1(i);
        dfs1(1);
        for(int i = 1; i <= n; i++)
            if(a[i] == 2) dfs2(i);
        for(int i = 1; i <= n; i++) cout<<a[i]<<" ";
        cout<<endl;
    }
    return 0;
}