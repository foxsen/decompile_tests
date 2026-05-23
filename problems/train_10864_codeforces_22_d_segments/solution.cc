#include <bits/stdc++.h>
using namespace std;
int n, p, cnt, r[1010];
pair<int, int> c[1010];
bool check[1010];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> c[i].second >> c[i].first;
    if (c[i].second > c[i].first) swap(c[i].second, c[i].first);
  }
  sort(c, c + n);
  while (1) {
    int i = 0;
    for (i = 0; i < n; i++)
      if (!check[i]) break;
    if (i == n) break;
    r[cnt] = c[i].first;
    for (i = 0; i < n; i++)
      if (c[i].first >= r[cnt] && c[i].second <= r[cnt]) check[i] = true;
    cnt++;
  }
  cout << cnt << endl;
  for (int i = 0; i < cnt; i++) cout << r[i] << " ";
  cout << endl;
  return 0;
}
