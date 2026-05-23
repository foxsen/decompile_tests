#include <bits/stdc++.h>
using namespace std;
using LL = long long;
namespace _buff {
const size_t BUFF = 1 << 19;
char ibuf[BUFF], *ib = ibuf, *ie = ibuf;
char getc() {
  if (ib == ie) {
    ib = ibuf;
    ie = ibuf + fread(ibuf, 1, BUFF, stdin);
  }
  return ib == ie ? -1 : *ib++;
}
}  // namespace _buff
LL read() {
  using namespace _buff;
  LL ret = 0;
  bool pos = true;
  char c = getc();
  for (; (c < '0' || c > '9') && c != '-'; c = getc()) {
    assert(~c);
  }
  if (c == '-') {
    pos = false;
    c = getc();
  }
  for (; c >= '0' && c <= '9'; c = getc()) {
    ret = (ret << 3) + (ret << 1) + (c ^ 48);
  }
  return pos ? ret : -ret;
}
const size_t N = 18;
const size_t M = N * N;
const int MOD = 998244353;
void iadd(int &dp, int val) {
  dp += val;
  if (dp >= MOD) {
    dp -= MOD;
  }
}
void isub(int &dp, int val) {
  dp -= val;
  if (dp < 0) {
    dp += MOD;
  }
}
int dp[1 << N], e[M][2], msk[N];
bool ok[1 << N];
int main() {
  int n = read(), m = read();
  for (int i = 0; i < m; ++i) {
    e[i][0] = read() - 1;
    e[i][1] = read() - 1;
    msk[e[i][0]] |= 1 << e[i][1];
    msk[e[i][1]] |= 1 << e[i][0];
  }
  for (int i = 0, _ = 1 << n; i < _; ++i) {
    int cur = 0;
    bool &flag = ok[i] = true;
    for (int j = 0; j < n && flag; ++j) {
      if (i >> j & 1) {
        flag = ~cur >> j & 1;
        cur |= msk[j];
      }
    }
  }
  dp[0] = 1;
  for (int i = 1, _ = 1 << n; i < _; ++i) {
    for (int j = i; j; j = (j - 1) & i) {
      if (ok[j]) {
        if (__builtin_popcount(j) & 1) {
          iadd(dp[i], dp[i ^ j]);
        } else {
          isub(dp[i], dp[i ^ j]);
        }
      }
    }
  }
  cout << (LL)(MOD + 1) / 2 * dp[(1 << n) - 1] % MOD * m % MOD << '\n';
  return 0;
}
