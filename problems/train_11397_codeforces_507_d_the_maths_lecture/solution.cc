#include <bits/stdc++.h>
using namespace std;
long long n, m, mm, f[1100][110];
void init() { memset(f, 0, sizeof(f)); }
void work() {
  int first = 1;
  for (int i = (0); i <= (n); ++i) {
    f[i + 1][0] = f[i][0] * 10 % mm;
    for (int k = (1); k <= (9); ++k) (f[i + 1][(first * k) % m] += 1) %= mm;
    for (int j = (1); j <= (m); ++j)
      for (int k = (0); k <= (9); ++k) {
        (f[i + 1][(j + k * first) % m] += f[i][j]) %= mm;
      }
    (first *= 10) %= m;
  }
  cout << (f[n][0] - f[n - 1][0] + mm) % mm << endl;
}
int main() {
  while (cin >> n >> m >> mm) {
    init();
    work();
  }
  return 0;
}
