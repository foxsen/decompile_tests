#include <bits/stdc++.h>
using namespace std;
double p[100010];
int main(void) {
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    cin >> p[i];
  }
  double x = 0.0, ans = 0.0;
  for (int i = 0; i < N; ++i) {
    x = x * p[i] + p[i];
    ans += 2.0 * x;
    ans -= p[i];
  }
  printf("%.9f", ans);
  return 0;
}
