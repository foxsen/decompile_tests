#include <bits/stdc++.h>
int a[100000];
int c[100001];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::set<int> unused;
  for (int i = 0; i < n; ++i) {
    unused.insert(i + 1);
  }
  for (int i = 0; i < n; ++i) {
    std::cin >> a[i];
    if (a[i] <= n) {
      c[a[i]]++;
      if (c[a[i]] == 1) {
        unused.erase(unused.find(a[i]));
      } else {
        a[i] = 0;
      }
    } else {
      a[i] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      a[i] = *unused.begin();
      unused.erase(unused.begin());
    }
  }
  for (int i = 0; i < n; ++i) {
    std::cout << a[i] << ' ';
  }
  return 0;
}
