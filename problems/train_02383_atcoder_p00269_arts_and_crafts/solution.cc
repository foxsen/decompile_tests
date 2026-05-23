#include <cstdio>
#include <queue>
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
const int INF = 1 << 29;
int shift[10];

struct Edge {
    int to, cap, cost, rev;
    Edge(int t, int c, int r) : to(t), cap(c), rev(r) {}
    Edge(int t, int ca, int co, int r) : to(t), cap(ca), cost(co), rev(r) {}
};

using Graph = vector< vector< Edge > >;
struct Flow {
    vector< vector<Edge> > G;
    const int MAXC = 1 << 29;
    int n;
    vector<bool> used;
    vector<int> prevv, preve, dist;
    Flow(int n_) : G(n_), n(n_), used(n_, false), prevv(n_), preve(n_), dist(n_, MAXC) {}

    void add_edge(int from, int to, int cap, int cost) {
        G[from].push_back(Edge(to, cap, cost, G[to].size()));
        G[to  ].push_back(Edge(from, 0, -cost, G[from].size() - 1));
    }

    int dfs(int v, int t, int f) {
        if(v == t) return f;
        used[v] = true;
    }


    // ベルマンフォード法で最小費用流を解く
    // 負辺や負閉路があるときは基本的にこちらのほうが確実
    int mincost_flow(int s, int t, int f) {
        int res = 0;
        int ma = MAXC;
        while(f > 0) {
            fill(dist.begin(), dist.end(), ma);
            dist[s] = 0;
            bool update = true;
            while(update) {
                update = false;
                for(int v = 0; v < n; v++) {
                    if(dist[v] == ma) continue;
                    for(int i=0; i<G[v].size(); i++) {
                        Edge &e = G[v][i];
                        if(e.cap>0 && dist[e.to] > dist[v] + e.cost) {
                            dist[e.to] = dist[v] + e.cost;
                            prevv[e.to] = v;
                            preve[e.to] = i;
                            update = true;
                        }
                    }
                }
            }

            if(dist[t] == ma) return -1;
            int d = f;
            for(int v = t; v != s; v = prevv[v]) {
                d = min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * dist[t];
            for(int v = t; v != s; v = prevv[v]) {
                Edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }    
    
    int fast_mincost_flow(int s, int t, int f) {
        int res = 0, ma = MAXC;
        vector<int> pot(n);
        while(f > 0) {
            using PT = pair<int, int>;
            priority_queue< PT, vector<PT>, greater<PT> > que;
            fill(dist.begin(), dist.end(), ma);

            dist[s] = 0;
            que.push(make_pair(0, s));
            while(que.size()) {
                PT cur = que.top(); que.pop();
                int v = cur.second;
                if(dist[v] < cur.first) continue;
                for(size_t i=0; i<G[v].size(); i++) {
                    Edge &e = G[v][i];
                    if(e.cap > 0 and dist[e.to] > dist[v] + e.cost + pot[v] - pot[e.to]) {
                        dist[e.to] = dist[v] + e.cost + pot[v] - pot[e.to];
                        prevv[e.to] = v;
                        preve[e.to] = i;
                        que.push(make_pair(dist[e.to], e.to));
                    }
                }
            }
            if(dist[t] == ma) {
                return -1;
            }
            for(int v=0; v<n; v++) pot[v] += dist[v];

            int d = f;
            for(int v=t; v!=s; v=prevv[v]) {
                d = min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * pot[t];
            for(int v=t; v!=s; v=prevv[v]) {
                Edge &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }
};

void chmin(int &A, int B) {
    A = min(A, B);
}

int D, K, L, M, N, P;
int c[10][10], r[210][10], t[210][10];

int encode(vector<int> cnt) {
    int sz = cnt.size(), res = 0;
    for(int i=sz-1; i>=0; i--) {
        res = res * 3 + cnt[i];
    }
    return res;
}

int get_digit(int val, int k) {
    val /= shift[k];
    return val % 3;
}

int update_digit(int bit, int k, int val) {
    bit -= get_digit(bit, k) * shift[k];
    bit += val * shift[k];
    return bit;
}

vector<int> solve_dp(int day, const vector<int> &vec) {
    int lim = shift[K];
    vector< vector< vector<int> > > dp(K+1, vector< vector<int> >(L+1, vector<int>(lim, INF)));
    dp[0][0] = vec;

    for(int i=0; i<K; i++) {
        for(int j=0; j<=L; j++) {
            for(int bit=0; bit<lim; bit++) {
                int v = get_digit(bit, i);
                for(int x=0; x+v<=2 and x+j<=L; x++) {
                    int nbit = update_digit(bit, i, x+v);
                    int cost = c[day][i] * x;
                    chmin(dp[i+1][j+x][nbit], dp[i][j][bit] + cost);
                }
            }
        }
    }

    vector<int> res = vec;
    for(int bit=0; bit<lim; bit++) {
        for(int i=0; i<=L; i++) res[bit] = min(res[bit], dp[K][i][bit]);
    }
    return res;
}

int solve_testcase() {
    cin >> D >> K >> L;
    if(D == 0 and K == 0 and L == 0) return 1;
    for(int i=0; i<D; i++) {
        for(int j=0; j<K; j++) {
            cin >> c[i][j];
        }
    }

    // solve (DP);
    vector<int> vec(shift[K], INF);
    vec[0] = 0;
    for(int i=0; i<D; i++) {
        vec = solve_dp(i, vec);
    }

    /*
      for(int i=0; i<shift[K]; i++) {
      fprintf(stderr, "vec[%d] = %d\n", i, vec[i]);
      }
    */

    cin >> M >> N >> P;
    for(int i=0; i<M; i++) {
        for(int j=0; j<K; j++) {
            cin >> r[i][j];
        }
    }

    for(int i=0; i<P; i++) {
        for(int j=0; j<K; j++) {
            cin >> t[i][j];
        }
    }
  
    Flow fl(M + P + 2);
    int source = M + P, sink = source + 1;
    for(int i=0; i<P; i++) fl.add_edge(source, i, 1, 0);
    for(int i=0; i<M; i++) fl.add_edge(P+i, sink, 1, 0);

    // fprintf(stderr, "source sink end\n");
    vector<int> cnt(K);
    for(int i=0; i<P; i++) {
        for(int j=0; j<M; j++) {
            fill(cnt.begin(), cnt.end(), 0);

            // fprintf(stderr, "cnt = %zu\n", cnt.size());
            // fprintf(stderr, "fill end\n");
            for(int k=0; k<K; k++) cnt[k] += r[j][k];
            for(int k=0; k<K; k++) cnt[k] -= t[i][k];

            bool ok = true;
            for(int k=0; k<K; k++) ok &= (cnt[k] >= 0);
            if(!ok) continue;

            // fprintf(stderr, "before encode\n");
            int bit = encode(cnt);
            // fprintf(stderr, "bit = %d, size = %zu\n", bit, vec.size());
            if(vec[bit] == INF) continue;
            // fprintf(stderr, "add edge: [%d, %d, %d]\n", i, j, vec[bit]);
            fl.add_edge(i, P+j, 1, vec[bit]);
        }
    }

    for(int i=0; i<M; i++) {
        fill(cnt.begin(), cnt.end(), 0);
        for(int k=0; k<K; k++) cnt[k] += r[i][k];
        int bit = encode(cnt);
        if(vec[bit] == INF) continue;
        // fprintf(stderr, "# add edge: [source, %d, %d]\n", i, vec[bit]);
        fl.add_edge(source, P+i, 1, vec[bit]);
    }

    // fprintf(stderr, "before flow\n");
    int ans = fl.fast_mincost_flow(source, sink, N);
    cout << ans << endl;
    return 0;
}

int main() {
    shift[0] = 1;
    for(int i=1; i<10; i++) shift[i] = shift[i-1] * 3;
  
    while(!solve_testcase());
}

