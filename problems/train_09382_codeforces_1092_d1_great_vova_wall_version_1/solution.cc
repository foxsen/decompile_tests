#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; ++i) cin >> a[i];
  int m = *max_element(a, a + n);
  for (int i = 0; i < n; ++i) {
    if ((m - a[i]) % 2)
      a[i] = m + 1;
    else
      a[i] = m;
  }
  stack<int> d;
  for (int i = 0; i < n; ++i) {
    if (d.empty())
      d.push(a[i]);
    else {
      if (d.top() == a[i])
        d.pop();
      else
        d.push(a[i]);
    }
  }
  set<int> s;
  while (!d.empty()) {
    s.insert(d.top());
    d.pop();
  }
  s.size() <= 1 ? cout << "YES\n" : cout << "NO\n";
  return 0;
}
