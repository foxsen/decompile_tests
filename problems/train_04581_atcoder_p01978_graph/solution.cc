// 基本テンプレート
 
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
#include <fstream>
#include <functional>
using namespace std;
 
#define rep(i,a,n) for(int (i)=(a); (i)<(n); (i)++)
#define repq(i,a,n) for(int (i)=(a); (i)<=(n); (i)++)
#define repr(i,a,n) for(int (i)=(a); (i)>=(n); (i)--)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define int long long int
 
template<typename T> void chmax(T &a, T b) {a = max(a, b);}
template<typename T> void chmin(T &a, T b) {a = min(a, b);}
template<typename T> void chadd(T &a, T b) {a = a + b;}
 
typedef pair<int, int> pii;
typedef long long ll;
 
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
const ll INF = 1001001001001001LL;
const ll MOD = 1000000007LL;

// 移動元と行先と辺のコストを記録する構造体
template <typename T>
struct Edge {
    int from, to;
    T cost;
    Edge(int s, T d) : to(s), cost(d) {}
    Edge(int f, int s, T d) : from(f), to(s), cost(d) {}

    bool operator<(const Edge &e) const {
        return cost < e.cost;
    }
    bool operator>(const Edge &e) const {
        return cost > e.cost;
    }
};

template <typename T>
using Graph = vector< vector< Edge<T> > >;

void add_edge(Graph<int> &G, int a, int b, int c, int cost) {
    // a - b
    G[a].push_back(Edge<int>(b, cost));
    G[b].push_back(Edge<int>(a, cost));

    // b - c
    G[b].push_back(Edge<int>(c, cost));
    G[c].push_back(Edge<int>(b, cost));

    // c - a
    G[c].push_back(Edge<int>(a, cost));
    G[a].push_back(Edge<int>(c, cost));
}

struct Elem {
    int pos, cost;
    bool operator<(const Elem &e) const {
        return cost > e.cost;
    }
};
 
signed main() {
    int N, M, s, t; cin >> N >> M >> s >> t;
    s--; t--;

    Graph<int> G(N);
    for(int i=0; i<M; i++) {
        int a, b, c, cost; cin >> a >> b >> c >> cost;
        a--; b--; c--;
        add_edge(G, a, b, c, cost);
    }

    vector<int> dist(N, INF);
    dist[s] = 0;
    priority_queue<Elem> que;
    que.push(Elem{s, 0});

    while(que.size()) {
        Elem cur = que.top(); que.pop();
        int v = cur.pos, cost = cur.cost;
        for(auto e : G[v]) {
            if(dist[e.to] > cost + e.cost) {
                dist[e.to] = cost + e.cost;
                que.push(Elem{e.to, cost + e.cost});
            }
        }
    }

    cout << dist[t] << endl;
    return 0;
}
