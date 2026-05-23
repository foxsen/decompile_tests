#include <bits/stdc++.h>
using namespace std;
priority_queue<pair<int, int> > hp;
int a[500000];
int p[500000];
int n, k;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long ans = 0, s = 0;
  for (int i = 1; i <= k; i++) {
    ans += s;
    hp.push(make_pair(a[i], i));
    s += a[i];
  }
  for (int i = k + 1; i <= n + k; i++) {
    ans += s;
    if (i <= n) {
      hp.push(make_pair(a[i], i));
      s += a[i];
    }
    pair<int, int> c = hp.top();
    p[c.second] = i;
    hp.pop();
    s -= c.first;
  }
  cout << ans << "\n";
  for (int i = 1; i <= n; i++) cout << p[i] << " ";
  cout << "\n";
  return 0;
}
