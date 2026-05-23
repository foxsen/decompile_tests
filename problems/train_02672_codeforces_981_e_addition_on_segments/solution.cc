#include <bits/stdc++.h>
using namespace std;
mt19937 mt_rand(chrono::system_clock::now().time_since_epoch().count());
template <typename T1, typename T2>
inline bool upmax(T1& a, T2 b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
template <typename T1, typename T2>
inline bool upmin(T1& a, T2 b) {
  if (b < a) {
    a = b;
    return 1;
  }
  return 0;
}
const int maxn = (int)10002;
const int base = 2147483647;
const long double PI = acos(-1.);
int n, q;
bitset<maxn> a, ans;
vector<int> t[4 * maxn];
void upd(int v, int tl, int tr, int l, int r, int x) {
  if (l == tl && r == tr) {
    t[v].push_back(x);
  } else {
    int m = (tl + tr) >> 1;
    if (l <= m) upd(v + v, tl, m, l, min(r, m), x);
    if (r > m) upd(v + v + 1, m + 1, tr, max(l, m + 1), r, x);
  }
}
void getAns(int v, int l, int r, bitset<maxn> cur) {
  for (int x : t[v]) {
    cur = (cur << x) | cur;
  }
  ans |= cur;
  if (l == r) return;
  int m = (l + r) >> 1;
  getAns(v + v, l, m, cur);
  getAns(v + v + 1, m + 1, r, cur);
}
int main() {
  scanf("%d%d", &n, &q);
  a.set(0);
  ans.set(0);
  vector<pair<int, int>> event;
  for (int i = 1; i <= q; i++) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    upd(1, 1, n, l, r, x);
  }
  getAns(1, 1, n, a);
  vector<int> vec;
  for (int i = 1; i <= n; i++) {
    if (ans[i]) {
      vec.push_back(i);
    }
  }
  cout << vec.size() << '\n';
  for (int v : vec) {
    cout << v << " ";
  }
  return 0;
}
