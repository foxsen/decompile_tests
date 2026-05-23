#include <bits/stdc++.h>
using namespace std;
int v[401][401], d[401];
int main() {
  int n, m;
  cin >> n >> m;
  while (m--) {
    int x, y;
    cin >> x >> y;
    v[x][y] = v[y][x] = 1;
  }
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int x = q.front();
    q.pop();
    for (int i = 2; i <= n; i++)
      if (!d[i] && v[x][i] != v[1][n]) q.push(i), d[i] = d[x] + 1;
  }
  if (d[n])
    cout << d[n] << endl;
  else
    cout << "-1\n";
  return 0;
}
