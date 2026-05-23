#include <bits/stdc++.h>
using namespace std;
const int M = 1e5 + 5;
int pt[M];
bool vis[M];
int st[M];
int en[M];
int lvl[M];
int n;
int anc[M][30];
vector<int> tree[10 * M];
vector<int> vtr[M];
vector<int> eu;
void dfs(int x, int t) {
  if (vis[x]) return;
  vis[x] = 1;
  eu.push_back(t);
  int i;
  lvl[x] = t;
  st[x] = eu.size() - 1;
  for (i = 0; i < vtr[x].size(); i++) {
    dfs(vtr[x][i], t + 1);
  }
  eu.push_back(t);
  en[x] = eu.size() - 1;
}
void pre() {
  int i, j;
  for (i = 1; i <= n; i++)
    for (j = 1; 1 << j <= n; j++) anc[i][j] = 0;
  for (i = 1; i <= n; i++) anc[i][0] = pt[i];
  for (j = 1; 1 << j <= n; j++)
    for (i = 1; i <= n; i++)
      if (anc[i][j - 1]) anc[i][j] = anc[anc[i][j - 1]][j - 1];
  return;
}
void build(int node, int s, int e) {
  if (s == e) {
    tree[node].push_back(eu[s]);
    return;
  }
  int mid = (s + e) / 2;
  build(2 * node, s, mid);
  build(2 * node + 1, mid + 1, e);
  int a = tree[2 * node].size();
  int b = tree[2 * node + 1].size();
  int i = 0, j = 0;
  while (i < a && j < b) {
    if (tree[2 * node][i] < tree[2 * node + 1][j]) {
      tree[node].push_back(tree[2 * node][i]);
      i++;
    } else {
      tree[node].push_back(tree[2 * node + 1][j]);
      j++;
    }
  }
  while (i < a) {
    tree[node].push_back(tree[2 * node][i]);
    i++;
  }
  while (j < b) {
    tree[node].push_back(tree[2 * node + 1][j]);
    j++;
  }
}
int fpt(int x, int p) {
  int log;
  for (log = 0; 1 << log <= lvl[x]; log++)
    ;
  int i, t = lvl[x] - p;
  for (i = log; i >= 0; i--) {
    if (lvl[x] - (1 << i) >= t) x = anc[x][i];
  }
  return x;
}
int query(int node, int s, int e, int l, int r, int x) {
  if (s > r || l > e) return 0;
  if (s >= l && e <= r) {
    return upper_bound(tree[node].begin(), tree[node].end(), x) -
           lower_bound(tree[node].begin(), tree[node].end(), x);
  }
  int mid = (s + e) / 2;
  return query(2 * node, s, mid, l, r, x) +
         query(2 * node + 1, mid + 1, e, l, r, x);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  int i, m, x, p, y;
  for (i = 1; i <= n; i++) {
    lvl[i] = 0;
    cin >> pt[i];
    if (pt[i]) vtr[pt[i]].push_back(i);
  }
  for (i = 1; i <= n; i++) {
    if (vtr[i].size()) dfs(i, 0);
  }
  for (i = 1; i <= n; i++) {
    if (!vis[i]) {
      st[i] = eu.size();
      eu.push_back(lvl[i]);
      en[i] = eu.size();
      eu.push_back(lvl[i]);
    }
  }
  pre();
  build(1, 0, eu.size() - 1);
  cin >> m;
  int l, r;
  while (m--) {
    cin >> x >> p;
    if (lvl[x] < p)
      cout << "0 ";
    else {
      y = fpt(x, p);
      l = st[y];
      r = en[y];
      cout << query(1, 0, eu.size() - 1, l, r, lvl[x]) / 2 - 1 << " ";
    }
  }
  cout << "\n";
}
