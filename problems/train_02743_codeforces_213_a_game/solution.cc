#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3fffffff;
int N, home[300], gind[300];
vector<int> gra[220];
int solve(int);
int main() {
  int i, j, k, x, y;
  scanf("%d", &N);
  for (i = 1; i <= N; ++i) {
    scanf("%d", &home[i]);
    home[i]--;
  }
  for (i = 1; i <= N; ++i) {
    scanf("%d", &k);
    for (j = 0; j < k; ++j) {
      scanf("%d", &y);
      gra[y].push_back(i);
      gind[i]++;
    }
  }
  int ans = INF;
  for (i = 0; i < 3; ++i) {
    int tmp = solve(i);
    if (tmp < ans) ans = tmp;
  }
  printf("%d\n", ans);
  return 0;
}
int solve(int s) {
  int ind[300], i, j, k, cnt = N, sameroom, res = 0;
  bool used[300];
  memset(used, 0, sizeof(used));
  for (i = 0; i < 220; ++i) ind[i] = gind[i];
  while (cnt > 0) {
    sameroom = 0;
    for (i = 1; i <= N; ++i) {
      if (!used[i] && home[i] == s && ind[i] == 0) {
        for (j = 0; j < gra[i].size(); ++j) --ind[gra[i][j]];
        used[i] = true;
        --cnt;
        ++sameroom;
      }
    }
    if (sameroom == 0) {
      s = (s + 1) % 3;
      res++;
    }
  }
  return res + N;
}
