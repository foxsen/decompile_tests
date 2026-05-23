#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b) {
  return (a.first > b.first || (a.first == b.first && a.second < b.second));
}
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  vector<pair<int, int> > c;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    c.push_back({a[i], i});
  }
  int m;
  cin >> m;
  sort(c.begin(), c.end(), cmp);
  for (int q = 0; q < m; q++) {
    vector<int> ans;
    int k, pos;
    cin >> k >> pos;
    pos--;
    for (int i = 0; i < k; i++) {
      ans.push_back(c[i].second);
    }
    sort(ans.begin(), ans.end());
    cout << a[ans[pos]] << "\n";
  }
  cout << endl;
  return 0;
}
