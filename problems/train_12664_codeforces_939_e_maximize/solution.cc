#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 1;
const int M = 1e9 + 7;
const double eps = 1e-6;
const double PI(acos(-1.0));
int q, t;
double a[N], b[N];
double f(int l) { return (b[l] + a[t]) / (l + 1.0); }
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> q;
  int l = 0;
  for (int i = 0; i < (q); i++) {
    int op;
    cin >> op;
    if (op == 1) {
      cin >> a[++t];
      b[t] = b[t - 1] + a[t];
    } else {
      while (l < t - 1 && f(l + 1) < f(l)) l++;
      printf("%.9lf\n", a[t] - f(l));
    }
  }
}
