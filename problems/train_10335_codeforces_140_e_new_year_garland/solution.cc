#include <bits/stdc++.h>
using namespace std;
long long n, m, p, l[1000100], a[5050][5050], x[5050], y[5050], h[5050],
    f[5050];
void pre(void) {
  a[1][1] = 1;
  for (long long i = 2; i < 5050; ++i)
    for (long long j = 2; j <= i; ++j)
      a[i][j] = a[i - 1][j - 1] + (j - 1) * a[i - 1][j], a[i][j] %= p;
}
void read(void) {
  cin >> n >> m >> p;
  for (long long i = 0; i < n; ++i) cin >> l[i];
  h[0] = 1;
  f[0] = 1;
  for (long long i = 1; i < 5050; ++i)
    h[i] = (h[i - 1] * (m - i + 1)) % p, f[i] = (f[i - 1] * i) % p;
}
void kill(void) {
  long long s = 0;
  for (long long i = 1; i <= l[0]; ++i) x[i] = (a[l[0]][i] * h[i]) % p;
  for (long long i = 1; i <= l[0]; ++i) s += x[i], s %= p;
  for (long long i = 1; i < n; ++i) {
    for (long long j = 1; j <= l[i]; ++j) {
      y[j] = h[j] * s - f[j] * x[j];
      y[j] %= p;
      y[j] *= a[l[i]][j];
      y[j] %= p;
    }
    s = 0;
    for (long long j = 0; j <= l[i + 1]; ++j) x[j] = 0;
    for (long long j = 1; j <= l[i]; ++j) x[j] = y[j], s += x[j], s %= p;
  }
  s %= p;
  if (s < 0) s += p;
  cout << s << "\n";
}
int main() {
  ios_base::sync_with_stdio(0);
  read();
  pre();
  kill();
  return 0;
}
