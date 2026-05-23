#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
int a[maxn], c[maxn];
struct node {
  int num, price, pos;
} b[maxn];
bool cmp(node x, node y) {
  if (x.price != y.price)
    return x.price < y.price;
  else
    return x.pos < y.pos;
}
int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    b[i].pos = i;
    b[i].num = a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> c[i];
    b[i].price = c[i];
  }
  sort(b, b + n, cmp);
  int t, d;
  long long ans = 0;
  int now = 0;
  while (m--) {
    ans = 0;
    cin >> t >> d;
    if (d >= a[t - 1]) {
      ans += (long long)a[t - 1] * c[t - 1];
      d -= a[t - 1];
      a[t - 1] = 0;
    } else {
      ans += (long long)d * c[t - 1];
      a[t - 1] -= d;
      cout << ans << endl;
      continue;
    }
    for (; now < n; now++) {
      if (d == 0) break;
      if (a[b[now].pos] == 0) continue;
      if (a[b[now].pos] >= d) {
        ans += (long long)b[now].price * d;
        a[b[now].pos] -= d;
        d = 0;
      } else {
        ans += (long long)b[now].price * a[b[now].pos];
        d -= a[b[now].pos];
        a[b[now].pos] = 0;
      }
      if (d == 0) break;
    }
    if (d > 0) {
      cout << "0" << endl;
    } else {
      cout << ans << endl;
    }
  }
  return 0;
}
