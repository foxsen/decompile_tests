#include <bits/stdc++.h>
using namespace std;
const int INF = numeric_limits<int>::max();
const long long LLINF = numeric_limits<long long>::max();
const unsigned long long ULLINF = numeric_limits<unsigned long long>::max();
const double PI = acos(-1.0);
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t[50];
  long long n, k, M;
  cin >> n >> k >> M;
  long long sum = 0;
  for (int i = 0; i < k; i++) cin >> t[i], sum += t[i];
  sort(t, t + k);
  long long ans = 0;
  for (int s = 0; s <= n; s++) {
    if (sum * s > M) break;
    long long p = n - s;
    long long T = M - sum * s;
    long long cur = (k + 1) * s;
    for (int i = 0; i < k; i++) {
      long long take = min(T / t[i], p);
      cur += take;
      T -= take * t[i];
    }
    ans = max(ans, cur);
  }
  cout << ans;
  return 0;
}
