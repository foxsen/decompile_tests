#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000005;
struct node {
  int x, y;
} data[maxn];
int pos[maxn], dp[maxn], n;
int getmax(int a, int b) { return a > b ? a : b; }
bool cmp(node a, node b) { return a.x < b.x; }
void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &data[i].x);
  for (int i = 0; i < n; i++) scanf("%d", &data[i].y);
}
void work() {
  for (int i = 0; i < n; i++) pos[data[i].y] = i + 1;
  for (int i = 0; i < n; i++) data[i].y = pos[data[i].x];
  int ans = 1;
  dp[1] = data[0].y;
  for (int i = 1; i < n; i++) {
    int ts, te, lower = 1, upper = ans, ret = 0;
    while (lower <= upper) {
      int mid = (lower + upper) >> 1;
      if (dp[mid] > data[i].y) {
        ret = mid;
        lower = mid + 1;
      } else
        upper = mid - 1;
    }
    ret++;
    dp[ret] = getmax(dp[ret], data[i].y);
    ans = getmax(ans, ret);
  }
  printf("%d\n", ans);
}
int main() {
  init();
  work();
  return 0;
}
