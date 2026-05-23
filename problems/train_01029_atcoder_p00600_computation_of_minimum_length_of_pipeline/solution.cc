#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <queue>
using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
const int INF = 1<<29;

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};

bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

pair<Weight, Edges> prim(const Graph &g, int r) {
  int n = g.size();
  Edges T;
  Weight total = 0;

  vector<bool> visited(n);
  priority_queue<Edge> Q;
  REP(i,r)
    Q.push( Edge(-1, i, 0) );
  while (!Q.empty()) {
    Edge e = Q.top(); Q.pop();
    if (visited[e.dst]) continue;
//    printf("%d->%d, %d\n",e.src,e.dst,e.weight);
    T.push_back(e);
    total += e.weight;
    visited[e.dst] = true;
    FOR(f, g[e.dst]) if (!visited[f->dst]) Q.push(*f);
  }
  return pair<Weight, Edges>(total, T);
}


int main() {
  int n,m;
  while(cin>>n>>m,n||m) {
    Graph g(n+m);
    REP(i,n) {
      REP(j,m) {
        int a;
        cin >> a;
        if (a) {
          g[i].push_back(Edge(i,j+n,a));
          g[j+n].push_back(Edge(j+n,i,a));
        }
      }
    }
    REP(i,m) {
      for (int j=i+1; j<m; ++j) {
        int a;
        cin >> a;
        if (a) {
          g[i+n].push_back(Edge(i+n,j+n,a));
          g[j+n].push_back(Edge(j+n,i+n,a));
        }
      }
    }
    cout << prim(g, n).first << endl;
  }
}