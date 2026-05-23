#include <bits/stdc++.h>
using namespace std;
vector<pair<long long, long long>> v;
int main() {
  long long n, x, sum = 0, ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    sum += x;
    v.push_back(make_pair(x, sum));
  }
  if (sum % 3 == 0) {
    long long a = sum / 3;
    long long b = a * 2;
    x = 0;
    for (int i = 0; i < n - 1; i++) {
      if (v[i].second == b) ans += x;
      if (v[i].second == a) x++;
    }
  }
  cout << ans << endl;
  return 0;
}
