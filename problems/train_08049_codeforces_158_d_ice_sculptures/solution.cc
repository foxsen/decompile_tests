#include <bits/stdc++.h>
int count(int);
int n, deg[1000000];
int main(void) {
  int i, maxsum = -1000000000;
  scanf("%d\n", &n);
  for (i = 0; i < n; i++) scanf("%d", &deg[i]);
  for (i = 1; i * 3 <= n; i++) {
    if (n % i) continue;
    maxsum = (maxsum > count(i)) ? maxsum : count(i);
  }
  printf("%d\n", maxsum);
  return 0;
}
int count(int numSides) {
  int sum[numSides], i;
  for (i = 0; i < numSides; i++) sum[i] = 0;
  for (i = 0; i < n; i++) sum[i % numSides] += deg[i];
  int ms = -1000000000;
  for (i = 0; i < numSides; i++) ms = (ms > sum[i]) ? ms : sum[i];
  return ms;
}
