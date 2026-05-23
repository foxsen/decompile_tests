#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, a[1000 + 20] = {}, x, y = 0;
  bool ans = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    y = max(x, y);
    a[x - 1]++;
  }
  for (int i = 0; i < (y - 2); i++) {
    if (a[i] && a[i + 1] && a[i + 2]) {
      ans = 1;
      break;
    }
  }
  if (ans)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
  return 0;
}
