#include <bits/stdc++.h>
#define rep(i, a, n) for(int i = a; i < n; i++)
#define repb(i, a, b) for(int i = a; i >= b; i--)
#define all(a) a.begin(), a.end()
#define o(a) cout << a << endl
#define int long long
#define fi first
#define se second
using namespace std;
typedef pair<int, int> P;

const int MAX_V = 100010;
int V;
vector<int> G[MAX_V];
vector<int> rG[MAX_V];
vector<int> vs;
bool used[MAX_V];
int cmp[MAX_V];

void add_edge(int from, int to){
    G[from]. push_back(to);
    rG[to]. push_back(from);
}

void dfs(int v){
    used[v] = true;
    for(int i = 0; i < G[v].size(); i++){
        if(!used[G[v][i]]) dfs(G[v][i]);
    }
    vs. push_back(v);
}

void rdfs(int v, int k){
    used[v] = true;
    cmp[v] = k;
    for(int i = 0; i < rG[v].size(); i++){
        if(!used[rG[v][i]]) rdfs(rG[v][i], k);
    }
}

int scc(){
    memset(used, 0, sizeof(used));
    vs.clear();
    for(int v = 0; v < V; v++){
        if(!used[v]) dfs(v);
    }
    memset(used, 0, sizeof(used));
    int k = 0;
    for(int i = vs.size() - 1; i >= 0; i--){
        if(!used[vs[i]]) rdfs(vs[i], k++);
    }
    return k;
}

signed main(){
    int E;
    cin >> V >> E;
    rep(i, 0, E){
        int s, t;
        cin >> s >> t;
        add_edge(s, t);
    }
    scc();
    int q;
    cin >> q;
    rep(i, 0, q){
        int s, t;
        cin >> s >> t;
        cout << (cmp[s] == cmp[t] ? 1 : 0) << endl;
    }
}