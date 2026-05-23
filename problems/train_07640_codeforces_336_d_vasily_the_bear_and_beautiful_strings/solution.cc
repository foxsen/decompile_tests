#include <bits/stdc++.h>
using namespace std;
const int N = 2e6;
const int INF = 1e9 + 9;
const int B = 1e9 + 7;
void relax(long long &a, const long long &b) { a = (a + b % B) % B; }
long long pwr(long long a, long long b) {
  long long res = 1;
  while (b) {
    if (b & 1) res = (res * a) % B;
    a = (a * a) % B, b >>= 1;
  }
  return res;
}
long long fact[N], rfact[N], pwr2[N];
long long Cnk(long long n, long long k) {
  if (k < 0 || n < k) return 0;
  return ((fact[n] * rfact[k]) % B * rfact[n - k]) % B;
}
int d(int n, int m, int g) {
  if (n + m == 1) {
    int f = (n ? 0 : 1);
    return f == g;
  }
  if (g == 1)
    return n ? d(n - 1, m, 0) : 0;
  else
    return ((n ? d(n - 1, m, 1) : 0) + Cnk(n + m - 1, n)) % B;
}
int n, m, g;
int main() {
  ios_base ::sync_with_stdio(0);
  cin.tie(0);
  fact[0] = 1, rfact[0] = 1;
  for (int i = int(1); i <= int(2e5); ++i) {
    fact[i] = (fact[i - 1] * i) % B;
    rfact[i] = pwr(fact[i], B - 2);
  }
  cin >> n >> m >> g;
  long long ans = d(n, m, g);
  cout << ans << "\n";
  return 0;
}
