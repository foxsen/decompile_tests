#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("-O3")
const int MAXN = 1e5 + 5;
const int MAXK = 18;
const int MAXQ = MAXN;
const int S = 400;
struct Query {
  int l, r, idx, lc;
  bool operator<(Query other) const {
    if (l / S != (other.l) / S) return l < other.l;
    return ((l / S) & 2) ? r < other.r : r > other.r;
  }
  void wypisz() { cerr << l << " " << r << " " << idx << " " << lc << "\n"; }
};
vector<int> G[MAXN];
int parent[MAXN][MAXK];
vector<int> child[MAXN];
int glebokosc[MAXN];
pair<int, int> wystepowanie[MAXN];
bool boy[MAXN];
int val[MAXN];
int ile[2][MAXN];
int parity[MAXN];
long long ans[MAXQ];
vector<int> kolejnosc;
vector<Query> que;
int licznik = 0;
int n, q;
long long res = 0;
void dfs_gen(int x, int p = -1) {
  wystepowanie[x].first = kolejnosc.size();
  kolejnosc.push_back(x);
  for (int y : G[x])
    if (y != p) {
      glebokosc[y] = glebokosc[x] + 1;
      child[x].push_back(y);
      parent[y][0] = x;
      dfs_gen(y, x);
    }
  wystepowanie[x].second = kolejnosc.size();
  kolejnosc.push_back(x);
}
int lca(int a, int b) {
  if (glebokosc[a] > glebokosc[b]) swap(a, b);
  int dif = glebokosc[b] - glebokosc[a];
  for (int k = MAXK - 1; k >= 0; k--)
    if ((1 << k) & dif) b = parent[b][k];
  if (a == b) return a;
  for (int k = MAXK - 1; k >= 0; k--)
    if (parent[a][k] != parent[b][k]) {
      b = parent[b][k];
      a = parent[a][k];
    }
  return parent[b][0];
}
void treegen() {
  dfs_gen(0);
  for (int k = 1; k < MAXK; k++)
    for (int i = 0; i < (n); ++i)
      parent[i][k] = parent[parent[i][k - 1]][k - 1];
}
void enu() {
  vector<int> X;
  for (int i = 0; i < (n); ++i) X.push_back(val[i]);
  sort((X).begin(), (X).end());
  X.resize(unique((X).begin(), (X).end()) - X.begin() + 1);
  for (int i = 0; i < (n); ++i)
    val[i] = lower_bound((X).begin(), (X).end(), val[i]) - X.begin();
}
void pre() {
  cin >> n;
  for (int i = 0; i < (n); ++i) cin >> boy[i];
  for (int i = 0; i < (n); ++i) cin >> val[i];
  enu();
  for (int i = 0; i < (n - 1); ++i) {
    int a, b;
    cin >> a >> b;
    G[--a].push_back(--b);
    G[b].push_back(a);
  }
  treegen();
  cin >> q;
  for (int i = 0; i < (q); ++i) {
    int a, b;
    cin >> a >> b;
    if (wystepowanie[--a].first > wystepowanie[--b].first) swap(a, b);
    if (lca(a, b) == a)
      que.push_back({wystepowanie[a].first, wystepowanie[b].first, i, -1});
    else
      que.push_back(
          {wystepowanie[a].second, wystepowanie[b].first, i, lca(a, b)});
  }
}
void add(int x, int a) {
  res += ile[a ^ 1][val[x]];
  ile[a][val[x]]++;
}
void remove(int x, int a) {
  res -= ile[a ^ 1][val[x]];
  ile[a][val[x]]--;
}
void change(int a) {
  int x = kolejnosc[a];
  parity[x]++;
  if (parity[x] % 2)
    add(x, boy[x]);
  else
    remove(x, boy[x]);
}
void solve(vector<Query> V) {
  sort((V).begin(), (V).end());
  int cur_l = 0;
  int cur_r = -1;
  for (auto Q : V) {
    while (cur_l > Q.l) change(--cur_l);
    while (cur_r < Q.r) change(++cur_r);
    while (cur_l < Q.l) change(cur_l++);
    while (cur_r > Q.r) change(cur_r--);
    if (Q.lc != -1) change(wystepowanie[Q.lc].first);
    ans[Q.idx] = res;
    if (Q.lc != -1) change(wystepowanie[Q.lc].first);
  }
}
int main() {
  ios_base::sync_with_stdio(0), cout.setf(ios::fixed), cout.precision(10);
  pre();
  solve(que);
  for (int i = 0; i < (q); ++i) cout << ans[i] << "\n";
}
