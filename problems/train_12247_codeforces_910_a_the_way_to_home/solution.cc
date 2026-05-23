#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, d, val, ind = 0, counter = 0, ans = 0;
  cin >> n >> d;
  string v;
  cin >> v;
  while (ind <= n - 1) {
    counter++;
    ans = 0;
    for (int i = d; i >= 1; i--) {
      if (v[ind + i] == '1') {
        ind += i;
        ans = 1;
        break;
      }
    }
    if (!ans) break;
    if (ind == n - 1) {
      ans = 1;
      break;
    }
  }
  if (ans)
    cout << counter << endl;
  else
    cout << -1 << endl;
  return 0;
}
