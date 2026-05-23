#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long> > v1, v2;
long long n, s;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cin >> n >> s;
  long long sum1 = 0;
  long long sum2 = 0;
  long long ans = 0;
  for (long long i = 1; i <= n; i++) {
    long long x, y, z;
    cin >> x >> y >> z;
    if (y > z) {
      sum1 += x;
      ans += x * y;
      v1.push_back(make_pair(y - z, x));
    } else {
      sum2 += x;
      ans += x * z;
      v2.push_back(make_pair(z - y, x));
    }
  }
  long long temp1 = 0, temp2 = 0;
  if ((sum1 % s + sum2 % s) > s) {
    cout << ans << endl;
    return 0;
  }
  sum1 = sum1 % s;
  sum2 = sum2 % s;
  sort(v1.begin(), v1.end());
  for (int i = 0; i < v1.size(); i++) {
    temp1 += min(sum1, v1[i].second) * v1[i].first;
    sum1 -= min(sum1, v1[i].second);
  }
  sort(v2.begin(), v2.end());
  for (int i = 0; i < v2.size(); i++) {
    temp2 += min(sum2, v2[i].second) * v2[i].first;
    sum2 -= min(sum2, v2[i].second);
  }
  cout << ans - min(temp1, temp2) << endl;
  return 0;
}
