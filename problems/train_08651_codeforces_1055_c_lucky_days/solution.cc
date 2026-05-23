#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000000 + 5;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long la, ra, ta, lb, rb, tb;
long long cal(long long la, long long ra, long long lb, long long rb) {
  long long mn = max(la, lb), mx = min(ra, rb);
  return max(0ll, mx - mn + 1);
}
int main() {
  cin >> la >> ra >> ta >> lb >> rb >> tb;
  if (la > lb) swap(la, lb), swap(ra, rb);
  long long g = gcd(ta, tb);
  long long d = (lb - la) / g * g;
  lb -= d;
  rb -= d;
  long long ans = cal(la, ra, lb, rb);
  ans = max(ans, cal(la, ra, lb - g, rb - g));
  cout << ans;
  return 0;
}
