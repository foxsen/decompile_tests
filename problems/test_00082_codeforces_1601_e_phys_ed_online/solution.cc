#include <bits/stdc++.h>
using namespace std;
mt19937 rnd(time(0));
const long long mod = 1e9 + 7;
long long fastpow(long long a, long long b) {
  if (b == 0) return 1;
  assert(b >= 0);
  if (b & 1) return fastpow(a, b - 1) * 1LL * a % mod;
  long long t = fastpow(a, b / 2);
  return t * 1LL * t % mod;
}
const long long maxn = 3e5 + 50;
vector<long long> r[maxn];
void solve() {
  long long n, q, k;
  cin >> n >> q >> k;
  long long a[n];
  for (auto &i : a) cin >> i;
  long long sp[n][20];
  for (long long i = n - 1; i >= 0; --i) {
    sp[i][0] = a[i];
    for (long long j = 1; j < 20; ++j) {
      sp[i][j] = min(sp[i][j - 1], sp[min(n - 1, i + (1 << j - 1))][j - 1]);
    }
  }
  long long max_st[n + 10];
  long long st = 0;
  for (long long i = 0; i <= n + 9; ++i) {
    while ((1 << st + 1) <= i) {
      st++;
    }
    max_st[i] = st;
  }
  auto get = [&](long long l, long long r) {
    long long d = max_st[r - l + 1];
    return min(sp[l][d], sp[r - (1 << d) + 1][d]);
  };
  long long bp[n][20];
  vector<long long> v[k];
  long long next[n][20];
  for (auto &i : next)
    for (auto &j : i) j = n;
  for (long long i = n - 1; i >= 0; --i) {
    long long dk = i % k;
    long long x = get(i, min(i + k - 1, n - 1));
    while (v[dk].size() &&
           get(v[dk].back(), min(n - 1, v[dk].back() + k - 1)) >= x) {
      v[dk].pop_back();
    }
    if (v[dk].size()) {
      next[i][0] = v[dk].back();
      bp[i][0] = x * (v[dk].back() - i) / k;
    } else {
      next[i][0] = n;
      bp[i][0] = x * (n - i + k - 1) / k;
    }
    v[dk].push_back(i);
    for (long long j = 1; j < 19; ++j) {
      if (next[i][j - 1] != n) {
        next[i][j] = next[next[i][j - 1]][j - 1];
        bp[i][j] = bp[next[i][j - 1]][j - 1] + bp[i][j - 1];
      } else {
        bp[i][j] = bp[i][j - 1];
      }
    }
  }
  for (long long i = 0; i < q; ++i) {
    long long l, r;
    cin >> l >> r;
    l--;
    r--;
    long long x = get(l, r);
    if (a[l] <= x) {
      cout << (r - l + 1 + k - 1) / k * a[l] << '\n';
    } else {
      long long d = l + 1;
      for (long long j = l + 1; j + k - 1 <= r;) {
        if (get(j, j + k - 1) > a[l]) {
          d = j + k;
          j += k;
        } else {
          break;
        }
      }
      if (d + k - 1 > r) {
        cout << (r - l + 1 + k - 1) / k * a[l] << '\n';
        continue;
      }
      long long ans = a[l] * ((d - l + k - 1) / k);
      long long now = d;
      for (long long x = 19; x >= 0; --x) {
        if (next[now][x] <= r) {
          ans += bp[now][x];
          now = next[now][x];
        }
      }
      if (now + k - 1 <= r) ans += (r - now + 1) / k * get(now, now + k - 1);
      cout << ans << '\n';
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t = 1;
  while (t--) solve();
}
