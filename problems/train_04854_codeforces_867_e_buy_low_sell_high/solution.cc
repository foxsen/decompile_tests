#include <bits/stdc++.h>
using namespace std;
int n, x;
long long ans;
multiset<int> q;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> x;
    if (!q.empty() && *q.begin() < x) {
      ans += x - *q.begin();
      q.erase(q.begin());
      q.insert(x);
    }
    q.insert(x);
  }
  cout << ans;
}
