#include <bits/stdc++.h>
using namespace std;
long long binpow(long long a, long long b) {
  long long res = 1;
  while (b > 0) {
    if (b & 1) res = res * a;
    a = a * a;
    b >>= 1;
  }
  return res;
}
int findXOR(int n) {
  switch (n % 4) {
    case 0:
      return n;
    case 1:
      return 1;
    case 2:
      return n + 1;
    case 3:
      return 0;
  }
}
int rangeXOR(int l, int r) { return (findXOR(l - 1) ^ findXOR(r)); }
int getbit(int mask, int bit) { return (mask & (1 << bit)); }
void setbit(int& mask, int bit, int val) {
  if (val)
    mask |= (1 << bit);
  else
    mask &= ~(1 << bit);
}
const int N = 1e2 + 10;
const int M = 1e6 + 10;
const long long INF = 1e8;
int solveit(int i, int a, int b, int c) {
  if (a < 0 || b < 0 || c < 0) return -INF;
  int cnta = 0, cntb = 0, cntc = 0;
  if (i == (1 << 3)) return 0;
  if (i & (1 << 0)) cnta++;
  if (i & (1 << 1)) cntb++;
  if (i & (1 << 2)) cntc++;
  int ret = 0;
  ret = max(1 + solveit(i + 1, a - cnta, b - cntb, c - cntc),
            solveit(i + 1, a, b, c));
  return ret;
}
void solve() {
  int a, b, c;
  cin >> a >> b >> c;
  cout << solveit(1, a, b, c);
}
int main(void) {
  int tc = 1;
  cin >> tc;
  while (tc--) {
    solve();
    if (tc) cout << '\n' << flush;
  }
}
