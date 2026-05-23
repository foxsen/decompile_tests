#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
const int mod = 1e9 + 7;
inline long long mul(long long x, long long y) { return x * y % mod; }
int n;
long long sum[N][2][2], sq[N][2][2], cnt[N][2][2];
char a[N], b[N];
int main() {
  scanf("%s %s", a + 1, b + 1);
  n = strlen(a + 1);
  for (int i = n; i >= 1; i--) {
    if (b[i] == '7') {
      b[i] = '4';
      break;
    }
    b[i] = '7';
  }
  cnt[0][0][0] = 1;
  for (int i = 1; i <= n; i++) {
    for (int need1 = 0; need1 <= 1; need1++) {
      for (int need2 = 0; need2 <= 1; need2++) {
        for (int c = '4'; c <= '7'; c += 3) {
          bool w1 = c < a[i] or (need1 and c == a[i]);
          bool w2 = c > b[i] or (need2 and c == b[i]);
          cnt[i][need1][need2] += cnt[i - 1][w1][w2];
          sum[i][need1][need2] += mul(10, sum[i - 1][w1][w2]);
          sum[i][need1][need2] += mul(c - '0', cnt[i - 1][w1][w2]);
          sq[i][need1][need2] += mul(100, sq[i - 1][w1][w2]);
          sq[i][need1][need2] += mul((c - '0') * 20, sum[i - 1][w1][w2]);
          sq[i][need1][need2] += mul((c - '0') * (c - '0'), cnt[i - 1][w1][w2]);
        }
        cnt[i][need1][need2] %= mod;
        sum[i][need1][need2] %= mod;
        sq[i][need1][need2] %= mod;
      }
    }
  }
  long long ans = 0, ten = 1, need1 = 0, need2 = 0, X = 0, Y = 0;
  for (int i = n; i >= 1; i--) {
    bool w1 = '4' < a[i] or (need1 and '4' == a[i]);
    bool w2 = '4' > b[i] or (need2 and '4' == b[i]);
    long long x = (X + mul(7, ten)) % mod;
    long long y = (Y + mul(4, ten)) % mod;
    X = (X + mul(4, ten)) % mod;
    Y = (Y + mul(7, ten)) % mod;
    ten = mul(ten, 10);
    ans += mul(mul(ten, ten), sq[i - 1][w1][w2]);
    ans += mul(mul(ten, x + y), sum[i - 1][w1][w2]);
    ans += mul(mul(x, y), cnt[i - 1][w1][w2]);
    ans %= mod;
    need1 = w1 = '7' < a[i] or (need1 and '7' == a[i]);
    need2 = w2 = '7' > b[i] or (need2 and '7' == b[i]);
  }
  printf("%lld\n", ans);
  return 0;
}
