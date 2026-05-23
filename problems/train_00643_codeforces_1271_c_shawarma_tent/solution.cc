#include <bits/stdc++.h>
using namespace std;
long long int xpow(long long int a, long long int b) {
  if (b == 0) return 1;
  if (b % 2 == 0) {
    long long int k = xpow(a, b / 2);
    return k * k;
  }
  if (b % 2 != 0) return a * xpow(a, b - 1);
}
int main() {
  ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
  int n, sx, sy;
  cin >> n >> sx >> sy;
  int l = 0, r = 0, d = 0, u = 0;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x > sx) r++;
    if (x < sx) l++;
    if (y > sy) u++;
    if (y < sy) d++;
  }
  int maxi = max({l, r, d, u});
  cout << maxi << endl;
  if (l == maxi)
    sx--;
  else if (r == maxi)
    sx++;
  else if (u == maxi)
    sy++;
  else if (d == maxi)
    sy--;
  cout << sx << " " << sy << endl;
  return 0;
}
