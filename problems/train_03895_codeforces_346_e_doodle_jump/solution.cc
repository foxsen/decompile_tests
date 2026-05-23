#include <bits/stdc++.h>
using namespace std;
int T, N, A, P, H;
long long max_dist(long long a, long long n, long long p, int had) {
  if (a * n < p) {
    long long ans = a;
    if (had) ans = max(ans, p - a * n);
    return ans;
  }
  long long sum = a * n / p, tmp = a - p % a;
  long long first = a * (p / a - 1);
  if (first > a * n % p) sum--;
  return max_dist(min(tmp, a - tmp), sum, a, 1);
}
int main() {
  cin >> T;
  while (T--) {
    cin >> A >> N >> P >> H;
    A %= P;
    if (max_dist(A, N, P, 0) > H)
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}
