#include <bits/stdc++.h>
using namespace std;
long long fun(long long a) {
  long long ans = 0;
  if (a == 1)
    ans = 1;
  else if (a % 2 == 0) {
    long long j = a / 2;
    ans = j * 3;
  } else {
    long long j = a / 2;
    ans = (1 + (3 * j));
  }
  return ans;
}
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long a, b, c, ans = 0;
    cin >> a >> b >> c;
    vector<long long> vec;
    vec.push_back(a);
    vec.push_back(b);
    vec.push_back(c);
    sort(vec.begin(), vec.end());
    if ((vec[0] + vec[1]) <= vec[2]) {
      cout << vec[0] + vec[1] << endl;
    } else {
      long long ans = 0;
      long long t = vec[2] - vec[1];
      vec[2] -= t;
      vec[0] -= t;
      ans += t;
      t = vec[1] - vec[0];
      ans += t;
      vec[2] -= t;
      vec[1] -= t;
      ans += fun(vec[0]);
      cout << ans << endl;
    }
  }
}
