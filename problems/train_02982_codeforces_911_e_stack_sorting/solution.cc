#include <bits/stdc++.h>
using pii = std::pair<int, int>;
using pll = std::pair<long long, long long>;
const int maxn = 2e5 + 100;
int a[maxn];
int i = 0;
void cons(int l, int r) {
  if (r < l) return;
  if (a[i] > 0) {
    if (a[i] < l || a[i] > r) {
      std::cout << -1 << std::endl;
      std::exit(0);
    }
    int x = a[i];
    ++i;
    cons(l, x - 1);
    cons(x + 1, r);
  } else {
    for (; r >= l; r--, i++) a[i] = r;
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  int n, k;
  std::cin >> n >> k;
  for (int i = 0; i < k; i++) std::cin >> a[i];
  cons(1, n);
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << " ";
  }
  std::cout << std::endl;
  return 0;
}
