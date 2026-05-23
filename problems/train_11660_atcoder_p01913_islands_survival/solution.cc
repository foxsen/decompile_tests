#include<bits/stdc++.h>

using namespace std;

typedef long long int64;
const int64 INF = 1LL << 55;

int N, M, T;
int x[200000], y[200000], z[200000];
vector< pair< int, int > > g[200000];
int64 v[200000];

struct UnionFind
{
  vector< int64 > data, time, score;

  UnionFind(int sz)
  {
    data.assign(sz, -1LL);
    time.assign(sz, T);
    score.resize(sz);
    for(int i = 0; i < sz; i++) {
      if(v[i] == INF) score[i] = -INF;
      else score[i] = 0;
    }
  }

  int64 find(int64 k)
  {
    if(data[k] < 0) return (k);
    return (data[k] = find(data[k]));
  }

  void unite(int64 x, int64 y, int64 z)
  {
    x = find(x), y = find(y);
    if(x == y) return;
    score[x] = max(score[x] + size(x) * (time[x] - z), score[y] + size(y) * (time[y] - z));
    data[x] += data[y];
    data[y] = x;
    time[x] = z;
  }

  int64 size(int64 k)
  {
    return (-data[find(k)]);
  }

  int64 res()
  {
    return (score[find(0)] + size(0) * time[find(0)]);
  }
};

int main()
{
  cin >> N >> M >> T;
  for(int i = 0; i < M; i++) {
    cin >> x[i] >> y[i] >> z[i];
    --x[i], --y[i];
    g[x[i]].emplace_back(y[i], z[i]);
    g[y[i]].emplace_back(x[i], z[i]);
  }

  fill_n(v, 100000, INF);
  queue< int > que;
  que.push(0);
  v[0] = 0;
  while(!que.empty()) {
    int p = que.front();
    que.pop();
    for(auto &e : g[p]) {
      if(v[e.first] != INF || v[p] >= e.second) continue;
      v[e.first] = v[p] + 1;
      que.emplace(e.first);
    }
  }

  vector< int > to(M);
  iota(begin(to), end(to), 0);
  sort(begin(to), end(to), [&](int a, int b)
  {
    return (z[a] > z[b]);
  });
  UnionFind tree(N);
  for(int i : to) tree.unite(x[i], y[i], z[i]);
  cout << tree.res() << endl;
}