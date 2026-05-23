#include <bits/stdc++.h>
using namespace std;
int n, m;
long long k;
int a[100005], s[100005], r[100005];
struct BIT {
  int c[100005];
  void add(int x, int y) {
    for (int i = x; i <= m; i += (i & -i)) {
      c[i] += y;
    }
  }
  long long get(int x) {
    long long ret = 0;
    for (int i = x; i > 0; i -= (i & -i)) {
      ret += c[i];
    }
    return ret;
  }
} f0, f1;
int main() {
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    s[i] = a[i];
  }
  sort(s, s + n);
  m = unique(s, s + n) - s;
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(s, s + m, a[i]) - s + 1;
  }
  for (int i = n - 1; i >= 0; --i) {
    r[i] = f0.get(a[i] - 1) + (i < n - 1 ? r[i + 1] : 0);
    f0.add(a[i], 1);
  }
  for (int i = 0; i < n; ++i) {
    f0.add(a[i], -1);
  }
  f0.add(a[0], 1);
  int pos = n;
  long long now = 0;
  for (int i = n - 1; i >= 1; --i) {
    f1.add(a[i], 1);
    if (r[i] + f1.get(a[0] - 1) > k) {
      f1.add(a[i], -1);
      break;
    }
    pos = i;
    now = r[i] + f1.get(a[0] - 1);
  }
  if (pos == 1) {
    cout << 1ll * n * (n - 1) / 2;
    return 0;
  }
  if (pos == n) {
    puts("0");
    return 0;
  }
  long long ans = n - pos;
  for (int i = 1; i < n - 1; ++i) {
    now += f0.get(m) - f0.get(a[i]) + f1.get(a[i] - 1);
    f0.add(a[i], 1);
    while (now > k && pos < n) {
      now -= f0.get(m) - f0.get(a[pos]) + f1.get(a[pos] - 1);
      f1.add(a[pos], -1);
      pos++;
    }
    if (pos == n && now > k) {
      break;
    }
    ans += n - pos;
  }
  cout << ans << endl;
  return 0;
}
