#include <bits/stdc++.h>
using namespace std;
char S[1000010], S1[1000010];
int n, m, k, d;
int f1, f2;
bool can[1000010];
int root[1000010][21];
void calc(int x0, int st, int times) {
  int i = 0, sum = 0, u = st;
  while (1 << (i + 1) <= times) i++;
  while (i >= 0) {
    if (times & (1 << i)) {
      if (root[u][i] == -1) {
        i--;
        while (i >= 0) {
          if (root[u][i] != -1) {
            u = root[u][i];
            sum += 1 << i;
          }
          i--;
        }
        S1[x0 - st + sum] = S[x0];
        return;
      } else {
        u = root[u][i];
        sum += 1 << i;
      }
    }
    i--;
  }
  S1[x0 - st + times + u] = S[x0];
}
int main() {
  scanf("%s%d", S, &m);
  n = strlen(S);
  for (int i = 1; i <= m; i++) {
    scanf("%d%d", &k, &d);
    f1 = (k - 1) / d;
    f2 = (k - 1) % d + 1;
    for (int i = 0; i < k; i++) can[i] = 1;
    for (int i = 0; i < k; i++)
      if (can[i])
        for (int j = i, l; j != -1 && can[j]; j = l) {
          root[j][0] = l = (j % d) * f1 + min(j % d, f2) + (j / d) - 1;
          can[j] = 0;
        }
    for (int i = 1, j = 2; j <= n - k + 1; i++, j <<= 1)
      for (int l = 0; l < k; l++)
        root[l][i] = (root[l][i - 1] == -1) ? -1 : root[root[l][i - 1]][i - 1];
    for (int i = 0; i < k; i++) calc(i, i, n - k + 1);
    for (int i = k; i < n; i++) calc(i, k - 1, n - i);
    for (int i = 0; i < n; i++) printf("%c", S1[i]);
    printf("\n");
    for (int i = 0; i < n; i++) S[i] = S1[i];
  }
  return 0;
}
