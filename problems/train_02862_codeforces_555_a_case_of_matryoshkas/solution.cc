#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return (b == 0 ? a : gcd(b, a % b)); }
long long lcm(long long a, long long b) { return ((a * b) / gcd(a, b)); }
long long pw(long long b, long long p) {
  if (!p) return 1;
  long long sq = pw(b, p / 2);
  sq *= sq;
  if (p % 2) sq *= b;
  return sq;
}
long long sd(long long x) { return x < 10 ? x : x % 10 + sd(x / 10); }
double sq(double x) {
  for (long long i = 0; i < x; i++)
    if ((double)i * i > x) return (i - 1);
  return double(1);
}
int main() {
  int n, k;
  cin >> n >> k;
  long long cnt = k - 1;
  vector<vector<int>> v(k);
  vector<int> index(k);
  vector<bool> c(n, false);
  for (long long i = 0; i < k; i++) {
    int x;
    cin >> x;
    v[i].resize(x);
    for (long long j = 0; j < x; j++) cin >> v[i][j];
  }
  for (long long i = 0; i < k; i++) {
    if (v[i][0] == 1) {
      for (long long j = 0; j < v[i].size() - 1; j++)
        if (v[i][j + 1] - 1 != v[i][j]) {
          cnt += 2 * (v[i].size() - j - 1);
          break;
        }
      continue;
    }
    cnt += 2 * (v[i].size() - 1);
  }
  cout << cnt;
}
