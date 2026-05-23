#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, l, r;
  cin >> n >> l >> r;
  vector<long long> a, p;
  for (long long i = 0; i < n; ++i) {
    long long b;
    cin >> b;
    a.push_back(b);
  }
  for (long long i = 0; i < n; ++i) {
    long long b;
    cin >> b;
    p.push_back(b);
  }
  vector<tuple<long long, long long, long long>> wow;
  for (long long i = 0; i < n; ++i) {
    wow.push_back(make_tuple(p[i], a[i], i));
  }
  sort(wow.begin(), wow.end());
  vector<pair<long long, long long>> ans;
  ans.push_back(make_pair(get<2>(wow[0]), l - get<1>(wow[0])));
  for (long long i = 1; i < n; ++i) {
    if (r - get<1>(wow[i]) <= ans[i - 1].second) {
      cout << -1 << endl;
      return 0;
    } else if (l - get<1>(wow[i]) > ans[i - 1].second) {
      ans.push_back(make_pair(get<2>(wow[i]), l - get<1>(wow[i])));
    } else {
      ans.push_back(make_pair(get<2>(wow[i]), ans[i - 1].second + 1));
    }
  }
  sort(ans.begin(), ans.end());
  vector<long long> checker;
  for (long long i = 0; i < n; ++i) {
    long long true_value = ans[i].second + a[i];
    if (true_value - ans[i].second < l || true_value - ans[i].second > r) {
      cout << -1 << endl;
      return 0;
    } else
      checker.push_back(true_value);
  }
  for (long long i = 0; i < n; ++i) {
    cout << checker[i] << " ";
  }
  cout << endl;
  return 0;
}
