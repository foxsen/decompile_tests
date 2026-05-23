#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define FOR(i,k,n) for(int i=(k); i<(int)(n); ++i)
#define REP(i,n) FOR(i,0,n)
#define FORIT(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)

template<class T> void debug(T begin, T end){ for(T i = begin; i != end; ++i) cerr<<*i<<" "; cerr<<endl; }
inline bool valid(int x, int y, int W, int H){ return (x >= 0 && y >= 0 && x < W && y < H); }

typedef long long ll;
const int INF = 100000000;
const double EPS = 1e-8;
const int MOD = 1000000007;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

struct UnionFind {
  vector<int> data;
  UnionFind(int N) : data(N, -1) { }
  inline bool uni(int x, int y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[x] > data[y]) swap(x, y);
      data[x] += data[y]; data[y] = x;
    }
    return x != y;
  }
  bool find(int x, int y) {
    return root(x) == root(y);
  }
  inline int root(int x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  inline int size(int x) {
    return -data[root(x)];
  }
};

struct edge{
  int src, dst, cost;
  edge(int s, int d, int c) : src(s), dst(d), cost(c) {}
  edge() {}
  bool operator< (const edge& e) const {
    return cost < e.cost;
  }
};

int main(){
  int N;
  cin>>N;
  vector<edge> v(N - 1);
  REP(i, N - 1){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    v[i] = edge(a, b, c);
  }
  UnionFind uf(N);
  sort(v.begin(), v.end());
  ll ans = 0;
  REP(i, N - 1){
    ans += (ll)uf.size(v[i].src) * uf.size(v[i].dst) * v[i].cost;
    uf.uni(v[i].src, v[i].dst);
  }
  cout<<ans<<endl;
  return 0;
}