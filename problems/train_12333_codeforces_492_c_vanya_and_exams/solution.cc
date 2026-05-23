#include <bits/stdc++.h>
using namespace std;
long long n, r, avg, curr, ans;
pair<long long, long long> p[100100];
bool ok(long long mid, long long i) {
  if (curr + mid - p[i].second >= n * avg) return true;
  return false;
}
int main() {
  scanf("%lld%lld%lld", &n, &r, &avg);
  for (int i = 0; i < n; i++) {
    long long x, y;
    scanf("%lld%lld", &x, &y);
    p[i].first = y;
    p[i].second = x;
    curr += x;
  }
  if (curr >= n * avg) {
    cout << 0;
    return 0;
  }
  sort(p, p + n);
  for (int i = 0; i < n; i++) {
    if (curr + r - p[i].second == n * avg) {
      curr += r - p[i].second;
      ans += p[i].first * (r - p[i].second);
      break;
    }
    if (curr + r - p[i].second < n * avg) {
      curr += r - p[i].second;
      ans += p[i].first * (r - p[i].second);
      continue;
    }
    long long high = r, low = p[i].second;
    while (high > low) {
      long long mid = (high + low) / 2;
      if (ok(mid, i))
        high = mid;
      else
        low = mid + 1;
    }
    ans += p[i].first * (low - p[i].second);
    break;
  }
  cout << ans;
}
