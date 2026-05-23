#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n, m, k;
  cin >> n >> m >> k;
  queue<int> q;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) cin >> a[i];
  sort(a.begin(), a.end());
  int curr = 0;
  int res = 0;
  for (int t = m; t <= 1000000; ++t) {
    while (!q.empty() && q.front() < t - m + 1) q.pop();
    while (curr < n && a[curr] <= t) {
      if ((int)q.size() < k - 1)
        q.push(a[curr]);
      else
        ++res;
      ++curr;
    }
  }
  cout << res << endl;
  return 0;
}
