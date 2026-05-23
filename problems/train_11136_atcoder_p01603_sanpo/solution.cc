#include <bits/stdc++.h>

using namespace std;
using ll = long long int;

void chmax(ll &A, ll B) { A = max(A, B); }

struct Edge {
    Edge() {}
    Edge(int to_, int tm_, int lim_, int cost_) : to(to_), tm(tm_), lim(lim_), cost(cost_) {}
    int to, tm, lim, cost;
};
using Graph = vector< vector<Edge> >;

ll N, T, dp[650][10010];
int euler[650], dir[650];
Edge euler_edge[650];
int idx = 0;

void dfs(Graph &G, int cur, int par=-1) {
    euler[idx++] = cur;
    for(auto e : G[cur]) {
        int to = e.to;
        if(to == par) continue;
        euler_edge[idx] = e;
        dir[idx] = 0;
        dfs(G, to, cur);
        euler_edge[idx] = e;
        dir[idx] = 1;
        euler[idx++] = cur;
    }
}

int main() {
    cin >> N >> T;

    Graph G(N);
    for(int i=0; i<N-1; i++) {
        int a, b, t, m, v; cin >> a >> b >> t >> m >> v;
        a--; b--;
        G[a].push_back(Edge{b, t, m, v});
        G[b].push_back(Edge{a, t, m, v});
    }
    dfs(G, 0);

    /*
    for(int i=0; i<idx; i++) {
        printf("%d (%d), ", euler[i], euler_edge[i].cost);
    }
    cout << endl;
    */

    vector<int> pre(N, -1);
    fill(dp[0], dp[650], -(1LL << 60));
    // for(int i=0; i<idx; i++) dp[i][0] = 0;
    dp[0][0] = pre[0] = 0;
    for(int i=1; i<idx; i++) {
        int prev_idx = pre[ euler[i] ];

        int tm = euler_edge[i].tm;
        int lim = euler_edge[i].lim;
        int cost = euler_edge[i].cost;

        for(int t=0; t<=T; t++) {
            if(prev_idx >= 0) chmax(dp[i][t], dp[prev_idx][t]);
        }

        if(dir[i] == 1) {
            // 帰り
            for(int t=0; t<=T; t++) {
                chmax(dp[i][t], dp[i-1][t]);
            }
        }
        else {
            // 行き
            if(lim % 2 == 1) {
                ll take_tm = (lim + 1) * tm, take_cost = lim * cost;
                for(int t=take_tm; t<=T; t++) {
                    chmax(dp[i][t], dp[i-1][t - take_tm] + take_cost);
                }
                lim--;
            }

            if(lim == 0) {
                ll take_tm = 2 * tm;
                for(int t=take_tm; t<=T; t++) {
                    chmax(dp[i][t], dp[i-1][t - take_tm]);
                }
            }
            else {
                lim -= 2;
                for(int m=2; lim>0; m*=2) {
                    ll x = min(lim, m); lim -= x;
                    ll take_tm = x * tm, take_cost = x * cost;
                    for(int t=T; t>=take_tm; t--) {
                        chmax(dp[i-1][t], dp[i-1][t - take_tm] + take_cost);
                    }
                }

                ll take_tm = 2 * tm, take_cost = 2 * cost;
                for(int t=take_tm; t<=T; t++) {
                    chmax(dp[i][t], dp[i-1][t - take_tm] + take_cost);
                }
            }
        }

        /*
        for(int t=0; t<=T; t++) {
            if(dp[i][t] < 0) cout << "-INF" << " ";
            else cout << dp[i][t] << " ";
        }
        cout << endl;
        */
        
        pre[ euler[i] ] = i;
    }
    cout << *max_element(dp[idx-1], dp[idx-1] + T + 1) << endl;
    return 0;
}
