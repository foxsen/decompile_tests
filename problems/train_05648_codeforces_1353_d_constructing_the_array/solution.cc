#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    vector<long long int> v(n + 1);
    priority_queue<pair<long long int, pair<long long int, long long int>>> q;
    q.push({n, {1, n}});
    long long int cnt = 1;
    while (!q.empty()) {
      auto x = q.top();
      q.pop();
      long long int mid = (x.second.first + x.second.second + 1) / 2;
      v[mid] = cnt;
      cnt++;
      if ((mid - 1 - (x.second.first) + 1) > 0) {
        q.push({mid - 1 - (x.second.first) + 1, {x.second.first, mid - 1}});
      }
      if ((x.second.second - (mid + 1) + 1) > 0) {
        q.push({x.second.second - (mid + 1) + 1, {mid + 1, x.second.second}});
      }
    }
    for (long long int i = n; i >= 1; i--) {
      cout << v[i] << " ";
    }
    cout << "\n";
  }
  return 0;
}
