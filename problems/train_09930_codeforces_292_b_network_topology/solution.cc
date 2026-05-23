#include <bits/stdc++.h>
using namespace std;
const long long N = 1e5 + 7;
const long long inf = 1e9 + 7;
const long long mod = 1e9 + 7;
int n;
int m;
int x;
int y;
vector<int> g[N];
int main() {
  ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; i++) {
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int badbus = 0, cnt = 0;
  for (int i = 1; i <= n; i++) {
    badbus |= (g[i].empty());
    if ((int)g[i].size() == 1) {
      cnt++;
      continue;
    }
    badbus |= ((int)g[i].size() != 2);
  }
  if (cnt == 2 && badbus == 0) {
    cout << "bus topology\n";
    return 0;
  }
  int badring = 0;
  for (int i = 1; i <= n; i++) {
    badring |= ((int)g[i].size() != 2);
  }
  if (badring == 0) {
    cout << "ring topology\n";
    return 0;
  }
  cnt = 0;
  int badstar = 0;
  for (int i = 1; i <= n; i++) {
    if ((int)g[i].size() == n - 1) {
      cnt++;
      continue;
    }
    badstar |= ((int)g[i].size() != 1);
  }
  if (cnt == 1 && badstar == 0) {
    cout << "star topology\n";
    return 0;
  }
  cout << "unknown topology\n";
}
