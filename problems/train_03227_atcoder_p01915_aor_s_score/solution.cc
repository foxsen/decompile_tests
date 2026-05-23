// ?????¬???????????¬??????

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <string>
#include <cstring>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <set>
#include <complex>
#include <cmath>
#include <limits>
#include <cfloat>
#include <climits>
#include <ctime>
#include <cassert>
#include <numeric>
#include <functional>
using namespace std;

#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define int long long int

template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}

typedef pair<int, int> pii;
typedef long long ll;

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
constexpr ll INF = 1001001001001001LL;
constexpr ll MOD = 1000000007LL;

template <typename T>
struct Edge {
    int to; T cap, cost; int rev;
    Edge(int t, T c, int r) : to(t), cap(c), rev(r) {}
    Edge(int t, T ca, T co, int r) : to(t), cap(ca), cost(co), rev(r) {}
};

template <typename T>
using Graph = vector< vector< Edge<T> > >;

template <typename T>
struct Flow {
    vector< vector< Edge<T> > > G;
    const T MAXC = 1 << 30;
    int n;
    vector<bool> used;
    vector<int> prevv, preve, dist;
    Flow(int _n) : G(_n), n(_n), used(_n, false), 
        prevv(n), preve(n), dist(n, MAXC) {}

    // G[e.to][e.rev] ??§?????????????????§??????
    void add_edge(int from, int to, T cap) {
        G[from].push_back(Edge<T>(to, cap, G[to].size()));
        G[to].push_back(Edge<T>(from, 0, G[from].size() - 1));
    }
    void add_edge(int from, int to, T cap, T cost) {
        G[from].push_back(Edge<T>(to, cap, cost, G[to].size()));
        G[to].push_back(Edge<T>(from, 0, -cost, G[from].size() - 1));
    }

    T dfs(int v, int t, T f) {
        if(v == t) return f;
        used[v] = true;
        for(int i=0; i < G[v].size(); i++) {
            Edge<T> &e = G[v][i];
            if(!used[e.to] && e.cap > 0) {
                T d = dfs(e.to, t, min(f, e.cap));
                if(d > 0) {
                    e.cap -= d;
                    G[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

    T max_flow(int s, int t) {
        T flow = 0;
        while(1) {
            fill(used.begin(), used.end(), false);
            T f = dfs(s, t, INF);
            if(f == 0) return flow;
            flow += f;
        }
    }

    T mincost_flow(int s, int t, T f) {
        T res = 0;
        T ma = MAXC;
        while(f > 0) {
            fill(dist.begin(), dist.end(), ma);
            dist[s] = 0;
            bool update = true;
            while(update) {
                update = false;
                for(int v = 0; v < n; v++) {
                    if(dist[v] == ma) continue;
                    for(int i=0; i<G[v].size(); i++) {
                        Edge<T> &e = G[v][i];
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
            T d = f;
            for(int v = t; v != s; v = prevv[v]) {
                d = min(d, G[prevv[v]][preve[v]].cap);
            }
            f -= d;
            res += d * dist[t];
            for(int v = t; v != s; v = prevv[v]) {
                Edge<T> &e = G[prevv[v]][preve[v]];
                e.cap -= d;
                G[v][e.rev].cap += d;
            }
        }
        return res;
    }
};

int N, M, K;
int a[110], b[110][110], t[110];

signed main() {
    cin >> N >> M >> K;
    rep(i,0,N) cin >> a[i];
    rep(i,0,M) rep(j,0,N) cin >> b[i][j];
    rep(i,0,M) cin >> t[i];

    Flow<int> fl(N+M+3);
    int source = N+M, sink = source + 1, mid = sink + 1;
    fl.add_edge(source, mid, N-K, 0);
    fl.add_edge(source, sink, N, 0);
    rep(i,0,M) fl.add_edge(mid, i, t[i], 0);
    rep(i,0,N) fl.add_edge(M+i, sink, 1, 0);

    rep(i,0,M) rep(j,0,N) {
        fl.add_edge(i, M+j, 1, a[j] - b[i][j]);
    }
    int S = accumulate(a, a+N, 0LL);
    cout << S - fl.mincost_flow(source, sink, N) << endl;
    return 0;
}