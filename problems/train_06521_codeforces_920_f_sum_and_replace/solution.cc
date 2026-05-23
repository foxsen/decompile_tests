#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int LINF = 0x3f3f3f3f3f3f3f3f;
template <typename T, typename U>
inline void amin(T &x, U y) {
  if (y < x) x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y) {
  if (x < y) x = y;
}
const int N = 2e6 + 7;
const int N2 = 1e6 + 7;
int v[N];
long long s[N];
int PHI[1000007];
void precalc() {
  for (int i = 2; i <= N2; i++)
    for (int j = i; j <= N2; j += i) PHI[j]++;
}
void update(int l, int r, int nod, int poz, int val) {
  if (l == r) {
    s[nod] = val * 1LL;
    v[nod] = val;
    return;
  }
  int mid = (l + r) / 2;
  if (poz <= mid)
    update(l, mid, nod * 2, poz, val);
  else
    update(mid + 1, r, nod * 2 + 1, poz, val);
  s[nod] = s[nod * 2] + s[nod * 2 + 1];
  v[nod] = max(v[nod * 2], v[nod * 2 + 1]);
}
void update2(int l, int r, int nod, int a, int b) {
  if (v[nod] < 3) return;
  if (l == r) {
    v[nod] = PHI[v[nod]] + 1;
    s[nod] = v[nod];
    return;
  }
  int mid = (l + r) / 2;
  if (a <= mid) update2(l, mid, nod * 2, a, b);
  if (b > mid) update2(mid + 1, r, nod * 2 + 1, a, b);
  s[nod] = s[nod * 2] + s[nod * 2 + 1];
  v[nod] = max(v[nod * 2], v[nod * 2 + 1]);
}
long long query(int l, int r, int nod, int a, int b) {
  if (a <= l && b >= r) return s[nod];
  int mid = (l + r) / 2;
  long long s = 0;
  if (a <= mid) s += query(l, mid, nod * 2, a, b);
  if (b > mid) s += query(mid + 1, r, nod * 2 + 1, a, b);
  return s;
}
int main() {
  ios::sync_with_stdio(false), cin.tie(0);
  precalc();
  int n, q;
  cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    update(1, n, 1, i, x);
  }
  while (q--) {
    int task;
    int a, b;
    cin >> task;
    cin >> a >> b;
    if (task == 1)
      update2(1, n, 1, a, b);
    else
      cout << query(1, n, 1, a, b) << '\n';
  }
}
