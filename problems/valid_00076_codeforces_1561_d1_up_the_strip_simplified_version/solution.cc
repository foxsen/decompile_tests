#include <bits/stdc++.h>
using namespace std;
long long int m;
void solve() {
  int n, i, j;
  cin >> n >> m;
  long long int sum = 0, t[2 * n + 2], val, pref = 0;
  for (i = n + 1; i < 2 * n + 2; i++) {
    t[i] = (i - n) % 2;
  }
  t[n + 1] = 0;
  t[n + 2] = 2;
  for (i = n; i >= 1; i--) {
    t[i] = t[2 * i] + t[2 * i + 1];
  }
  for (i = 2; i <= n; i++) {
    t[i + n] += sum;
    t[i + n + 1] -= sum;
    pref += t[i + n];
    val = pref;
    for (j = 2; j <= n / i; j++) {
      t[j * i + n] += val;
      t[min(j * i + n + j, 2 * n + 1)] -= val;
    }
    sum += pref;
    sum %= m;
  }
  cout << (pref % m + m) % m;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int tc = 1;
  while (tc--) {
    solve();
  }
  return 0;
}
