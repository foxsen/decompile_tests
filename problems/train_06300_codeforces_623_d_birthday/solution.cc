#include <bits/stdc++.h>
using namespace std;
const int N = 110;
double p[N];
int n;
struct P {
  long double qk;
  int id;
  inline P(long double qk = 0.0, int id = 0) : qk(qk), id(id) {}
  inline long double calc() const { return (1 - qk * (1 - p[id])) / (1 - qk); }
  inline bool operator<(const P& o) const { return calc() < o.calc(); }
};
int main() {
  while (scanf("%d", &n) == 1) {
    long double q = 1.0;
    priority_queue<P> que;
    for (int i = 0; i < (n); ++i) {
      scanf("%lf", p + i);
      p[i] /= 100;
      q *= p[i];
      que.push(P(1 - p[i], i));
    }
    if (n == 1) {
      puts("1");
      continue;
    }
    long double ans = n + (1 - q);
    for (int i = n + 1; i <= 500000; ++i) {
      P tmp = que.top();
      que.pop();
      q *= tmp.calc();
      ans += 1 - q;
      tmp.qk *= (1 - p[tmp.id]);
      que.push(tmp);
    }
    printf("%.10f\n", (double)ans);
  }
  return 0;
}
