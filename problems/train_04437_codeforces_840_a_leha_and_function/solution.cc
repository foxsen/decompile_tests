#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 20;
int n, a[maxn], b[maxn], ans[maxn];
vector<pair<int, int> > v;
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int j = 0; j < n; j++) {
    cin >> b[j];
    v.push_back(pair<int, int>(b[j], j));
  }
  sort(a, a + n, greater<int>());
  sort(v.begin(), v.end());
  for (int i = 0; i < n; i++) {
    ans[v[i].second] = a[i];
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << ' ';
  }
  cout << endl;
  return 0;
}
