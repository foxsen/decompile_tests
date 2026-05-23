#include <bits/stdc++.h>
using namespace std;
char s[1505][1505];
int f[1505][1505];
struct node {
  int x, y;
} st, vis[1505][1505];
int xx[4] = {0, 0, 1, -1};
int yy[4] = {1, -1, 0, 0};
int n, m;
int bfs() {
  node c;
  f[st.x][st.y] = 1;
  vis[st.x][st.y].x = st.x;
  vis[st.x][st.y].y = st.y;
  queue<node> q;
  q.push(st);
  while (!q.empty()) {
    node d = q.front();
    q.pop();
    for (int i = 0; i < 4; i++) {
      int x = d.x + xx[i];
      int y = d.y + yy[i];
      node cc;
      cc.x = x;
      cc.y = y;
      c.x = (x % n + n) % n;
      c.y = (y % m + m) % m;
      if (s[c.x][c.y] == '#') continue;
      if (!f[c.x][c.y]) {
        f[c.x][c.y] = 1;
        q.push(cc);
        vis[c.x][c.y].x = x;
        vis[c.x][c.y].y = y;
      } else {
        if ((vis[c.x][c.y].x != x) || (vis[c.x][c.y].y != y)) {
          return 1;
        }
      }
    }
  }
  return 0;
}
int main() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
    for (int j = 0; j < m; j++) {
      if (s[i][j] == 'S') {
        st.x = i;
        st.y = j;
        s[i][j] = '.';
      }
    }
  }
  if (bfs()) {
    puts("Yes");
  } else {
    puts("No");
  }
  return 0;
}
