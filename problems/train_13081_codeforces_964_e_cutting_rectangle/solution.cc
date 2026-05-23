#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) {
  if (a % b == 0)
    return b;
  else
    return gcd(b, a % b);
}
int main() {
  int n;
  scanf("%d", &n);
  map<long long, map<long long, long long>> cnt;
  long long g = 1;
  bool first = true;
  for (int i = 0; i < n; i += 1) {
    long long w, h, c;
    scanf("%lld %lld %lld", &w, &h, &c);
    cnt[w][h] = c;
    if (first) {
      g = c;
      first = false;
    } else
      g = gcd(g, c);
  }
  for (auto itr = cnt.begin(); itr != cnt.end(); itr++) {
    auto jtr = itr;
    if (++jtr == cnt.end()) continue;
    auto pi = itr->second.begin();
    auto pj = jtr->second.begin();
    long long gg = gcd(pi->second, pj->second);
    long long a = pi->second / gg;
    long long b = pj->second / gg;
    while (pi != itr->second.end() && pj != jtr->second.end()) {
      if (pi->first != pj->first) {
        cout << 0 << endl;
        return 0;
      }
      gg = gcd(pi->second, pj->second);
      if (a != pi->second / gg || b != pj->second / gg) {
        cout << 0 << endl;
        return 0;
      }
      pi++;
      pj++;
    }
    if (pi != itr->second.end() || pj != jtr->second.end()) {
      cout << 0 << endl;
      return 0;
    }
  }
  int ans = 0;
  for (long long i = 1; i * i <= g; i += 1) {
    if (g % i == 0) {
      if (i * i != g)
        ans += 2;
      else
        ans += 1;
    }
  }
  cout << ans << endl;
}
