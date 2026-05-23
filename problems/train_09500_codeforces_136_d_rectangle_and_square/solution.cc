#include <bits/stdc++.h>
using namespace std;
struct pnt {
  int x, y;
} p[10];
int h[10];
int s1[10];
int s2[10];
bool fnd;
int dist2(pnt a, pnt b) {
  return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
bool squ(pnt a, pnt b, pnt c, pnt d) {
  int dab = dist2(a, b);
  int dbc = dist2(b, c);
  if (dbc != dab) return false;
  int dcd = dist2(c, d);
  if (dcd != dab) return false;
  int dda = dist2(d, a);
  if (dda != dab) return false;
  int dac = dist2(a, c);
  if (dac != dab * 2) return false;
  int dbd = dist2(b, d);
  if (dbd != dab * 2) return false;
  return true;
}
bool square() {
  pnt a = p[s1[0]];
  pnt b = p[s1[1]];
  pnt c = p[s1[2]];
  pnt d = p[s1[3]];
  if (squ(a, b, c, d)) return true;
  if (squ(a, b, d, c)) return true;
  if (squ(a, c, b, d)) return true;
  if (squ(a, c, d, b)) return true;
  if (squ(a, d, b, c)) return true;
  if (squ(a, d, c, b)) return true;
  return false;
}
bool rec(pnt a, pnt b, pnt c, pnt d) {
  int dab = dist2(a, b);
  int dbc = dist2(b, c);
  int dcd = dist2(c, d);
  if (dcd != dab) return false;
  int dda = dist2(d, a);
  if (dda != dbc) return false;
  int dac = dist2(a, c);
  int dbd = dist2(b, d);
  if (dac != dbd) return false;
  return true;
}
bool rect() {
  pnt a = p[s2[0]];
  pnt b = p[s2[1]];
  pnt c = p[s2[2]];
  pnt d = p[s2[3]];
  if (rec(a, b, c, d)) return true;
  if (rec(a, b, d, c)) return true;
  if (rec(a, c, b, d)) return true;
  if (rec(a, c, d, b)) return true;
  if (rec(a, d, b, c)) return true;
  if (rec(a, d, c, b)) return true;
  return false;
}
void dfs(int x, int y, int z) {
  if (fnd) return;
  if (x == 8) {
    if (square() && rect()) {
      printf("YES\n");
      int i, j;
      j = 0;
      for (i = 0; i < 8; i++) {
        if (h[i] == 0) {
          if (j) printf(" ");
          printf("%d", i + 1);
          j++;
        }
      }
      printf("\n");
      j = 0;
      for (i = 0; i < 8; i++) {
        if (h[i] == 1) {
          if (j) printf(" ");
          printf("%d", i + 1);
          j++;
        }
      }
      printf("\n");
      fnd = true;
    }
    return;
  }
  if (y < 4) {
    h[x] = 0;
    s1[y] = x;
    dfs(x + 1, y + 1, z);
  }
  if (z < 4) {
    h[x] = 1;
    s2[z] = x;
    dfs(x + 1, y, z + 1);
  }
}
int main() {
  int i;
  for (i = 0; i < 8; i++) scanf("%d%d", &p[i].x, &p[i].y);
  fnd = false;
  dfs(0, 0, 0);
  if (!fnd) printf("NO\n");
  return 0;
}
