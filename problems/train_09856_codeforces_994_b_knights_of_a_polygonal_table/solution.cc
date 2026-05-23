#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  long long p[n], c[n];
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  vector<pair<long long, pair<long long, int> > > v;
  for (int i = 0; i < n; i++) {
    v.push_back(make_pair(p[i], make_pair(c[i], i)));
  }
  sort(v.begin(), v.end());
  multiset<long long> s;
  long long ans[n];
  for (int i = 0; i < n; i++) ans[i] = 0;
  for (int i = 0; i < n; i++) {
    int t = k;
    auto it = s.rbegin();
    long long temp;
    while (it != s.rend() and t > 0) {
      temp = *it;
      ans[v[i].second.second] += temp;
      it++;
      t--;
    }
    ans[v[i].second.second] += v[i].second.first;
    s.insert(v[i].second.first);
  }
  for (int i = 0; i < n; i++) cout << ans[i] << " ";
  return 0;
}
