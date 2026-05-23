#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
const int MAXN = 100000;
const int MAXP = 10000000;
int pw(int x, int n, int mod) {
  int ret = 1;
  while (true) {
    if (n & 1) ret = (long long)ret * x % mod;
    if ((n >>= 1) == 0) return ret;
    x = (long long)x * x % mod;
  }
}
int n, modlim;
char sa[MAXN + 1];
char sb[MAXN + 1];
bool isp[MAXP + 1];
vector<int> getpol(int d) {
  vector<int> pol(d, 0);
  for (int i = (0); i < (n); ++i) pol[i % d] += ((int)sa[i]) - ((int)sb[i]);
  return pol;
}
int eval(const vector<int> &pol, int r, int mod) {
  int ret = 0, x = 1;
  for (int i = (0); i < (((int)(pol).size())); ++i) {
    ret = (ret + (long long)pol[i] * x) % mod;
    x = (long long)x * r % mod;
  }
  if (ret < 0) ret += mod;
  return ret;
}
pair<int, int> solve() {
  for (int i = (0); i <= (MAXP); ++i) isp[i] = true;
  isp[0] = isp[1] = false;
  for (int i = (2); i <= (MAXP); ++i)
    if (isp[i])
      for (int j = i + i; j <= MAXP; j += i) isp[j] = false;
  for (int d = (0); d <= (MAXP); ++d)
    if (d % 2 == 1 && isp[d]) {
      vector<int> pol = getpol(d);
      for (int p = 1; p <= MAXP; p += d)
        if (isp[p] && p >= modlim) {
          int r = -1;
          for (int i = (2); i < (p - 2); ++i) {
            int cur = pw(i, (p - 1) / d, p);
            if (cur != 1) {
              r = cur;
              break;
            }
          }
          assert(r != -1);
          for (int i = (0); i < (d); ++i) {
            int x = pw(r, i, p);
            if (x < 2 || x > p - 2) continue;
            assert(pw(x, d, p) == 1);
            if (eval(pol, x, p) == 0) return make_pair(x, p);
          }
        }
    }
  assert(false);
  return make_pair(-1, -1);
}
void run() {
  scanf("%d%d", &n, &modlim);
  scanf("%s", &sa);
  assert(strlen(sa) == n);
  scanf("%s", &sb);
  assert(strlen(sb) == n);
  pair<int, int> ans = solve();
  printf("%d %d\n", ans.second, ans.first);
}
int main() {
  run();
  return 0;
}
