#include <bits/stdc++.h>
using namespace std;
const long long OO = (long long)(4e18) + 9;
const long long MOD = (long long)(1e9) + 7;
const int oo = 2147483647;
const double EPS = 1e-8;
const double PI = acos(-1.0);
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int dX[] = {1, 0, -1, 0, 1, -1, 1, -1};
int dY[] = {0, 1, 0, -1, 1, 1, -1, -1};
string abc = "abcdefghijklmnopqrstuvwxyz";
string vowels = "aeiou";
int dcmp(long double d1, long double d2) {
  return fabs(d1 - d2) <= EPS ? 0 : d1 > d2 ? 1 : -1;
}
long long gcd(long long x, long long y) { return !y ? x : gcd(y, x % y); }
long long lcm(long long a, long long b) { return a * (b / gcd(a, b)); }
int ord(int r, int c, int nCol) { return (nCol * r) + c + 1; }
pair<int, int> rord(int n, int nCol) {
  int r = n % nCol, c = n / nCol;
  if (n % nCol == 0) c--, r = nCol;
  return pair<int, int>(r, c);
}
long long poww(long long num, long long p, long long md) {
  num %= md;
  long long ret = 1;
  while (p > 0) {
    if (p & 1) ret = (ret * num) % md;
    num = (num * num) % md;
    p >>= 1;
  }
  return ret;
}
long long nCr(long long n, long long r) {
  if (n < r) return 0;
  if (r == 0) return 1;
  return n * nCr(n - 1, r - 1) / r;
}
string pattern(long long num) {
  string ret = "", second = "";
  while (num) ret += (num % 10) % 2 + '0', num /= 10;
  reverse(ret.begin(), ret.end());
  int flag = 0;
  for (int i = 0; i < (int)ret.size(); i++) {
    if (ret[i] == '1') flag = 1;
    if (flag) second += ret[i];
  }
  if (second == "") second = "0";
  return second;
}
int main() {
  int t;
  scanf("%d", &t);
  map<string, int> cnt;
  string cmd, reg, pat, regt;
  long long n;
  while (t--) {
    cin >> cmd;
    if (cmd == "+")
      scanf("%lld", &n), pat = pattern(n), cnt[pat]++;
    else if (cmd == "-")
      scanf("%lld", &n), pat = pattern(n), cnt[pat]--;
    else {
      cin >> reg;
      regt = "";
      int flag = 0;
      for (int i = 0; i < (int)reg.size(); i++) {
        if (reg[i] == '1') flag = 1;
        if (flag) regt += reg[i];
      }
      if (regt == "") regt = "0";
      cout << cnt[regt] << endl;
    }
  }
  return 0;
}
