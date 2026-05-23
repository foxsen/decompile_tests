#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
constexpr int MOD = 1000000007;
constexpr ll INF = (1LL << 61) - 1;
template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}
template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}
template <typename T>
void fail(T v) {
  cout << v << endl;
  exit(0);
}
vector<int> G[1001001], mn;
void dfs(int i, int p) {
  for (int& e : G[i]) {
    if (e == p) continue;
    chmin(mn[e], mn[i]);
    dfs(e, i);
  }
}
void solve() {
  int N, Q;
  scanf("%d %d", &N, &Q);
  mn.assign(N, 0);
  for (int i = 0; i < (int)(N - 1); ++i) {
    int x, y;
    scanf("%d %d", &x, &y);
    x--;
    y--;
    G[x].push_back(y);
    G[y].push_back(x);
  }
  for (int i = 0; i < (int)(N); ++i) mn[i] = i;
  int root;
  scanf("%d %d", &root, &root);
  root %= N;
  dfs(root, -1);
  int all = root;
  Q--;
  int last = 0;
  while (Q--) {
    int T, X;
    scanf("%d %d", &T, &X);
    X = (X + last) % N;
    if (T == 1) {
      chmin(all, mn[X]);
    } else {
      last = min(all, mn[X]) + 1;
      printf("%d\n", last);
    }
  }
}
int main() {
  solve();
  return 0;
}
