#include <bits/stdc++.h>
using namespace std;
#pragma comment(linker, "/STACK:64000000")
int n, m, t, y, j, l, i, h, q, q1, q2, p1, p2, k, a1[5], a2[5];
bool b1, b2;
inline void solve() {
  for (j = 1; j <= 4; j++) {
    scanf("%d%d", &a1[j], &a2[j]);
  }
  if ((a2[1] > a1[3] && a1[2] > a2[4] && a2[1] > a1[4] && a1[2] > a2[3]) ||
      (a2[2] > a1[3] && a1[1] > a2[4] && a2[2] > a1[4] && a1[1] > a2[3])) {
    b1 = 1;
  }
  if (((a1[2] < a2[4] && a2[1] < a1[3]) || (a1[2] < a2[3] && a2[1] < a1[4])) &&
      ((a1[1] < a2[4] && a2[2] < a1[3]) || (a1[1] < a2[3] && a2[2] < a1[4]))) {
    b2 = 1;
  }
  if (b1) {
    printf("Team 1\n");
  }
  if (b2) {
    printf("Team 2\n");
  }
  if (!b1 && !b2) {
    printf("Draw\n");
  }
}
inline void init() {}
inline void answer() {}
int main() {
  init();
  solve();
  answer();
  return 0;
}
