#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &v[i]);
  }
  long long ans = 0;
  for (int i = 0; i < n - 1; i++) {
    ans += max(0, v[i] - v[i + 1]);
  }
  cout << ans << '\n';
  return 0;
}
