#include <bits/stdc++.h>
using namespace std;
const int S = 316, N = 2e5;
struct d {
  int l, r, id;
  int t() { return l / S; }
} q[N];
bool p(d a, d b) {
  return a.t() != b.t() ? a.t() < b.t() : a.t() & 1 ? a.r > b.r : a.r < b.r;
}
long long a[N], c[N * 12], r[N], x, n, m, k, pl, pr = -1;
void add(int v) {
  x += c[v ^ k];
  c[v]++;
}
void del(int v) {
  c[v]--;
  x -= c[v ^ k];
}
int main() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) cin >> a[i], a[i] ^= a[i - 1];
  for (int i = 0, l, r; i < m; i++) cin >> q[i].l >> q[i].r, q[i].id = i;
  sort(q, q + m, p);
  for (int i = 0; i < m; i++) {
    int ql = q[i].l - 1, qr = q[i].r, id = q[i].id;
    while (pl > ql) add(a[--pl]);
    while (pr < qr) add(a[++pr]);
    while (pl < ql) del(a[pl++]);
    while (pr > qr) del(a[pr--]);
    r[id] = x;
  }
  for (int i = 0; i < m; i++) cout << r[i] << "\n";
}
