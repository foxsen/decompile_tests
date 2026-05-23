#include <bits/stdc++.h>
using namespace std;
const int MAXN = 3 * 1e5 + 10;
int max(int a, int b) {
  if (a > b) return a;
  return b;
}
int min(int a, int b) {
  if (a < b) return a;
  return b;
}
int a[MAXN] = {0};
int b[MAXN] = {0};
int c[MAXN] = {0};
int main() {
  int n;
  cin >> n;
  int maxi = 0;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    maxi = max(maxi, a[i]);
  }
  for (int i = 2; i < n; ++i) b[i] = min(max(a[i - 1], a[i + 1]), a[i]);
  for (int i = 1; i < n; ++i) c[i] = max(a[i], a[i + 1]);
  int solb = 0;
  int solc = 0;
  for (int k = 0; k < n - 1; ++k) {
    if ((n - k) % 2 == 1) {
      solb = max(solb, max(b[(1 + n - k) / 2], b[(k + 1 + n) / 2]));
      cout << solb << " ";
    } else {
      solc = max(solc, max(c[(1 + n - k) / 2], c[(k + 1 + n) / 2]));
      cout << solc << " ";
    }
  }
  cout << maxi << endl;
  return 0;
}
