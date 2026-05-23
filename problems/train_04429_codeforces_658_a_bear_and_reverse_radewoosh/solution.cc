#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  int n, c;
  cin >> n >> c;
  int p[n], t[n], a[n], b[n];
  for (int i = 0; i < n; i++) cin >> p[i];
  for (int i = 0; i < n; i++) cin >> t[i];
  a[0] = t[0];
  for (int i = 1; i < n; i++) a[i] = t[i] + a[i - 1];
  a[0] = max(0, p[0] - (c * a[0]));
  for (int i = 1; i < n; i++) a[i] = max(0, p[i] - (c * a[i]));
  b[n - 1] = t[n - 1];
  for (int i = n - 2; i >= 0; i--) b[i] = t[i] + b[i + 1];
  b[n - 1] = max(0, p[n - 1] - (c * b[n - 1]));
  for (int i = n - 2; i >= 0; i--) b[i] = max(0, p[i] - (c * b[i]));
  int l = 0, r = 0;
  for (int i = 0; i < n; i++) {
    l += a[i];
    r += b[i];
  }
  if (l == r) cout << "Tie";
  if (l > r) cout << "Limak";
  if (l < r) cout << "Radewoosh";
  return 0;
}
