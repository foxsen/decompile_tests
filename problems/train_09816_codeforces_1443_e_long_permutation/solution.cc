#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;
void err(istream_iterator<string> it) {}
template <typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
  cerr << *it << " = " << a << "\n";
  err(++it, args...);
}
long long powm(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
int db = 0;
const long long mod = 1e9 + 7;
const long long N = 1000005;
const long long inf = 1e9;
void solve() {
  long long n, q;
  cin >> n >> q;
  long long fact[16];
  fact[0] = 1;
  for (long long i = (1); i < (16); i++) fact[i] = fact[i - 1] * i;
  long long sum[n + 2];
  sum[n + 1] = 0;
  sum[n] = n;
  long long permutation[n + 1];
  permutation[n] = n;
  int change = max(1ll, n - 15ll);
  for (long long i = (n)-1; i >= 0; i--)
    sum[i] = i + sum[i + 1], permutation[i] = i;
  long long cnt = 0;
  while (q--) {
    long long timepass = 2;
    cin >> timepass;
    if (timepass == 1) {
      long long x, y;
      cin >> x >> y;
      cout << sum[x] - sum[y + 1] << '\n';
    } else {
      long long x = 1;
      cin >> x;
      cnt += x;
      long long shift = cnt;
      for (long long i = (n + 1) - 1; i >= (change); i--) {
        permutation[i] = i;
      }
      long long pos, cur_pos;
      while (shift > 0) {
        for (long long i = (n + 1) - 1; i >= (change); i--) {
          pos = n - i + 1;
          if (shift < fact[pos]) {
            cur_pos = i;
            break;
          }
        }
        long long dif = (shift) / fact[pos - 1];
        shift %= fact[pos - 1];
        swap(permutation[cur_pos + dif], permutation[cur_pos]);
        sort(permutation + cur_pos + 1, permutation + n + 1);
      }
      for (long long i = (n)-1; i >= (change); i--)
        permutation[i] += permutation[i + 1];
      for (long long i = (n + 1) - 1; i >= (change); i--)
        sum[i] = permutation[i];
    }
  }
}
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0), cout.tie(0);
  int tc = 1;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
  return 0;
}
