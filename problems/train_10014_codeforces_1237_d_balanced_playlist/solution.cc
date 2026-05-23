#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
const long long INF = 1e9 + 47;
const long long LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int N = 1 << 19;
int n;
int a[N];
int ans[N];
int t[N << 1];
void build(int v, int tl, int tr) {
  if (tl == tr) {
    t[v] = a[tl];
    return;
  }
  int tm = (tl + tr) >> 1;
  build(v + v, tl, tm);
  build(v + v + 1, tm + 1, tr);
  t[v] = max(t[v + v], t[v + v + 1]);
}
int get(int v, int tl, int tr, int l, int r) {
  if (l > r || tl > tr) return 0;
  if (l == tl && r == tr) return t[v];
  int tm = (tl + tr) >> 1;
  return max(get(v + v, tl, tm, l, min(r, tm)),
             get(v + v + 1, tm + 1, tr, max(l, tm + 1), r));
}
int r[N];
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  int mx = 0, mn = INF;
  for (int i = (0); i < (n); ++i) {
    cin >> a[i];
    mx = max(mx, a[i]);
    mn = min(mn, a[i]);
  }
  if (mn * 2 >= mx) {
    for (int i = (0); i < (n); ++i) cout << "-1 ";
    cout << endl;
    return 0;
  }
  for (int i = (n); i < (n * 4); ++i) a[i] = a[i - n];
  build(1, 0, n * 4 - 1);
  mx = 0;
  int ptr = 0;
  for (int i = (0); i < (n * 4); ++i) {
    mx = max(mx, a[i]);
    if (a[i] * 2 < mx) {
      r[0] = i;
      ptr = i;
      break;
    }
  }
  for (int i = (1); i < (n); ++i) {
    int tut = get(1, 0, 4 * n - 1, i, ptr);
    if (tut > 2 * a[ptr]) {
      r[i] = ptr;
      continue;
    }
    mx = tut;
    int j = ptr + 1;
    while (1) {
      mx = max(mx, a[j]);
      if (a[j] * 2 < mx) {
        ptr = j;
        break;
      }
      ++j;
    }
    r[i] = ptr;
  }
  for (int i = (0); i < (n); ++i) ans[i] = r[i] - i;
  for (int i = (0); i < (n); ++i) cout << ans[i] << ' ';
  cout << endl;
  cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
  return 0;
}
