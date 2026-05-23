#include <bits/stdc++.h>
using namespace std;
const int maxn = 3000 + 10;
int n;
struct Tside {
  int x, y, v;
  int num;
  Tside *next;
} * h[maxn];
int f[maxn], floors[maxn];
int res = 1000000, res1, res2;
int tx, ty, tv;
void swap(int &a, int &b) {
  int tmp = a;
  a = b;
  b = tmp;
}
void ins(int x, int y, int num) {
  Tside *tmp = h[x];
  h[x] = new (Tside);
  h[x]->x = x;
  h[x]->y = y;
  h[x]->v = 0;
  h[x]->num = num;
  h[x]->next = tmp;
  tmp = h[y];
  h[y] = new (Tside);
  h[y]->x = y;
  h[y]->y = x;
  h[y]->v = 1;
  h[y]->num = num;
  h[y]->next = tmp;
}
void dfs1(int s, int fa) {
  floors[s] = floors[fa] + 1;
  f[s] = 0;
  Tside *tmp;
  tmp = h[s];
  while (tmp != NULL) {
    if (tmp->y != fa) {
      dfs1(tmp->y, s);
      f[s] += f[tmp->y] + tmp->v;
    }
    tmp = tmp->next;
  }
}
void dfs2(int s, int fa, int num, int ans) {
  Tside *tmp = h[s];
  if (num == 0) {
    if (ans < res2) res2 = ans;
  } else {
    if (ans < res1) res1 = ans;
  }
  int tmp_ans;
  while (tmp != NULL) {
    if (tmp->y != fa && tmp->num != num) {
      if (tmp->v == 1)
        tmp_ans = ans - 1;
      else
        tmp_ans = ans + 1;
      dfs2(tmp->y, s, num, tmp_ans);
    }
    tmp = tmp->next;
  }
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) h[i] = NULL;
  for (int i = 1; i < n; i++) {
    cin >> tx >> ty;
    ins(tx, ty, i);
  }
  floors[0] = 0;
  dfs1(1, 0);
  Tside *tmp;
  for (int i = 1; i <= n; i++) {
    tmp = h[i];
    while (tmp != NULL) {
      tx = tmp->x;
      ty = tmp->y;
      tv = tmp->v;
      if (floors[tx] > floors[ty]) {
        swap(tx, ty);
        tv = 1 - tv;
      }
      res1 = f[1] - f[ty] - tv;
      dfs2(1, 0, tmp->num, res1);
      res2 = f[ty];
      dfs2(ty, tx, 0, res2);
      if (res > res1 + res2) res = res1 + res2;
      tmp = tmp->next;
    }
  }
  if (res == 1000000) res = 0;
  cout << res << endl;
  return 0;
}
