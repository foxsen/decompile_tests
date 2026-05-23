#include <bits/stdc++.h>
using namespace std;
int N;
double R, V, W;
double s, f;
int main() {
  scanf("%d%lf%lf", &N, &R, &V);
  W = V / R;
  for (int i = 0; i < N; i++) {
    cin >> s >> f;
    double x = (f - s) / 2;
    double lb = (x - R) / V, rb = (x + R) / V;
    for (int j = 0; j < 60; j++) {
      double mb = (lb + rb) / 2;
      double val = V * mb + R * fabs(sin(W * mb));
      if (val < x)
        lb = mb;
      else
        rb = mb;
      if (rb - lb < 1E-7) break;
    }
    printf("%.10f\n", lb + rb);
  }
  return 0;
}
