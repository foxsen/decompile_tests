#include <bits/stdc++.h>
using namespace std;
int ans = 0, n;
int numDistDig(int n) {
  vector<int> arr(10, 0);
  while (n > 0) {
    arr[n % 10]++;
    n /= 10;
  }
  int ans = 0, i;
  for (i = 0; i < 10; i++) ans += (arr[i] > 0);
  return ans;
}
void dfs(int num) {
  if (num > 0 && num <= n) ans++;
  if (ans >= 100000000) return;
  int i;
  for (i = 0; i < 10; i++) {
    int num2 = num * 10 + i;
    if (num2 > 0 && numDistDig(num2) <= 2) dfs(num2);
  }
}
int main() {
  scanf("%d", &n);
  dfs(0);
  printf("%d\n", ans);
}
