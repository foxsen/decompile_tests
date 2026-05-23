#include <bits/stdc++.h>
using namespace std;
const long long inf = 1e9 + 113;
const long long maxn = 1e5 + 113;
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k;
  cin >> n >> k;
  vector<int> s1;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    s1.push_back(a);
  }
  int ans = s1[0];
  if (k == 1) {
    for (int i = 0; i < n; i++) ans = min(ans, s1[i]);
    cout << ans;
    return 0;
  }
  int maxn = s1[0];
  for (int i = 0; i < n; i++) maxn = max(maxn, s1[i]);
  if (k >= 3) {
    cout << maxn;
    return 0;
  }
  if (k == 2) {
    cout << max(s1[0], s1[s1.size() - 1]);
    return 0;
  }
}
