#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a1, a2;
  cin >> a1 >> a2;
  int res = 0;
  while (a1 && a2 && (a1 > 1 || a2 > 1)) {
    if (a1 > a2) swap(a1, a2);
    ++a1;
    a2 -= 2;
    ++res;
  }
  cout << res << '\n';
  return 0;
}
