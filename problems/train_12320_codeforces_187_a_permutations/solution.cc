#include <bits/stdc++.h>
using namespace std;
const int MAXN = 200 * 1000 + 100;
int n, a[MAXN], b[MAXN], p[MAXN], x;
int main() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    p[a[i]] = i;
  }
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < n; ++i) a[p[b[i]]] = i;
  x = 1;
  while (x < n && a[x] > a[x - 1]) x++;
  cout << n - x << endl;
  return 0;
}
