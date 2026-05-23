#include <bits/stdc++.h>
#pragma GCC optimize(3)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-fgcse")
#pragma GCC optimize("-fgcse-lm")
#pragma GCC optimize("-fipa-sra")
#pragma GCC optimize("-ftree-pre")
#pragma GCC optimize("-ftree-vrp")
#pragma GCC optimize("-fpeephole2")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("-fsched-spec")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("-falign-jumps")
#pragma GCC optimize("-falign-loops")
#pragma GCC optimize("-falign-labels")
#pragma GCC optimize("-fdevirtualize")
#pragma GCC optimize("-fcaller-saves")
#pragma GCC optimize("-fcrossjumping")
#pragma GCC optimize("-fthread-jumps")
#pragma GCC optimize("-funroll-loops")
#pragma GCC optimize("-fwhole-program")
#pragma GCC optimize("-freorder-blocks")
#pragma GCC optimize("-fschedule-insns")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("-ftree-tail-merge")
#pragma GCC optimize("-fschedule-insns2")
#pragma GCC optimize("-fstrict-aliasing")
#pragma GCC optimize("-fstrict-overflow")
#pragma GCC optimize("-falign-functions")
#pragma GCC optimize("-fcse-skip-blocks")
#pragma GCC optimize("-fcse-follow-jumps")
#pragma GCC optimize("-fsched-interblock")
#pragma GCC optimize("-fpartial-inlining")
#pragma GCC optimize("no-stack-protector")
#pragma GCC optimize("-freorder-functions")
#pragma GCC optimize("-findirect-inlining")
#pragma GCC optimize("-fhoist-adjacent-loads")
#pragma GCC optimize("-frerun-cse-after-loop")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("-finline-small-functions")
#pragma GCC optimize("-ftree-switch-conversion")
#pragma GCC optimize("-foptimize-sibling-calls")
#pragma GCC optimize("-fexpensive-optimizations")
#pragma GCC optimize("-funsafe-loop-optimizations")
#pragma GCC optimize("inline-functions-called-once")
#pragma GCC optimize("-fdelete-null-pointer-checks")
using namespace std;
const long long N = 2e5 + 10;
long long lim[N], a[N], b[N];
void solve() {}
signed main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n, m, i;
    long long dl = 0, dr = 0;
    cin >> n >> m;
    for (i = 1; i <= n; i++) {
      long long x, y, l, r;
      cin >> x >> y;
      a[i] = min(x, m);
      b[i] = m - a[i];
      if (x <= m)
        l = m - x - y;
      else
        l = x - m - y;
      if (y <= m)
        r = x - m + y;
      else
        r = x + m - y;
      assert(l <= r);
      lim[i] = r - l >> 1;
      dl -= l;
      dr += r - l;
    }
    if (dl >= 0 && dl <= dr) {
      cout << (dl & 1) << '\n';
      dl >>= 1;
      for (i = 1; i <= n; i++)
        if (dl >= lim[i])
          dl -= lim[i], cout << a[i] - lim[i] << ' ' << b[i] + lim[i] << '\n';
        else
          cout << a[i] - dl << ' ' << b[i] + dl << '\n', dl = 0;
    } else if (dl < 0) {
      cout << -dl << endl;
      for (i = 1; i <= n; i++) cout << a[i] << ' ' << b[i] << endl;
    } else {
      cout << dl - dr << endl;
      for (i = 1; i <= n; i++)
        cout << a[i] - lim[i] << ' ' << b[i] + lim[i] << '\n';
    }
  }
}
