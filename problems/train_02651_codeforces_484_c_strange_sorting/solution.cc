#include <bits/stdc++.h>
using namespace std;
char s[1000005], t[1000005];
int n, k, d;
int P[1000005], Ans[1000005], G[1000005];
void solve() {
  scanf("%d %d", &k, &d);
  for (int i = 0; i < n; ++i) P[i] = Ans[i] = i;
  int u = 0;
  for (int i = 0; i < d; ++i)
    for (int j = i; j < k; j += d) P[u++] = j;
  P[n] = P[0];
  for (int i = 0; i <= n - 1; ++i) P[i] = P[i + 1];
  int m = n - k + 1;
  while (m > 0) {
    if (m % 2) {
      for (int i = 0; i < n; ++i) Ans[i] = P[Ans[i]];
    }
    for (int i = 0; i < n; ++i) G[i] = P[i];
    for (int i = 0; i < n; ++i) P[i] = G[P[i]];
    m /= 2;
  }
  for (int i = 0; i < n; ++i) t[(i + n - k + 1) % n] = s[Ans[i]];
  for (int i = 0; i < n; ++i) s[i] = t[i];
  printf("%s\n", s);
}
int main() {
  scanf("%s", s);
  n = strlen(s);
  int Q;
  scanf("%d", &Q);
  while (Q--) solve();
}
