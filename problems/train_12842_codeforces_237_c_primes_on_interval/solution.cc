#include <bits/stdc++.h>
using namespace std;
const int M = 1e6 + 5;
int a, b, k, t, p[M], mark[M], sum[M];
void init() {
  int N = 1e6;
  for (int i = 2; i <= N; i++) {
    if (mark[i] == 0) p[++t] = i;
    for (int j = 1; p[j] * i <= N; j++) {
      mark[p[j] * i] = 1;
      if (i % p[j] == 0) break;
    }
  }
  for (int i = 2; i <= N; i++) {
    sum[i] = sum[i - 1];
    if (mark[i] == 0) sum[i]++;
  }
}
int judge(int x) {
  for (int i = a; i <= b - x + 1; i++) {
    int j = i + x - 1;
    if (sum[j] - sum[i - 1] < k) return 0;
  }
  return 1;
}
int main() {
  init();
  scanf("%d%d%d", &a, &b, &k);
  int le = 1, ri = b - a + 1, ans = -1;
  while (le <= ri) {
    int mid = le + ri >> 1;
    if (judge(mid)) {
      ans = mid;
      ri = mid - 1;
    } else
      le = mid + 1;
  }
  printf("%d", ans);
  return 0;
}
