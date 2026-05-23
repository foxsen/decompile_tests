#include <bits/stdc++.h>
using namespace std;
int b[102];
int g[102];
int main() {
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  cin >> m;
  for (int i = 0; i < m; i++) {
    cin >> g[i];
  }
  sort(b, b + n);
  sort(g, g + m);
  int itb, itg;
  itb = itg = 0;
  int cnt = 0;
  while (itb < n && itg < m) {
    if (abs(b[itb] - g[itg]) <= 1) {
      cnt++, itb++, itg++;
      continue;
    }
    if (b[itb] < g[itg])
      itb++;
    else
      itg++;
  }
  cout << cnt;
  return 0;
}
