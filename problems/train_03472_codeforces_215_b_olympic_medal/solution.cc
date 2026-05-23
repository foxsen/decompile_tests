#include <bits/stdc++.h>
using namespace std;
double r1[5000], p1[5000], p2[5000];
int main() {
  double a, b;
  int n1, n2, n3;
  scanf("%d", &n1);
  for (int i = 0; i < n1; ++i) scanf("%lf", &r1[i]);
  scanf("%d", &n2);
  for (int i = 0; i < n2; ++i) scanf("%lf", &p1[i]);
  scanf("%d", &n3);
  for (int i = 0; i < n3; ++i) scanf("%lf", &p2[i]);
  scanf("%lf%lf", &a, &b);
  sort(r1, r1 + n1);
  double R1 = r1[n1 - 1];
  R1 *= R1;
  a /= b;
  double res = 0;
  for (int i = 0; i < n2; ++i) {
    for (int j = 0; j < n3; ++j) {
      double P1 = p1[i], P2 = p2[j];
      double aux = (P1 * R1 / P2) / (a + P1 / P2);
      res = max(res, aux);
    }
  }
  printf("%.7lf\n", sqrt(res));
  return 0;
}
