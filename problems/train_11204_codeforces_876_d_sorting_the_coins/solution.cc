#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  set<int> s;
  for (int i = 1; i <= n; i++) {
    s.insert(i);
  }
  s.insert(0);
  long long ans = 1;
  cout << ans << " ";
  for (int i = 1; i <= n; i++) {
    int x;
    scanf("%d", &x);
    s.erase(x);
    int temp = x;
    auto low = s.lower_bound(temp);
    auto high = s.upper_bound(temp);
    if ((low != s.begin()) && (high != s.end())) {
      low--;
      ans -= (temp - *low - 1);
      ans -= (*high - temp - 1);
      ans += (*high - *low - 1);
      printf("%lld ", ans);
      continue;
    }
    if (i == n) {
      cout << 1 << " ";
      continue;
    }
    if (high == s.end()) {
      low--;
      ans -= (x - *low - 1);
      printf("%lld ", ans);
      continue;
    }
  }
  cout << endl;
}
