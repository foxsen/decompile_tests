#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
string toBin(long long a) {
  string res = "";
  while (a) {
    res += char((a & 1) + '0');
    a >>= 1;
  }
  reverse(res.begin(), res.end());
  return res;
}
const int mod = 1e9 + 7;
long long expo(long long base, long long pow) {
  long long ans = 1;
  while (pow != 0) {
    if (pow & 1 == 1) {
      ans = ans * base;
      ans = ans % mod;
    }
    base *= base;
    base %= mod;
    pow /= 2;
  }
  return ans;
}
double pi = 3.141592653589793238462643;
double error = 0.0000001;
const int M = 100001;
pair<long long, long long> best;
inline long long po(long long x) { return x * x * x; }
void rec(long long m, long long blocks, long long tot) {
  if (m == 0) {
    best = max(best, make_pair(blocks, tot));
    return;
  }
  long long x = 1;
  while (po(x + 1) <= m) {
    x++;
  }
  rec(m - po(x), blocks + 1, tot + po(x));
  if (x >= 1) {
    rec(po(x) - 1 - po(x - 1), blocks + 1, tot + po(x - 1));
  }
}
int main() {
  long long m;
  cin >> m;
  best = make_pair(0, 0);
  rec(m, 0, 0);
  cout << best.first << " " << best.second;
}
