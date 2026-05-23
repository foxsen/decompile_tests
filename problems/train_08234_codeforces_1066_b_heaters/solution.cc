#include <bits/stdc++.h>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
using namespace std;
inline int read() {
  int r = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    r = r * 10 + c - '0';
    c = getchar();
  }
  return r;
}
inline long long readll() {
  long long r = 0;
  char c = getchar();
  while (c < '0' || c > '9') {
    c = getchar();
  }
  while (c >= '0' && c <= '9') {
    r = r * 10 + c - '0';
    c = getchar();
  }
  return r;
}
inline long long qpow(long long a, long long b, long long mod) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % mod;
    a = (a * a) % mod;
    b >>= 1;
  }
  return res;
}
inline long long gcd(long long a, long long b) {
  while (b ^= a ^= b ^= a %= b)
    ;
  return a;
}
const double eps = 1e-8;
const long long LLINF = 0x3f3f3f3f3f3f3f3f;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
const int MAXN = 1e5;
const int MAXM = 1e5;
int a[MAXN];
int re[MAXN];
int main() {
  int n, r;
  cin >> n >> r;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    if (a[i]) {
      ans++;
      for (int j = i; j >= 1 && j >= i - r + 1; j--) re[j]++;
      for (int j = i + 1; j <= n && j <= i + r - 1; j++) re[j]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!re[i]) {
      cout << "-1"
           << "\n";
      return 0;
    }
  }
  for (int i = 1; i <= n; i++) {
    int flag = 0;
    if (a[i]) {
      for (int j = i; j >= 1 && j >= i - r + 1; j--) {
        if (re[j] == 1) {
          flag = 1;
          break;
        }
      }
      for (int j = i + 1; j <= n && j <= i + r - 1; j++) {
        if (re[j] == 1) {
          flag = 1;
          break;
        }
      }
      if (!flag) {
        ans--;
        for (int j = i; j >= 1 && j >= i - r + 1; j--) re[j]--;
        for (int j = i + 1; j <= n && j <= i + r - 1; j++) re[j]--;
      }
    }
  }
  cout << ans << endl;
  return 0;
}
