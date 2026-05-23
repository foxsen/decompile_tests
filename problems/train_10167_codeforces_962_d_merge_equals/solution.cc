#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1;
long long a[N];
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  priority_queue<pair<long long, int>, vector<pair<long long, int>>,
                 greater<pair<long long, int>>>
      q;
  for (int i = 1; i <= n; ++i) {
    int x;
    cin >> x;
    q.push({x, i});
  }
  long long ans(0);
  while (!q.empty()) {
    pair<long long, int> p = q.top();
    q.pop();
    if (q.top().first == p.first && !q.empty()) {
      int x = q.top().second;
      q.pop();
      q.push({p.first * 2, x});
    } else {
      ans++;
      a[p.second] = p.first;
    }
  }
  cout << ans << endl;
  for (int i = 1; i <= n; ++i)
    if (a[i] != 0) cout << a[i] << ' ';
  cout << endl;
  return 0;
}
