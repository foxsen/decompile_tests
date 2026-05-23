#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
const int maxn = 3e2 + 10, maxm = 1e3 + 10;
const long long mod = 1e9 + 12341;
int n, m;
const long long decm = 128;
long long pw[maxn];
void init(int n = maxn - 5) {
  pw[0] = 1;
  for (int i = 1; i <= n; ++i) pw[i] = pw[i - 1] * decm % mod;
}
class strhash {
 public:
  long long hs[maxn], len;
  long long calhs(string &s, int n) {
    len = n;
    for (int i = 0; i <= len - 1; ++i) hs[i + 1] = (hs[i] * decm + s[i]) % mod;
    return hs[len];
  }
  inline long long geths(int a, int b) {
    return (hs[b] - (hs[a - 1] * pw[b - a + 1]) % mod + mod) % mod;
  }
} mps, mpt[20];
int l[20], r[20];
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  init(maxn - 5);
  string s;
  cin >> s;
  cin >> n;
  mps.calhs(s, s.size());
  for (int i = 1; i <= n; ++i) {
    string t;
    cin >> t >> l[i] >> r[i];
    mpt[i].calhs(t, t.size());
  }
  int xx = s.size();
  set<long long> ans;
  for (int i = 1; i <= xx; ++i)
    for (int j = i; j <= xx; ++j) {
      int cnt = 0;
      int len = j - i + 1;
      long long hs = mps.geths(i, j);
      for (int k = 1; k <= n; ++k) {
        int flag = 0;
        if (len <= mpt[k].len)
          for (int z = 1; z <= mpt[k].len - len + 1; ++z)
            if (hs == mpt[k].geths(z, z + len - 1)) flag++;
        if (flag >= l[k] && flag <= r[k]) {
          cnt++;
        }
      }
      if (cnt == n) {
        ans.insert(hs);
      }
    }
  cout << ans.size() << '\n';
}
