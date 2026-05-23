#include <bits/stdc++.h>
using ll = long long;
using ld = long double;
using namespace std;
const int MAXN = 20001;
int n;
ll x[MAXN], y[MAXN];
void rm(int id) {
  for (int i = id; i + 1 < n; ++i) {
    x[i] = x[i + 1];
    y[i] = y[i + 1];
  }
  --n;
}
ll vals[MAXN];
int ans = 0;
const int BTS = 20;
const ll MSK = (1 << BTS) - 1;
pair<ll, ll> mul(ll x, ll y) {
  bool sgn = false;
  if (x < 0) {
    x = -x;
    sgn = !sgn;
  }
  if (y < 0) {
    y = -y;
    sgn = !sgn;
  }
  ll xl = x & MSK;
  x >>= BTS;
  ll yl = y & MSK;
  y >>= BTS;
  ll lw = (xl * yl);
  ll bg = ((x * y) << BTS) + x * yl + y * xl + (lw >> BTS);
  lw &= MSK;
  if (sgn) {
    bg = -bg;
    lw = -lw;
  }
  return {bg, lw};
}
int origx[MAXN];
int origy[MAXN];
int orign;
void work(ll mdx, ll mdy) {
  bool cool = true;
  for (int j = 0; j < orign; ++j) {
    vals[j] = origx[j] * mdx + origy[j] * mdy;
  }
  sort(vals, vals + orign);
  ll s = vals[0] + vals[orign - 1];
  for (int j = 0; j < orign - 1 - j; ++j) {
    if (vals[j] + vals[orign - 1 - j] != s) {
      cool = false;
      break;
    }
  }
  if (cool) {
    ++ans;
  }
}
ll mdx[MAXN], mdy[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cout.setf(ios::fixed);
  cout.precision(20);
  cout.tie(nullptr);
  cin.tie(nullptr);
  cin >> n;
  orign = n;
  ll sx = 0, sy = 0;
  for (int i = 0; i < n; ++i) {
    cin >> x[i] >> y[i];
    sx += x[i], sy += y[i];
    origx[i] = x[i], origy[i] = y[i];
  }
  for (int i = 0; i < n; ++i) {
    x[i] = (x[i] * n - sx);
    y[i] = (y[i] * n - sy);
  }
  int cur = 0;
  while (cur < n) {
    if (x[cur] == 0 && y[cur] == 0) {
      rm(cur);
      continue;
    }
    bool ok = true;
    for (int i = cur + 1; i < n; ++i) {
      if (x[i] + x[cur] == 0 && y[i] + y[cur] == 0) {
        rm(i);
        rm(cur);
        ok = false;
        break;
      }
    }
    cur += ok;
  }
  if (n == 0) {
    cout << -1 << "\n";
    return 0;
  }
  mdx[0] = x[0], mdy[0] = y[0];
  work(-y[0], x[0]);
  for (int i = 1; i < n; ++i) {
    bool ok = true;
    mdx[i] = (x[0] + x[i]);
    mdy[i] = (y[0] + y[i]);
    for (int j = 0; j < i; ++j) {
      if (mul(mdx[i], mdy[j]) == mul(mdy[i], mdx[j])) {
        ok = false;
        break;
      }
    }
    if (ok) {
      work(-mdy[i], mdx[i]);
    }
  }
  cout << ans << "\n";
}
