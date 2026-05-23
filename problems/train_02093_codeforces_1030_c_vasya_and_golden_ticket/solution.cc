#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  int n;
  cin >> n;
  string s;
  cin >> s;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    a[i] = s[i] - '0';
  }
  int sum = 0;
  for (int k = 0; k + 1 < n; ++k) {
    sum += a[k];
    int c_sum = 0;
    for (int i = k + 1; i < n; ++i) {
      if (a[i] == 0) continue;
      if (c_sum == sum) {
        c_sum = 0;
      }
      c_sum += a[i];
      if (c_sum > sum) {
        break;
      }
    }
    if (c_sum == sum) {
      cout << "YES";
      return 0;
    }
  }
  cout << "NO";
}
