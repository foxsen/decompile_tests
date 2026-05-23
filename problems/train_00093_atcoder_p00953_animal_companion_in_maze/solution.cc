#include <bits/stdc++.h>

using namespace std;

const int INF = 1 << 29;

struct UnionFind
{
  vector< int > data;

  UnionFind(int sz)
  {
    data.assign(sz, -1);
  }

  int find(int k)
  {
    return (data[k] < 0 ? k : data[k] = find(data[k]));
  }

  void unite(int x, int y)
  {
    x = find(x);
    y = find(y);
    if(x == y) return;
    if(data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
  }
};

vector< pair< int, int > > g[100001];
vector< int > leftt[100001], rightt[100001], just[100001];
vector< int > gg[100001];
int deg[100001];


int rec(int idx, int back = -1)
{
  if(rightt[idx][0] == INF) {
    for(int i = 0; i < g[idx].size(); i++) {
      int to, rev;
      tie(to, rev) = g[idx][i];
      if(i == back) continue;
      just[idx][i] = rec(to, rev) + 1;
    }
    for(int i = 0; i < g[idx].size(); i++) {
      leftt[idx][i + 1] = max(leftt[idx][i], just[idx][i]);
    }
    for(int i = (int) g[idx].size() - 1; i >= 0; i--) {
      rightt[idx][i] = max(rightt[idx][i + 1], just[idx][i]);
    }
  }
  if(back == -1) return (rightt[idx][0]);
  return (max(leftt[idx][back], rightt[idx][back + 1]));
}


int main()
{
  int N, M;
  vector< pair< int, int > > edges, arcs;

  scanf("%d %d", &N, &M);

  UnionFind uf(N);

  for(int i = 0; i < M; i++) {
    int x, y, t;
    cin >> x >> y >> t;
    --x, --y;
    if(t == 1) {
      arcs.emplace_back(x, y);
      g[x].emplace_back(y, -1);
    } else {
      if(uf.find(x) == uf.find(y)) {
        cout << "Infinite" << endl;
        return (0);
      }
      uf.unite(x, y);
      edges.emplace_back(x, y);
      g[y].emplace_back(x, g[x].size());
      g[x].emplace_back(y, g[y].size() - 1);
    }
  }

  {
    for(auto &e : arcs) {
      gg[uf.find(e.first)].push_back(uf.find(e.second));
      ++deg[uf.find(e.second)];
    }
    vector< int > order;
    for(int i = 0; i < N; i++) {
      if(deg[i] == 0) order.push_back(i);
    }
    for(int i = 0; i < order.size(); i++) {
      for(auto &e : gg[order[i]]) {
        if(--deg[e] == 0) order.push_back(e);
      }
    }
    if(order.size() != N) {
      cout << "Infinite" << endl;
      return (0);
    }
  }


  int ret = 0;
  for(int i = 0; i < N; i++) {
    int sz = g[i].size();
    just[i].assign(sz, INF);
    leftt[i].assign(sz + 1, INF);
    rightt[i].assign(sz + 1, INF);
    leftt[i][0] = rightt[i][sz] = 0;
  }
  for(int i = 0; i < N; i++) ret = max(ret, rec(i));
  cout << ret << endl;
}