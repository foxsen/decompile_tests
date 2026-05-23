#include <bits/stdc++.h>
using namespace std;
int n, m;
int data[2][100010], t[100010], num[100010];
queue<pair<int, int> > que;
int dis(int x, int y) { return abs(data[0][x] - data[1][y]); }
int main() {
  scanf("%d%d%*d%*d", &n, &m);
  for (int i = 0; i < n; i++) scanf("%d", &data[0][i]);
  for (int i = 0; i < m; i++) scanf("%d", &data[1][i]);
  for (int i = 0; i < m; i++) t[i] = 0x7fffffff;
  int j = 0;
  for (int i = 0; i < n; i++) {
    while (j + 1 < m && dis(i, j + 1) < dis(i, j)) j++;
    if (j + 1 < m && dis(i, j) == dis(i, j + 1)) {
      que.push(make_pair(i, j));
      continue;
    }
    int k = j;
    if (j + 1 < m && dis(i, j + 1) < dis(i, j)) k++;
    if (t[k] > dis(i, k)) num[k] = 0, t[k] = dis(i, k);
    if (t[k] == dis(i, k)) num[k]++;
  }
  while (!que.empty()) {
    int i = que.front().first, j = que.front().second;
    que.pop();
    if (dis(i, j) == t[j] || t[j] == 0x7fffffff)
      num[j]++, t[j] = dis(i, j);
    else if (dis(i, j + 1) == t[j + 1] || t[j + 1] == 0x7fffffff)
      num[j + 1]++, t[j + 1] = dis(i, j + 1);
  }
  int ans = n;
  for (int i = 0; i < m; i++) ans -= num[i];
  printf("%d\n", ans);
}
