#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 5;
long long a[N], n;
long long x;
long long sum[N], sz[N];
long long c2(long long a) { return 1LL * a * (a - 1) / 2; }
bool cmp(pair<long long, long long> v, pair<long long, long long> u) {
  return v < u;
}
int main() {
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i + n] = a[i];
  }
  n *= 2;
  for (int i = 0; i < n; i++) {
    sz[i + 1] = sz[i] + a[i];
    sum[i + 1] = sum[i] + (1LL * (a[i] + 1) * a[i] / 2);
  }
  vector<pair<long long, long long> > vec;
  vec.push_back({0, 0});
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] >= x)
      ans = max(ans, c2(a[i] + 1) - c2(a[i] - x + 1));
    else {
      int low = -1, high = i;
      pair<long long, long long> best = {-1, -1};
      while (high - low > 1) {
        int mid = (low + high) >> 1;
        if (sz[i + 1] - sz[mid] <= x)
          high = mid;
        else
          low = mid;
      }
      int j = high;
      long long b = sum[i + 1] - sum[j], r = sz[i + 1] - sz[j];
      if (j && x - r > 0) {
        r = min(x - r, a[j - 1]);
        ans = max(ans, b + c2(a[j - 1] + 1) - c2(a[j - 1] - r + 1));
      } else
        ans = max(ans, b);
    }
    vec.push_back({sz[i + 1], i + 1});
  }
  cout << ans << "\n";
}
