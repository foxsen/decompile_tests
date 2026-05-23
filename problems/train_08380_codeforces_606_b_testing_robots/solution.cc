#include <bits/stdc++.h>
using namespace std;
char ins[123456];
int n = 0;
bool vis[501][501];
int h, w, y, x;
void step(int i) {
  if (ins[i] == 'L') x = max(x - 1, 0);
  if (ins[i] == 'R') x = min(x + 1, w - 1);
  if (ins[i] == 'U') y = max(y - 1, 0);
  if (ins[i] == 'D') y = min(y + 1, h - 1);
}
int main() {
  scanf("%d%d%d%d ", &h, &w, &y, &x);
  x--;
  y--;
  scanf(" %s ", ins);
  while (ins[n] > 0) n++;
  for (int i = 0; i < w; i++)
    for (int j = 0; j < h; j++) vis[i][j] = false;
  vector<int> ret;
  int i = 0;
  do {
    ret.push_back(vis[x][y] ? 0 : 1);
    vis[x][y] = true;
    if (i < n) step(i);
  } while (++i <= n);
  int sm = 0;
  for (int i = 0; i < n; i++) {
    sm += ret[i];
    printf("%d ", ret[i]);
  }
  printf("%d\n", w * h - sm);
  return 0;
}
