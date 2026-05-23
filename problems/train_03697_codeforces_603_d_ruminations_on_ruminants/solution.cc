#include <bits/stdc++.h>
using namespace std;
const int N = 2010;
long long a[N], b[N], c[N];
int n;
long long gcd(long long a, long long b) { return b == 0 ? a : gcd(b, a % b); }
int calc(vector<pair<long long, long long> > slopes) {
  sort(slopes.begin(), slopes.end());
  int ans = 0;
  for (int i = 0; i < slopes.size(); ++i) {
    int j = i + 1;
    while (j < slopes.size() && slopes[j] == slopes[i]) {
      j++;
    }
    ans += (j - i) * (j - i - 1) / 2;
    i = j - 1;
  }
  return ans;
}
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i] >> b[i] >> c[i];
  }
  long long ans = 0;
  int cnt = 0;
  for (int i = 0; i < n; ++i) {
    if (c[i] == 0) {
      cnt++;
    }
  }
  if (cnt == 2) {
    ans += n - 2;
  }
  for (int i = 0; i < n; ++i) {
    if (c[i] != 0) {
      pair<long long, long long> x(-c[i] * a[i], a[i] * a[i] + b[i] * b[i]);
      pair<long long, long long> y(-c[i] * b[i], a[i] * a[i] + b[i] * b[i]);
      vector<pair<long long, long long> > slopes;
      for (int j = i + 1; j < n; ++j) {
        if (c[j] != 0) {
          pair<long long, long long> xx(-c[j] * a[j],
                                        a[j] * a[j] + b[j] * b[j]);
          pair<long long, long long> yy(-c[j] * b[j],
                                        a[j] * a[j] + b[j] * b[j]);
          pair<long long, long long> kx(
              xx.first * x.second - xx.second * x.first, xx.second * x.second);
          pair<long long, long long> ky(
              yy.first * y.second - yy.second * y.first, yy.second * y.second);
          long long g = gcd(abs(kx.first), abs(ky.first));
          long long aa = kx.first / g;
          long long bb = ky.first / g;
          if (aa < 0 || (aa == 0 && bb < 0)) {
            aa = -aa;
            bb = -bb;
          }
          slopes.push_back(make_pair(aa, bb));
        }
      }
      if (slopes.size() > 0) {
        ans += calc(slopes);
      }
    }
  }
  cout << ans << endl;
}
