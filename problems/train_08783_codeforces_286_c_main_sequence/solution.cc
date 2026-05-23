#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int M = 1000010;
const int mod = 1e9;
const double eps = 1e-8;
const double Pi = 2 * acos(0.0);
int n, p[M], t, tmp, stk[M];
bool q[M];
int main() {
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i];
  }
  cin >> t;
  for (int i = 1; i <= t; i++) {
    cin >> tmp;
    q[tmp] = 1;
  }
  t = -1;
  for (int i = n; i; i--) {
    if (q[i] || p[i] != stk[t]) {
      stk[++t] = p[i];
      p[i] = -p[i];
    } else
      t--;
  }
  if (t == -1) {
    cout << "YES" << endl;
    for (int i = 1; i <= n; i++) {
      cout << p[i] << ' ';
    }
  } else
    cout << "NO" << endl;
  return 0;
}
