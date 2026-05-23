#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
int n;
set<int> s;
inline void init() {
  int x = 1, y = 1;
  s.insert(1);
  for (int z = 2; z <= 1000; z = x + y) {
    s.insert(z);
    x = y, y = z;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  init();
  cin >> n;
  for (int i = 1; i <= n; ++i)
    if (s.find(i) != s.end())
      cout << 'O';
    else
      cout << 'o';
  return 0;
}
