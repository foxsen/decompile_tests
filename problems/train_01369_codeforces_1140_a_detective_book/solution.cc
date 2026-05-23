#include <bits/stdc++.h>
using namespace std;
int n, ans;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (register int i = 1, tmp, stop = 0; i <= n; ++i) {
    cin >> tmp;
    stop = max(stop, tmp);
    if (stop == i) {
      ++ans;
    }
  }
  printf("%d", ans);
  return 0;
}
