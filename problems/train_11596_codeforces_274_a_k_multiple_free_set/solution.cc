#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int n, k;
  cin >> n >> k;
  if (k == 1) {
    cout << n;
    return 0;
  }
  if (n == 1) {
    cout << 1;
    return 0;
  }
  set<long long int> s;
  for (long long int i = 0; i < n; i++) {
    long long int x;
    cin >> x;
    s.insert(x);
  }
  for (auto it = s.begin(); it != s.end(); it++) {
    long long int t = *it;
    if (s.find(t * k) != s.end()) {
      s.erase(s.find(t * k));
    }
  }
  int ans = s.size();
  cout << ans;
}
