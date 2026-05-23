#include <bits/stdc++.h>
using namespace std;
const int N = (int)1e6 + 15;
const long long inf = (long long)9e18;
const int MOD = 998244353;
const double eps = 1e-10;
const double PI = acos(-1);
inline double dcmp(double x) { return fabs(x) < eps ? 0 : (x > 0 ? 1 : -1); }
struct Node {
  long long x, y, w;
  bool operator<(const Node& b) const { return x < b.x; }
};
Node in[N], que[N];
long long a[N];
int x[N], y[N];
inline long long calc(long long xj, long long yi, long long fj) {
  return fj - xj * yi;
}
inline double cmp(const Node& a, const Node& b) {
  return (double)(b.y - a.y) / (b.x - a.x);
}
int main() {
  int n;
  while (~scanf("%d", &n)) {
    for (int i = 1; i <= n; i++) {
      scanf("%lld%lld%lld", &in[i].x, &in[i].y, &in[i].w);
    }
    sort(in + 1, in + 1 + n);
    for (int i = 1; i <= n; i++) {
      x[i] = in[i].x, y[i] = in[i].y, a[i] = in[i].w;
    }
    long long ans = 0;
    que[1] = Node{0, 0, 0};
    for (int i = 1, it = 1, tail = 1; i <= n; i++) {
      while (it + 1 <= tail && calc(que[it].x, y[i], que[it].y) <=
                                   calc(que[it + 1].x, y[i], que[it + 1].y)) {
        it++;
      }
      long long maxx = (it <= tail ? calc(que[it].x, y[i], que[it].y) : 0) +
                       1LL * x[i] * y[i] - a[i];
      ans = max(ans, maxx);
      while (tail >= 2 &&
             cmp(que[tail - 1], que[tail]) < cmp(que[tail], Node{x[i], maxx})) {
        tail--;
      }
      it = max(min(tail, it), 1);
      que[++tail] = Node{x[i], maxx};
    }
    printf("%lld\n", ans);
  }
}
