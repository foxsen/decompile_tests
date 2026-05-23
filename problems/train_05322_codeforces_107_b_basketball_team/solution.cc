#include <bits/stdc++.h>
using namespace std;
int min(int x, int y) { return x < y ? x : y; }
double logComb(int n, int r) {
  if (n < r) return -1.e100;
  r = min(n - r, r);
  double res = 0;
  for (int i = (0); i < (r); ++i) res += log(n - i);
  for (int i = (0); i < (r); ++i) res -= log(i + 1);
  return res;
}
int s[1001];
int main() {
  int n, m, h;
  while (~scanf("%d%d%d", &n, &m, &h)) {
    int sum = 0;
    for (int i = (0); i < (m); ++i) {
      scanf("%d", s + i);
      sum += s[i];
    }
    h--;
    if (sum < n) {
      puts("-1.000000000");
    } else {
      double res = 0;
      for (int i = (1); i < (n); ++i)
        res += exp(logComb(s[h] - 1, i) + logComb(sum - s[h], n - i - 1) -
                   logComb(sum - 1, n - 1));
      printf("%.8f\n", res);
    }
  }
  return 0;
}
