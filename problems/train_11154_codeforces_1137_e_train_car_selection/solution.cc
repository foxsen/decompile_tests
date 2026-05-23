#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 10;
pair<long long, long long> p[N];
int n, m, r = 1;
long long k = 0, b = 0;
double get_k(pair<long long, long long> a, pair<long long, long long> b) {
  return 1.0 * (a.second - b.second) / (a.first - b.first);
}
long long calc(pair<long long, long long> x) {
  return k * x.first + x.second + b;
}
int main() {
  scanf("%d%d", &n, &m);
  p[1] = make_pair(0, 0);
  r = 1;
  while (m--) {
    int opt;
    scanf("%d", &opt);
    if (opt == 1) {
      r = 1;
      p[1] = make_pair(0, 0);
      k = b = 0;
      int tmp;
      scanf("%d", &tmp);
      n += tmp;
    } else if (opt == 2) {
      pair<long long, long long> now = make_pair(n, -(n * k + b));
      while (r > 1 && get_k(now, p[r]) <= get_k(p[r], p[r - 1])) r--;
      p[++r] = now;
      int tmp;
      scanf("%d", &tmp);
      n += tmp;
    } else {
      int x, y;
      scanf("%d%d", &x, &y);
      b += x;
      k += y;
    }
    while (r > 1 && calc(p[r]) >= calc(p[r - 1])) r--;
    printf("%lld %lld\n", p[r].first + 1, calc(p[r]));
  }
}
