#include <bits/stdc++.h>
using namespace std;
long long max(long long f, long long b) {
  if (f > b)
    return f;
  else
    return b;
}
long long min(long long f, long long b) {
  if (f < b)
    return f;
  else
    return b;
}
long long lowbit(long long x) { return x & (-x); }
long long prime(long long x) {
  if (x <= 1) return false;
  for (int i = 2; i <= int(sqrt(x)); i++) {
    if (x % i == 0) return false;
  }
  return true;
}
bool cmp(long long f, long long b) { return f > b; }
long long gcd(long long f, long long b) {
  long long r;
  while (b > 0) {
    r = f % b;
    f = b;
    b = r;
  }
  return f;
}
long long powmod(long long f, long long b, long long mod) {
  long long res = 1;
  f %= mod;
  for (; b; b >>= 1) {
    if (b & 1) res = res * f % mod;
    f = f * f % mod;
  }
  return res;
}
inline int readint() {
  char c = getchar();
  int w = 1;
  int x = 0;
  while (!isdigit(c)) (c == '-') && (w = -w), c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
  x *= w;
  return x;
}
inline long long readll() {
  char c = getchar();
  long long w = 1;
  long long x = 0;
  while (!isdigit(c)) (c == '-') && (w = -w), c = getchar();
  while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ '0'), c = getchar();
  x *= w;
  return x;
}
void fl(string name) {
  freopen((name + ".in").c_str(), "r", stdin);
  freopen((name + ".out").c_str(), "w", stdout);
}
const int dx[8] = {-1, 1, 0, 0, -1, 1, -1, 1},
          dy[8] = {0, 0, -1, 1, -1, -1, 1, 1};
long long n, k;
char f[300100];
int main() {
  long long q;
  cin >> q;
  while (q--) {
    cin >> n >> k;
    cin >> (f + 1);
    long long found = 1;
    for (int i = 1; i <= (n - 1) / k; i++) {
      for (int g = 1; g + k * i <= n and k >= g; g++) {
        if ('?' == f[g + k * i]) {
        } else {
          if ('?' == f[g])
            f[g] = f[g + k * i];
          else if (f[g + k * i] != f[g]) {
            found = 0;
            break;
          }
        }
      }
      if (found == 0) break;
    }
    if (found == 0) {
      cout << "NO" << '\n';
    } else {
      long long tot = 0, p = 0;
      for (int i = 1; i <= k; i++) {
        if (f[i] == '?') p++;
        if (f[i] == '1') tot++;
      }
      if (k / 2 >= tot and k / 2 <= tot + p)
        cout << "YES" << '\n';
      else
        cout << "NO" << '\n';
    }
  }
  return 0;
}
