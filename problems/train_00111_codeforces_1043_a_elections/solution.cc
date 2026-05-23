#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans = max(ans, a[i]);
  }
  for (int i = ans; i < 1000; i++) {
    int cur = 0;
    for (int j = 0; j < n; j++) {
      cur += i - a[j] * 2;
    }
    if (cur > 0) {
      cout << i;
      return 0;
    }
  }
  return 0;
}
