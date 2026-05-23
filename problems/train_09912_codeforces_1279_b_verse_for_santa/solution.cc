#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    long long int n, s, sum = 0;
    cin >> n >> s;
    long long int a[n], mx = 0;
    vector<long long int> ans;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    bool flag = false;
    for (int i = 0; i < n; i++) {
      sum += a[i];
      mx = max(mx, a[i]);
      ans.push_back(a[i]);
      if (sum > s) {
        flag = true;
        break;
      }
    }
    if (!flag)
      cout << 0 << '\n';
    else {
      auto x = find(ans.begin(), ans.end(), mx) - ans.begin();
      cout << x + 1 << '\n';
    }
  }
}
