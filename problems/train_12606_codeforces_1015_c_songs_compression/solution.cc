#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 2;
const int M = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  long long n, m;
  cin >> n >> m;
  vector<pair<int, int> > v(n);
  long long nw = 0, cw = 0;
  for (int i = 0; i < n; i++) {
    cin >> v[i].first >> v[i].second;
    nw += v[i].first;
    cw += v[i].second;
  }
  sort(v.begin(), v.end(),
       [](const pair<int, int> p1, const pair<int, int> p2) {
         int x = p1.first - p1.second;
         int y = p2.first - p2.second;
         return x > y;
       });
  if (nw <= m) {
    cout << 0;
  } else if (cw > m) {
    cout << -1;
  } else {
    long long yo = nw;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      if (yo - v[i].first + v[i].second > m) {
        ans++;
        yo = yo - v[i].first + v[i].second;
      } else {
        ans++;
        break;
      }
    }
    cout << ans;
  }
  return 0;
}
