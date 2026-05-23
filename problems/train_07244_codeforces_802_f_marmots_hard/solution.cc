#include <bits/stdc++.h>
using namespace std;
struct edge {
  int u, v;
  long long w;
};
long long MOD = 1000000007;
long long _MOD = 1000000009;
double EPS = 1e-10;
const int N = 250;
double F[10001];
double uniform(int N, vector<int> a, int p) {
  double sum = 0;
  for (int i = 0; i < N; i++) {
    if (0 <= a[i] && a[i] <= p * 2)
      sum += log(1.0 / (p * 2 + 1));
    else
      return -DBL_MAX;
  }
  return sum;
}
double poisson(int N, vector<int> a, int p) {
  double sum = 0;
  for (int i = 0; i < N; i++) {
    sum += log(p) * a[i];
    sum += -p;
    sum -= F[a[i]];
  }
  return sum;
}
int main() {
  for (int x = 1; x <= 10000; x++) F[x] = F[x - 1] + log(x);
  int T;
  cin >> T;
  while (T--) {
    vector<int> a(N);
    for (int i = 0; i < N; i++) scanf("%d", &a[i]);
    double ma1 = -DBL_MAX, ma2 = -DBL_MAX;
    for (int p = 1; p <= 1000; p++) {
      for (int i = 0; i < N; i++) a[i] += p;
      bool ok = true;
      for (int i = 0; i < N; i++)
        if (a[i] < 0) ok = false;
      if (ok) {
        ma1 = max(ma1, uniform(N, a, p));
        ma2 = max(ma2, poisson(N, a, p));
      }
      for (int i = 0; i < N; i++) a[i] -= p;
    }
    cout << (ma1 > ma2 ? "uniform" : "poisson") << endl;
  }
}
